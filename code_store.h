struct code_store
{
	struct code* startP;
	struct code* endP;

	char* store_var; // May be null in some cases : Eg for var_dec_list and loops

	// Last line will be an assignment of store_var
};

struct code_store* code_store_init(struct code* startP, struct code* endP, char* store_var)
{
	struct code_store* code_store = malloc(sizeof(struct code_store));
	code_store->startP = startP;
	code_store->endP = endP;
	code_store->store_var = store_var;
	return code_store;
}

struct code_store* code_store_copy_init(struct code_store* c)
{
	return code_store_init(c->startP, c->endP, c->store_var);
}

struct code_store* code_store_concat_init(struct code_store* c1, struct code_store* c2)
{
	// Responsibility of setting non NULL value of store_var on caller

	if (c1->endP != NULL) // c1 not empty
	{
		c1->endP->next = c2->startP;
		if (c2->endP != NULL) // c2 non empty
			return code_store_init(c1->startP, c2->endP, NULL);
		else
			return code_store_init(c1->startP, c1->endP, NULL);
	}
	else
		return code_store_init(c2->startP, c2->endP, NULL);
}

