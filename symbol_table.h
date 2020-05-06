// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>

struct depth_type
{
	int depth;
	int type;
};

struct depth_type* depth_type_new(int depth, int type)
{
	struct depth_type* cont = malloc(sizeof(struct depth_type));
	cont->depth = depth;
	cont->type = type;
	return cont;
}

int get_data_size(int type)
{
	if (type == 0) return 2; // int
	else return 4; // float
}

struct variable_list
{
	char* name;
	int type; // 0 -> int, 1 -> float
	int offset;

	struct variable_list* next;
};

struct type_list
{
	int type;
	struct type_list* next;
};

struct type_list* type_list_new(int type)
{
	struct type_list* new_list = malloc(sizeof(struct type_list));
	new_list->type = type;
	new_list->next = NULL;
	return new_list;
}

struct type_list* type_list_insert_beg(struct type_list* list, int type)
{
	struct type_list* new_list = type_list_new(type);
	new_list->next = list;
	return new_list;
}

bool type_list_compare(struct type_list* list1, struct type_list* list2)
{
	while(list1 != NULL && list2 != NULL)
	{
		if (list1->type != list2->type) return false;
		list1 = list1->next;
		list2 = list2->next;
	}
	if (list1 != NULL || list2 != NULL) return false;
	return true;
}

struct fxn_list
{
	char* name;
	struct type_list* type_list;
	int ret_type;
	struct fxn_list* next;
};

bool fxn_compare(char* name1, struct type_list* list1, char* name2, struct type_list* list2)
{
	if (strcmp(name1, name2)) return false;
	if (!type_list_compare(list1, list2)) return false;
	return true;
}

struct symbol_table
{
	struct variable_list* top;
	struct symbol_table* parent;
	struct fxn_list* fxns;
	int offset;
	int depth;
};

struct symbol_table* sym_table_new(struct symbol_table* parent)
{
	struct symbol_table* table = malloc(sizeof(struct symbol_table));
	table->top = NULL;
	table->parent = parent;
	table->fxn_list = NULL;
	table->offset = 0;
	if (parent == NULL) table->depth = 0;
	else table->depth = parent->depth + 1;
	return table;
}

struct depth_type* sym_table_search(struct symbol_table* table, char* name)
{
	// x is the type of the found variable
	// {depth, type} returned
	// NULL -> not found

	struct depth_type* cont = malloc(sizeof(struct depth_type));

	while (table != NULL)
	{
		struct variable_list* top = table->top;
		while(top != NULL)
		{
			if (!strcmp(top->name, name)) return depth_type_new(table->depth, top->type);
			top = top->next;
		}
		table = table->parent;
	}
	return NULL;
}

struct depth_type* sym_table_fxn_search(struct symbol_table* table, char* name, struct type_list* list)
{
	// x is the ret_type of the found fxn
	// {depth, type} returned
	// NULL -> not found

	struct depth_type* cont = malloc(sizeof(struct depth_type));

	while (table != NULL)
	{
		struct fxn_list* top = table->fxns;
		while(top != NULL)
		{
			if (fxn_compare(top->name, top->type_list, name, list)) return depth_type_new(table->depth, top->ret_type);
			top = top->next;
		}
		table = table->parent;
	}
	return NULL;
}

void sym_table_insert(struct symbol_table* table, char* name, int type)
{
	struct variable_list* top = table->top;

	struct variable_list* new_var = malloc(sizeof(struct variable_list));
	new_var->name = malloc(sizeof(*name));
	strcpy(new_var->name, name);
	new_var->type = type;
	new_var->next = NULL;
	new_var->offset = table->offset;
	table->offset += get_data_size(type);

	if (top != NULL)
	{
		while (top->next != NULL) top = top->next;
		top->next = new_var;
	}
	else
		table->top = new_var;
}

void sym_table_fxn_insert(struct symbol_table* table, char* name, struct type_list* list, int ret_type)
{
	struct fxn_list* top = table->fxns;

	struct fxn_list* new_fxn = malloc(sizeof(struct fxn_list));
	new_fxn->name = malloc(sizeof(*name));
	strcpy(new_fxn->name, name);
	new_fxn->ret_type = ret_type;
	new_fxn->next = NULL;
	new_fxn->type_list = list;

	if (top != NULL)
	{
		while (top->next != NULL) top = top->next;
		top->next = new_fxn;
	}
	else
		table->fxn_list = new_fxn;
}

void sym_table_print(struct symbol_table* table)
{
	struct variable_list* top = table->top;
	printf("\n.................................\n");
	printf("Depth = %d.......\n", table->depth);
	while(top != NULL)
	{
		printf("%s, %d, %d\n", top->name, top->type, top->offset);
		top = top->next;
	}
	struct fxn_list* fxn = table->fxn_list;
	while(fxn != NULL)
	{
		printf("%s, %d", fxn->name, fxn->ret_type);
		struct type_list* list = fxn->type_list;
		while(list != NULL) 
		{
			printf(", %d\n", list->type);
			list = list->next;
		}
		fxn = fxn->next;
	}
}

// int main()
// {
// 	struct symbol_table* table = sym_table_new(NULL);
// 	sym_table_print(table);
// 	sym_table_insert(table, "abs", 0);
// 	sym_table_insert(table, "xy", 1);
// 	sym_table_print(table);

// 	table = sym_table_new(table);
// 	sym_table_print(table);
// 	sym_table_insert(table, "popper", 0);
// 	sym_table_insert(table, "dillo", 1);
// 	sym_table_print(table);

// 	table = sym_table_new(table);
// 	sym_table_print(table);
// 	sym_table_insert(table, "mamma", 0);
// 	sym_table_insert(table, "pappa", 1);
// 	sym_table_print(table);

// 	printf("\n%d, %d, %d \n", sym_table_search(table, "abs"), sym_table_search(table->parent, "abs"), sym_table_search(table->parent->parent, "abs"));
// }

