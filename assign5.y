%{
#include <stdio.h>	
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "symbol_table.h"
#include "expressions.h"
#include "code_store.h"

int type; // The current variable declaration type
struct symbol_table* table = NULL;

%}

%union
{
	float num_f;
	int num_i;
	char* str;
	struct exprn* EXPRN;
	struct code_store* CODE_STORE;
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
%type <CODE_STORE> VAR_DEC VAR_DEC_ASSIGN_LIST VAR_DEC_ASSIGN ASSIGN STATEMENT PROG

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

PROG: STATEMENT PROG 
{
	$$ = code_store_concat_init($1, $2);

	printf(" \n ....PROG..... \n");
	code_print($$->startP);
	printf(" \n ............. \n");
}
| STATEMENT 
{
	$$ = code_store_copy_init($1);
	printf(" \n ....PROG..... \n");
	code_print($$->startP);
	printf(" \n ............. \n");
};

STATEMENT: 
VAR_DEC SEMI {$$ = code_store_copy_init($1);}
|  ASSIGN SEMI {$$ = code_store_copy_init($1);}
;

ASSIGN: NAME EQUAL E
{
	if (sym_table_search(table, $1) / 10  == 0){printf("Variable '%s' not found in current scope\n", $1); exit(1);}

	exprn_type_cast($3, type);
	char* var = get_user_var($1);
	struct code* new_code = code_new("assign", $3->store_var, NULL, var);\
	$3->last_line_P->next = new_code;
	$$ = code_store_init($3->codeP, new_code, var);
};

DATA_TYPE: TYPE_INT {$$ = 0;}| TYPE_FLOAT {$$ = 1;};

VAR_DEC_ASSIGN: NAME 
{
	if (sym_table_search(table, $1) / 10 == 1){printf("Variable '%s' already declared in current scope\n", $1); exit(1);}
	sym_table_insert(table, $1, type);
	$$ = code_store_init(NULL, NULL, NULL);
} 
| NAME EQUAL E
{
	exprn_type_cast($3, type);
	char* var = get_user_var($1);
	struct code* new_code = code_new("assign", $3->store_var, NULL, var);\
	$3->last_line_P->next = new_code;
	$$ = code_store_init($3->codeP, new_code, var);

	if (sym_table_search(table, $1) / 10  == 1){printf("Variable '%s' already declared in current scope\n", $1); exit(1);}
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
	int x = sym_table_search(table, $1);
	if (x == 0) {printf("Variable %s undeclared\n", $1); exit(1);}
	exprn_init_with_name($$, $1, x % 10);

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
	sym_table_print(table);
}

yyerror(const char* s)
{
	fprintf(stderr, "error: %s\n", s);
}



