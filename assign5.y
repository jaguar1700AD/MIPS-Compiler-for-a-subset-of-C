%{
#include <stdio.h>	
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "symbol_table.h"
#include "expressions.h"
#include "code_store.h"
#include "case_helper.h"

int type; // The current variable declaration type
struct symbol_table* table = NULL;
struct depth_type* cont;

%}

%union
{
	float num_f;
	int num_i;
	char* str;
	struct exprn* EXPRN;
	struct code_store* CODE_STORE;
	struct Hcase* HCASE;
	struct Hcase_list* HCASE_LIST;
}

%token TYPE_INT TYPE_FLOAT
%token <str> NAME <num_i> NUM_INT <num_f> NUM_FLOAT
%token LESS GREATER EQUAL LESS_EQUAL GREATER_EQUAL NOT_EQUAL IS_EQUAL
%token AND OR NOT
%token PLUS MINUS MUL DIV MOD
%token SEMI COMMA COLON
%token LB RB LC RC
%token KEY_MAIN KEY_VOID KEY_RETURN KEY_BREAK KEY_DEFAULT KEY_IF KEY_ELSE KEY_SWITCH KEY_CASE KEY_FOR KEY_WHILE

%type <num_i> DATA_TYPE 
%type <EXPRN> E
%type <CODE_STORE> VAR_DEC VAR_DEC_ASSIGN_LIST VAR_DEC_ASSIGN ASSIGN STATEMENT STATEMENT_LIST BLOCK SWITCH PROG
%type <HCASE> CASE DEFAULT
%type <HCASE_LIST> CASE_LIST

%start PROG

%left IS_EQUAL 
%left OR
%left AND
%left NOT
%left NOT_EQUAL 
%left GREATER_EQUAL
%left LESS_EQUAL
%left GREATER
%left LESS
%left PLUS 
%left MINUS
%left MUL
%left DIV
%left MOD

%%

CASE: KEY_CASE NUM_INT COLON STATEMENT_LIST
{
	char* label = get_new_label();
	struct code* new_code = code_new("label", NULL, NULL, label);
	new_code->next = $4->startP;
	$$ = Hcase_new(label, $2, new_code, $4->endP);

	printf(" \n ....CASE..... \n");
	code_print($$->startP);
	printf(" \n ............. \n");
}
| KEY_CASE NUM_INT COLON
{
	char* label = get_new_label();
	struct code* new_code = code_new("label", NULL, NULL, label);
	$$ = Hcase_new(label, $2, new_code, new_code);

	printf(" \n ....CASE..... \n");
	code_print($$->startP);
	printf(" \n ............. \n");
};

DEFAULT: KEY_DEFAULT COLON STATEMENT_LIST
{
	char* label = get_new_label();
	struct code* new_code = code_new("label", NULL, NULL, label);
	new_code->next = $3->startP;
	$$ = Hcase_new(label, -1, new_code, $3->endP);
}
| KEY_DEFAULT COLON
{
	char* label = get_new_label();
	struct code* new_code = code_new("label", NULL, NULL, label);
	$$ = Hcase_new(label, -1, new_code, new_code);
}
|
{
	char* label = get_new_label();
	struct code* new_code = code_new("label", NULL, NULL, label);
	$$ = Hcase_new(label, -1, new_code, new_code);
}
;

CASE_LIST: CASE CASE_LIST
{
	char temp[10];
	sprintf(temp, "%d", $1->a);
	struct code* new_code = code_new("!=", NULL, temp, $2->start_label);
	new_code->next = $1->startP->next;
	$1->startP->next = new_code;
	struct code_list* new_list = code_list_new(new_code);
	new_list->next = $2->var_codes;
	while($1->endP->next != NULL) $1->endP = $1->endP->next;
	$1->endP->next = $2->startP;
	$$ = Hcase_list_new($1->label, new_list, $2->default_jump_code, $1->startP, $2->endP);
}
| CASE
{
	char temp[10];
	sprintf(temp, "%d", $1->a);
	struct code* new_code = code_new("!=", NULL, temp, NULL);
	new_code->next = $1->startP->next;
	$1->startP->next = new_code;
	while($1->endP->next != NULL) $1->endP = $1->endP->next;
	$$ = Hcase_list_new($1->label, code_list_new(new_code), new_code, $1->startP, $1->endP);
};

SWITCH: KEY_SWITCH LB E RB LC {table = sym_table_new(table);} CASE_LIST DEFAULT RC
{
	exprn_type_cast($3, 0);
	Hcase_backpatch($7, $3->store_var, $8->label);
	$3->last_line_P->next = $7->startP;
	$7->endP->next = $8->startP;
	$$ = code_store_init($3->codeP, $8->endP, NULL);
};

