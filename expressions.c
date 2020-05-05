/*
	Rewrite code at every place where goto, labels, trueP, falseP, true_name, false_name have been used
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool arr_present(char* arr, int len, int elem)
{
	for(int i = 0; i < len; i++) 
		if (arr[i] == elem) return true;
	return false;
}


char* get_new_label()
{
	static int label_cnt = 0;
	char* label = malloc(sizeof(char) * 4);
	sprintf(label, "L%d", label_cnt);
	label_cnt++;
	return label;
}

char* get_new_var()
{
	static int var_cnt = 0;
	char* var = malloc(sizeof(char) * 4);
	sprintf(var, "t%d", var_cnt);
	var_cnt++;
	return var;
}

//-----------------------------------------------------------------------------------------------------------

struct code
{
	char* op;
	char* arg1;
	char* arg2;
	char* result;
	struct code* next;

	/*
		if x < y goto L  ...........  translates to 
		(<, x, y, L) 
		Label L4: ...... (label, NULL, NULL, L4)
		goto L  ......  (goto, NULL, NULL, L)
	*/
};

struct code* code_new(char* op, char* arg1, char* arg2, char* result)
{
	struct code* codeP = malloc(sizeof(struct code));
	codeP->next = NULL;
	
	codeP->op = malloc(sizeof(op));
	codeP->op[0] = '\0';
	strcat(codeP->op, op);

	codeP->arg1 = malloc(sizeof(arg1));
	codeP->arg1[0] = '\0';
	strcat(codeP->arg1, arg1);

	codeP->arg2 = malloc(sizeof(arg2));
	codeP->arg2[0] = '\0';
	strcat(codeP->arg2, arg2);

	codeP->result = malloc(sizeof(result));
	codeP->result[0] = '\0';
	strcat(codeP->result, result);

	return codeP;
}

//-----------------------------------------------------------------------------------------------------------

struct code_list // Stores list of codes which should have the same jump value
{
	struct code* code;
	struct code_list* next;
};

struct code_list* code_list_new(struct code* code)
{
	struct code_list* list = malloc(sizeof(struct code_list));
	list->code = code;
	list->next = NULL;
	return list;
}

void code_list_add_elem(struct code_list* list, struct code* code)
{
	while(list->next != NULL) list = list->next;
	list->next = code_list_new(code);
}

void code_list_join(struct code_list* list1, struct code_list* list2)
{
	while(list1->next != NULL) list1 = list1->next;
	list1->next = list2;
}

void code_list_backpatch(struct code_list* list, char* jump_label)
{
	while(list != NULL)
	{
		list->code->result = malloc(sizeof(jump_label));
		strcpy(list->code->result, jump_label);
		list = list->next;
	}
}

//-----------------------------------------------------------------------------------------------------------

struct codeP_list // Stores list of code pointers which should point to the same code 
{
	struct code** codeP;
	struct codeP_list* next;
};

struct codeP_list* codeP_list_new(struct code** codeP)
{
	struct codeP_list* list = malloc(sizeof(struct codeP_list));
	list->codeP = codeP;
	list->next = NULL;
	return list;
}

void codeP_list_add_elem(struct codeP_list* list, struct code** codeP)
{
	while(list->next != NULL) list = list->next;
	list->next = codeP_list_new(codeP);
}

void codeP_list_join(struct codeP_list* list1, struct codeP_list* list2)
{
	while(list1->next != NULL) list1 = list1->next;
	list1->next = list2;
}

void codeP_list_backpatch(struct codeP_list* list, struct code* jump_loc)
{
	while(list != NULL)
	{
		*(list->codeP) = jump_loc;
		list = list->next;
	}
}


//---------------------------------------------------------------------------------------------------------

struct exprn
{
	int type; // 0->int, 1->float, 2->bool
	struct code* codeP;
	struct code_list* true_jump_lines; // NULL for ints / floats
	struct code_list* false_jump_lines; // NULL for ints / floats
	struct codeP_list* true_jumpPs; // NULL for ints / floats
	struct codeP_list* false_jumpPs; // NULL for ints / floats

	struct code* true_jump; // NULL for ints / floats
	struct code* false_jump; // NULL for ints / floats
	struct code* last_line_P;

	char* store_var; // NULL for bools

	// For ints / floats, last line will be an assignment of store_var
};

int upcast(int a, int b)
{
	if (a == b) return a;
	
	int dual = a * 10 + b;
	if (dual == 01 || dual == 10) return 1;
	else if (dual == 12 || dual == 21) return 1;
	else return 0;
}

