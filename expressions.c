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
		Label L4: ...... (Label, NULL, NULL, L4)
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

struct exprn
{
	int type; // 0->int, 1->float, 2->bool
	struct code* codeP;
	struct code* true_label_P; // Not significant for ints / floats
	struct code* false_label_P; // Not significant for ints / floats
	struct code* last_line_P;

	char* true_label_name; // Not significant for ints / floats
	char* false_label_name; // Not significant for ints / floats
	char* store_var; // Not significant for bools

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
			char* new_code = code_new("(float)", exprn->store_var, NULL, var);
		else
			char* new_code = code_new("(int)", exprn->store_var, NULL, var);
		exprn->last_line_P->next = new_code;
		exprn->last_line_P = new_code;
		exprn->store_var = var;
	}
	else if (duo_type == 20 || duo_type == 21) // bool -> int / float
	{
		char* temp_var = get_new_var();
		if (duo_type == 20)
		{
			char* new_true_code = code_new("assign", "1", NULL, temp_var);
			char* new_false_code = code_new("assign", "0", NULL, temp_var);
		}
		else
		{
			char* new_true_code = code_new("assign", "1.0", NULL, temp_var);
			char* new_false_code = code_new("assign", "0.0", NULL, temp_var);
		}

		new_true_code->next = exprn->true_label_P->next;
		exprn->true_label_P->next = new_true_code;
		exprn->true_label_P = NULL;
		exprn->true_label_name = NULL;

		new_false_code->next = exprn->false_label_P->next;
		exprn->false_label_P->next = new_false_code;
		exprn->false_label_P = NULL;
		exprn->false_label_name = NULL;

		//while(exprn->last_line_P->next != NULL) exprn->last_line_P = exprn->last_line_P->next;
		char* var = get_new_var();
		char* new_code = code_new("assign", exprn->store_var, NULL, var);
		exprn->last_line_P->next = new_code;
		exprn->last_line_P = new_code;

		exprn->store_var = var;
	}
	else // int / float -> bool
	{
		// Responsibility of correct assignment of true and false pointers relies on the caller 

		exprn->true_label_name = get_new_label();
		exprn->false_label_name = get_new_label();

		if (duo_type == 02)
			char* new_code1 = code_new("==", exprn->store_var, "0", exprn->true_label_name);
		else
			char* new_code1 = code_new("==", exprn->store_var, "0.0", exprn->true_label_name);

		char* new_code2 = code_new("goto", NULL, NULL, exprn->false_label_name);

		new_code1->next = new_code2;
		new_code2->next = exprn->last_line_P->next;
		exprn->last_line_P->next = new_code1;
		exprn->last_line_P = new_code2;

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
		if (lchild->op == 1 || rchild->op == 1)
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
		if (op == PLUS) code* new_code = code_new("PLUS", lchild->store_var, rchild->store_var, new_var);
		else if (op == MINUS) code* new_code = code_new("MINUS", lchild->store_var, rchild->store_var, new_var);
		else if (op == MINUS) code* new_code = code_new("MUL", lchild->store_var, rchild->store_var, new_var);
		else if (op == MINUS) code* new_code = code_new("DIVIDE", lchild->store_var, rchild->store_var, new_var);
		else code* new_code = code_new("MOD", lchild->store_var, rchild->store_var, new_var);
		
		rchild->last_line_P->next = new_code;
		parent->last_line_P = new_code;
		parent->store_var = new_var;

		parent->true_label_P = NULL;
		parent->false_label_P = NULL;
		parent->true_label_name = NULL;
		parent->false_label_name = NULL;
	}
	else if (present == 3)
	{
		assert(lchild->last_line_P->next == NULL && rchild->last_line_P->next == NULL);
		
		lchild->last_line_P->next = rchild->codeP;
		parent->codeP = lchild->codeP;

		char* new_var = get_new_var();
		if (op == PLUS) code* new_code = code_new("PLUS", lchild->store_var, rchild->store_var, new_var);
		else if (op == MINUS) code* new_code = code_new("MINUS", lchild->store_var, rchild->store_var, new_var);
		else if (op == MINUS) code* new_code = code_new("MUL", lchild->store_var, rchild->store_var, new_var);
		else if (op == MINUS) code* new_code = code_new("DIVIDE", lchild->store_var, rchild->store_var, new_var);
		else code* new_code = code_new("MOD", lchild->store_var, rchild->store_var, new_var);
		
		rchild->last_line_P->next = new_code;
		parent->last_line_P = new_code;
		parent->store_var = new_var;

		parent->true_label_P = NULL;
		parent->false_label_P = NULL;
		parent->true_label_name = NULL;
		parent->false_label_name = NULL;
	}
}

int main()
{
	for(int i = 0; i < 1001; i++)
		printf("%s\n", get_new_label());
}