PROG: STATEMENT_LIST
{
	$$ = code_store_copy_init($1);

	printf(" \n ....PROG..... \n");
	code_print($$->startP);
	printf(" \n ............. \n");
}

STATEMENT_LIST: STATEMENT STATEMENT_LIST {$$ = code_store_concat_init($1, $2);}
| STATEMENT {$$ = code_store_copy_init($1);}
;

STATEMENT: SWITCH
| VAR_DEC SEMI {$$ = code_store_copy_init($1);}
|  ASSIGN SEMI {$$ = code_store_copy_init($1);}
| BLOCK {$$ = code_store_copy_init($1);}
| KEY_IF LB E RB STATEMENT
{
	exprn_type_cast($3, 2);

	char* true_label = get_new_label();
	char* false_label = get_new_label();
	struct code* true_label_line = code_new("label", NULL, NULL, true_label);
	struct code* false_label_line = code_new("label", NULL, NULL, false_label);

	// Insert new codes in between old codes
	assert($3->last_line_P->next == NULL && $5->endP->next == NULL);
	$3->last_line_P->next = true_label_line;
	true_label_line->next = $5->startP;
	$5->endP->next = false_label_line;

	code_list_backpatch($3->true_jump_lines, true_label);
	code_list_backpatch($3->false_jump_lines, false_label);
	codeP_list_backpatch($3->true_jumpPs, true_label_line);
	codeP_list_backpatch($3->false_jumpPs, false_label_line);
	
	$$ = code_store_init($3->codeP, false_label_line, NULL);
}
| KEY_IF LB E RB STATEMENT KEY_ELSE STATEMENT
{
	exprn_type_cast($3, 2);

	char* true_label = get_new_label();
	char* false_label = get_new_label();
	char* final_label = get_new_label();
	struct code* true_label_line = code_new("label", NULL, NULL, true_label);
	struct code* false_label_line = code_new("label", NULL, NULL, false_label);
	struct code* final_label_line = code_new("label", NULL, NULL, final_label);
	struct code* jump_line = code_new("goto", NULL, NULL, final_label);

	// Insert new codes in between old codes
	assert($3->last_line_P->next == NULL && $5->endP->next == NULL && $7->endP->next == NULL);
	$3->last_line_P->next = true_label_line;
	true_label_line->next = $5->startP;
	$5->endP->next = jump_line;
	jump_line->next = false_label_line;
	false_label_line->next = $7->startP;
	$7->endP->next = final_label_line;

	code_list_backpatch($3->true_jump_lines, true_label);
	code_list_backpatch($3->false_jump_lines, false_label);
	codeP_list_backpatch($3->true_jumpPs, true_label_line);
	codeP_list_backpatch($3->false_jumpPs, false_label_line);
	
	$$ = code_store_init($3->codeP, final_label_line, NULL);
}
;

BLOCK: LC RC {$$ = code_store_init(NULL, NULL, NULL);}
| LC 
{
	sym_table_print(table);
	table = sym_table_new(table);
}
STATEMENT_LIST RC 
{ 
	$$ = code_store_copy_init($3); 
	sym_table_print(table);
	table = table->parent;
	sym_table_print(table);
	printf(" \n ....BLOCK..... \n");
	code_print($$->startP);
	printf(" \n ............. \n");
}
;

ASSIGN: NAME EQUAL E
{
	cont = sym_table_search(table, $1);
	if (cont == NULL){printf("Variable '%s' not found in current scope\n", $1); exit(1);}

	exprn_type_cast($3, type);
	char* var = get_user_var($1, cont->depth);
	struct code* new_code = code_new("assign", $3->store_var, NULL, var);\
	$3->last_line_P->next = new_code;
	$$ = code_store_init($3->codeP, new_code, var);
};

DATA_TYPE: TYPE_INT {$$ = 0;}| TYPE_FLOAT {$$ = 1;};

VAR_DEC_ASSIGN: NAME 
{
	cont = sym_table_search(table, $1);
	if (cont != NULL && cont->depth == table->depth){printf("Variable '%s' already declared in current scope\n", $1); exit(1);}
	sym_table_insert(table, $1, type);
	$$ = code_store_init(NULL, NULL, NULL);
} 
| NAME EQUAL E
{
	exprn_type_cast($3, type);
	char* var = get_user_var($1, table->depth);
	struct code* new_code = code_new("assign", $3->store_var, NULL, var);\
	$3->last_line_P->next = new_code;
	$$ = code_store_init($3->codeP, new_code, var);

	cont = sym_table_search(table, $1);
	if (cont != NULL && cont->depth == table->depth){printf("Variable '%s' already declared in current scope\n", $1); exit(1);}
	sym_table_insert(table, $1, type);
};