void exprn_type_cast(struct exprn* exprn, int type)
{
	if (exprn->type == type) return;

	int duo_type = exprn->type * 10 + type;
	
	if (duo_type == 01 || duo_type == 10) // int <-> float 
	{
		char* var = get_new_var();
		if (duo_type == 01)
			struct code* new_code = code_new("(float)", exprn->store_var, NULL, var);
		else
			struct code* new_code = code_new("(int)", exprn->store_var, NULL, var);
		exprn->last_line_P->next = new_code;
		exprn->last_line_P = new_code;
		exprn->store_var = var;
	}
	else if (duo_type == 20 || duo_type == 21) // bool -> int / float
	{
		assert(exprn->true_jump == NULL);
		assert(exprn->false_jump == NULL);

		char* true_label = get_new_label();
		char* false_label = get_new_label();
		char* final_label = get_new_label();
		struct code* true_label_line = code_new("label", NULL, NULL, true_label);
		struct code* false_label_line = code_new("label", NULL, NULL, false_label);
		struct code* final_label_line = code_new("label", NULL, NULL, final_label);

		char* temp_var = get_new_var();
		if (duo_type == 20)
		{
			struct code* new_true_code = code_new("assign", "1", NULL, temp_var);
			struct code* new_false_code = code_new("assign", "0", NULL, temp_var);
		}
		else
		{
			struct code* new_true_code = code_new("assign", "1.0", NULL, temp_var);
			struct code* new_false_code = code_new("assign", "0.0", NULL, temp_var);
		}

		char* var = get_new_var();
		struct code* new_code = code_new("assign", temp_var, NULL, var);
		struct code* jump_code = code_new("goto", NULL, NULL, final_label);

		// Insert new codes in between old codes
		struct code* saved_code = exprn->last_line_P->next;
		exprn->last_line_P->next = true_label_line;
		true_label_line->next = new_true_code;
		new_true_code->next = jump_code;
		jump_code->next = false_label_line;
		false_label_line->next = new_false_code;
		new_false_code->final_label_line;
		final_label_line->next = new_code;
		new_code->next = saved_code;

		code_list_backpatch(exprn->true_jump_lines, true_label);
		code_list_backpatch(exprn->false_jump_lines, false_label);
		codeP_list_backpatch(exprn->true_jumpPs, true_label_line);
		codeP_list_backpatch(exprn->false_jumpPs, false_label_line);
		
		exprn->true_jump = NULL;
		exprn->false_jump = NULL;
		exprn->last_line_P = new_code;
		exprn->store_var = var;
	}
	else // int / float -> bool
	{
		// Responsibility of correct assignment of true and false pointers relies on the caller 

		if (duo_type == 02)
			struct code* new_code1 = code_new("==", exprn->store_var, "0", NULL);
		else
			struct code* new_code1 = code_new("==", exprn->store_var, "0.0", NULL);

		struct code* new_code2 = code_new("goto", NULL, NULL, NULL);

		new_code1->next = new_code2;
		new_code2->next = exprn->last_line_P->next;
		exprn->last_line_P->next = new_code1;
		exprn->last_line_P = new_code2;

		exprn->true_jump_lines = code_list_new(new_code2);
		exprn->false_jump_lines = code_list_new(new_code1);
		exprn->true_jumpPs = codeP_list_new(&(exprn->true_jump));
		exprn->false_jumpPs = codeP_list_new(&(exprn->false_jump));

		exprn->true_jump = NULL
		exprn->false_jump = NULL;
		exprn->store_var = NULL;
	}

	exprn->type = type;
}

