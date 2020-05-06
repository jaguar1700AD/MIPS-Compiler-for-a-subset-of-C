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

struct symbol_table
{
	struct variable_list* top;
	struct symbol_table* parent;
	int offset;
	int depth;
};

struct symbol_table* sym_table_new(struct symbol_table* parent)
{
	struct symbol_table* table = malloc(sizeof(struct symbol_table));
	table->top = NULL;
	table->parent = parent;
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