VAR_DEC_ASSIGN_LIST: VAR_DEC_ASSIGN COMMA VAR_DEC_ASSIGN_LIST 
{
	$$ = code_store_concat_init($1, $3);
}
| VAR_DEC_ASSIGN
{
	$$ = code_store_copy_init($1);
};

VAR_DEC: DATA_TYPE {type = $1;} VAR_DEC_ASSIGN_LIST
{
	$$ = code_store_copy_init($3);
}
;

E: 	E PLUS E
{	
	$$ = exprn_init_null();
	exprn_operate($$, $1, $3, "+");
	printf(" \n ....+..... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| E MINUS E
{	
	$$ = exprn_init_null();
	exprn_operate($$, $1, $3, "-");
	printf(" \n ....-..... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| E MUL E
{	
	$$ = exprn_init_null();
	exprn_operate($$, $1, $3, "*");
	printf(" \n ....*..... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| E DIV E
{	
	$$ = exprn_init_null();
	exprn_operate($$, $1, $3, "/");
	printf(" \n ...../.... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| E MOD E
{	
	$$ = exprn_init_null();
	exprn_operate($$, $1, $3, "%");
	printf(" \n ....MOD..... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| E LESS E
{	
	$$ = exprn_init_null();
	exprn_operate($$, $1, $3, "<");
	printf(" \n .....<.... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| E GREATER E
{
	$$ = exprn_init_null();
	exprn_operate($$, $1, $3, ">");
	printf(" \n .....>.... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| E LESS_EQUAL E
{
	$$ = exprn_init_null();
	exprn_operate($$, $1, $3, "<=");
	printf(" \n ....<=..... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| E GREATER_EQUAL E
{
	$$ = exprn_init_null();
	exprn_operate($$, $1, $3, ">=");
	printf(" \n .....>=.... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| E NOT_EQUAL E
{
	$$ = exprn_init_null();
	exprn_operate($$, $1, $3, "!=");
	printf(" \n .....!=.... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| E IS_EQUAL E
{
	$$ = exprn_init_null();
	exprn_operate($$, $1, $3, "==");
	printf(" \n ....==..... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| E AND E
{
	$$ = exprn_init_null();
	exprn_operate($$, $1, $3, "&&");
	printf(" \n .....&&.... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| E OR E
{
	$$ = exprn_init_null();
	exprn_operate($$, $1, $3, "||");
	printf(" \n ....||..... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| NOT E 
{
	$$ = exprn_init_null();
	exprn_operate($$, $2, NULL, "!");
	printf(" \n .....!.... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| LB E RB
{
	$$ = exprn_init_null();
	exprn_operate($$, $2, NULL, "()");
	printf(" \n ....()..... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| MINUS E
{
	$$ = exprn_init_null();
	exprn_operate($$, $2, NULL, "-()");
	printf(" \n ....-()..... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| NUM_INT
{
	$$ = exprn_init_null();
	exprn_init_with_int_value($$, $1);
	printf(" \n ....NUM_INT..... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| NUM_FLOAT
{
	$$ = exprn_init_null();
	exprn_init_with_float_value($$, $1);
	printf(" \n ....NUM_FLOAT..... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
| NAME
{
	$$ = exprn_init_null();
	cont = sym_table_search(table, $1);
	if (cont == NULL) {printf("Variable %s undeclared\n", $1); exit(1);}
	char* user_var = get_user_var($1, cont->depth);
	exprn_init_with_name($$, user_var, cont->type);

	printf(" \n ....NAME..... \n");
	code_print($$->codeP);
	printf(" \n ............. \n");
}
; 

%%

int main(int argc, char** argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	// int tok;
	// while(tok = yylex()) 
	// {
	// 	printf("%d", tok);
	// 	if(tok == NUM_INT) printf(" = %d\n", yylval.num_i);
	// 	else if(tok == NUM_FLOAT) printf(" = %f\n", yylval.num_f);
	// 	else if(tok == NAME) printf(" = %s\n", yylval.str);
	// 	else printf("\n"); 
	// }

	type = -1;
	table = sym_table_new(NULL);;
	yyparse();
}

yyerror(const char* s)
{
	fprintf(stderr, "error: %s\n", s);
}



