// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>

struct variable_list
{
	char* name;
	int type; // 0 -> int, 1 -> float

	struct variable_list* next;
};

struct symbol_table
{
	struct variable_list* top;
	struct symbol_table* parent;
};

struct symbol_table* sym_table_new(struct symbol_table* parent)
{
	struct symbol_table* table = malloc(sizeof(struct symbol_table));
	table->top = NULL;
	table->parent = parent;
	return table;
}

int sym_table_search(struct symbol_table* table, char* name)
{
	// x is the type of the found variable
	// 2x -> variable found in current scope
	// 1x -> variabe found in some larger scope
	// 0 -> not found

	bool first = true;
	while (table != NULL)
	{
		struct variable_list* top = table->top;
		while(top != NULL)
		{
			if (first)
			{
				if (!strcmp(top->name, name)) return 10 + top->type;
			}
			else
			{
				if (!strcmp(top->name, name)) return 20 + top->type;
			}
			top = top->next;
		}
		table = table->parent;
		if (first) first = false;
	}
	return 0;
}

void sym_table_insert(struct symbol_table* table, char* name, int type)
{
	struct variable_list* top = table->top;

	struct variable_list* new_var = malloc(sizeof(struct variable_list));
	new_var->name = malloc(sizeof(*name));
	strcpy(new_var->name, name);
	new_var->type = type;
	new_var->next = NULL;

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
	while(top != NULL)
	{
		printf("%s, %d\n", top->name, top->type);
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