void exprn_operate(struct exprn* parent, struct exprn* lchild, struct exprn* rchild, int op)
{
	if (rchild == NULL)
	{
		if (op != NOT && op != LB)
		{
			printf("Missing one child in operation %d\n", op);
			exit(1);
		}

		/*
			Code ..............
		*/

		if (op == LB)
		{
			parent = lchild;
		}
		else // NOT
		{
			exprn_type_cast(lchild, 2);
			parent->type = 2;
			parent->codeP = lchild->codeP;
			parent->true_jump_lines = lchild->false_jump_lines;
			parent->false_jump_lines = lchild->true_jump_lines;
			parent->true_jumpPs = lchild->false_jumpPs;
			parent->false_jumpPs = lchild->true_jumpPs;
			codeP_list_add_elem(parent->true_jumpPs, &(parent->true_jump));
			codeP_list_add_elem(parent->false_jumpPs, &(parent->false_jump));
			parent->true_jump = NULL;
			parent->false_jump = NULL;
			parent->last_line_P = lchild->last_line_P;
			parent->store_var = NULL;
		}

		return;
	}

	int type1[] = [PLUS, MINUS, MUL, DIV]
	int type2[] = [MOD]
	int type3[] = [LESS, GREATER,LESS_EQUAL, GREATER_EQUAL, NOT_EQUAL, IS_EQUAL]
	int type4[] = [AND, OR, NOT]

	int present;
	if (arr_present(type1, 4, op)) present = 1;
	else if (arr_present(type2, 1, op)) present = 2;
	else if (arr_present(type3, 6, op)) present = 3;
	else present = 4;

	int cast = -1;
	if (present == 1) cast = upcast(upcast(lchild->op, rchild->op), 0);
	else if (present == 2) 
	{
		if (lchild->type == 1 || rchild->type == 1)
		{
			printf("Float data types cannot be used in modulus operation\n");
			exit(1);
		}
		cast = 0; 
	}
	else if (present == 3) cast = upcast(upcast(lchild->op, rchild->op), 0);
	else cast = 2;

	exprn_type_cast(lchild, cast);
	exprn_type_cast(rchild, cast);
	parent->type = cast;

	if (present == 1 || present == 2)
	{
		assert(lchild->last_line_P->next == NULL && rchild->last_line_P->next == NULL);
		
		lchild->last_line_P->next = rchild->codeP;
		parent->codeP = lchild->codeP;

		char* new_var = get_new_var();
		if (op == PLUS) struct code* new_code = code_new("PLUS", lchild->store_var, rchild->store_var, new_var);
		else if (op == MINUS) struct code* new_code = code_new("MINUS", lchild->store_var, rchild->store_var, new_var);
		else if (op == MINUS) struct code* new_code = code_new("MUL", lchild->store_var, rchild->store_var, new_var);
		else if (op == MINUS) struct code* new_code = code_new("DIVIDE", lchild->store_var, rchild->store_var, new_var);
		else struct code* new_code = code_new("MOD", lchild->store_var, rchild->store_var, new_var);
		
		rchild->last_line_P->next = new_code;
		parent->last_line_P = new_code;
		parent->store_var = new_var;

		parent->true_jump_lines = NULL;
		parent->false_jump_lines = NULL;
		parent->true_jumpPs = NULL;
		parent->false_jumpPs = NULL;
		parent->true_jump = NULL;
		parent->false_jump = NULL;
	}
	else if (present == 3)
	{
		assert(lchild->last_line_P->next == NULL && rchild->last_line_P->next == NULL);
		
		lchild->last_line_P->next = rchild->codeP;
		parent->codeP = lchild->codeP;

		if (op == LESS) struct code* new_code = code_new("<", lchild->store_var, rchild->store_var, NULL);
		else if (op == GREATER) struct code* new_code = code_new(">", lchild->store_var, rchild->store_var, NULL);
		else if (op == LESS_EQUAL) struct code* new_code = code_new("<=", lchild->store_var, rchild->store_var, NULL);
		else if (op == GREATER_EQUAL) struct code* new_code = code_new(">=", lchild->store_var, rchild->store_var, NULL);
		else if (op == NOT_EQUAL) struct code* new_code = code_new("!=", lchild->store_var, rchild->store_var, NULL);
		else if (op == IS_EQUAL) struct code* new_code = code_new("==", lchild->store_var, rchild->store_var, NULL);
		
		struct code* jump_code = code_new("goto", NULL, NULL, NULL);

		rchild->last_line_P->next = new_code;
		new_code->next = jump_code;
		parent->last_line_P = jump_code;

		parent->true_jump_lines = code_list_new(new_code);
		parent->false_jump_lines = code_list_new(jump_code);
		parent->true_jumpPs = codeP_list_new(&(parent->true_jump));
		parent->false_jumpPs = codeP_list_new(&(parent->false_jump));

		parent->true_jump = NULL;
		parent->false_jump = NULL;
		parent->store_var = NULL;

	}
	else
	{
		char* label = get_new_label();
		struct code* new_code = code_new("label", NULL, NULL, label);
		new_code->next = rchild->codeP;
		rchild->codeP = new_code;

		parent->codeP = lchild->codeP;
		parent->true_jump = NULL;
		parent->false_jump = NULL;
		parent->last_line_P = rchild->last_line_P;
		parent->store_var = NULL;

		if (op == AND)
		{
			code_list_backpatch(lchild->true_jump_lines, label);
			codeP_list_backpatch(lchild->true_jumpPs, new_code);

			parent->true_jump_lines = rchild->true_jump_lines;
			parent->false_jump_lines = code_list_join(lchild->false_jump_lines, rchild->false_jump_lines);

			parent->true_jumpPs = rchild->true_jumpPs;
			parent->false_jumpPs = codeP_list_join(lchild->false_jumpPs, rchild->false_jumpPs);

			codeP_list_add_elem(parent->true_jumpPs, &(parent->true_jump));
			codeP_list_add_elem(parent->false_jumpPs, &(parent->false_jump));
		}
		else // OR
		{
			code_list_backpatch(lchild->false_jump_lines, label);
			codeP_list_backpatch(lchild->false_jumpPs, new_code);

			parent->false_jump_lines = rchild->false_jump_lines;
			parent->true_jump_lines = code_list_join(lchild->true_jump_lines, rchild->true_jump_lines);

			parent->false_jumpPs = rchild->false_jumpPs;
			parent->true_jumpPs = codeP_list_join(lchild->true_jumpPs, rchild->true_jumpPs);

			codeP_list_add_elem(parent->true_jumpPs, &(parent->true_jump));
			codeP_list_add_elem(parent->false_jumpPs, &(parent->false_jump));
		}
	}
}

//-----------------------------------------------------------------------------------------------------------

int main()
{
	for(int i = 0; i < 1001; i++)
		printf("%s\n", get_new_label());
}