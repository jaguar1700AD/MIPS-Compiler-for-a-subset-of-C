#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a;
	switch(3 < 4)
	{
		case 1: a = 5; break;
		default: a = 2; break;
	}
	printf("%d\n", a);
}

| KEY_SWITCH LB E RB LC {table = sym_table_new(table);} CASE_LIST RC
{
	char* label = get_new_label();
	struct code* new_code = code_new("label", NULL, NULL, label);
	Hcase_backpatch($7, $3->store_var, label);
	$3->last_line_P->next = $7->startP;
	$7->endP->next = new_code;
	$$ = code_store_init($3->codeP, new_code, NULL);
};