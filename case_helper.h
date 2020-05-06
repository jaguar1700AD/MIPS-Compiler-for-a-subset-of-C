struct Hcase
{
	char* label;
	int a; // insignificant for default

	struct code* startP;
	struct code* endP;
};

struct Hcase_list
{
	char* start_label;
	struct code_list* var_codes;
	struct code* default_jump_code;

	struct code* startP;
	struct code* endP;
};

struct Hcase* Hcase_new(char* label, int a, struct code* startP, struct code* endP)
{
	struct Hcase* cont = malloc(sizeof(struct Hcase));
	cont->label = label;
	cont->a = a;
	cont->startP = startP;
	cont->endP = endP;
	return cont;
}

struct Hcase_list* Hcase_list_new(char* start_label, struct code_list* var_codes, struct code* default_jump_code, struct code* startP, struct code* endP)
{
	struct Hcase_list* cont = malloc(sizeof(struct Hcase_list));
	cont->start_label = start_label;
	cont->var_codes = var_codes;
	cont->default_jump_code = default_jump_code;
	cont->startP = startP;
	cont->endP = endP;
	return cont;
}

void Hcase_backpatch(struct Hcase_list* list, char* var, char* def_jmp)
{
	struct code_list* temp = list->var_codes;
	while(temp != NULL)
	{
		temp->code->arg1 = malloc(sizeof(var));
		sprintf(temp->code->arg1, "%s", var);
		temp = temp->next;
	}
	list->default_jump_code->result = malloc(sizeof(def_jmp));
	sprintf(list->default_jump_code->result, "%s", def_jmp);
}