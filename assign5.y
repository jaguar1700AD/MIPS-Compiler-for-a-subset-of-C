%{
#include <stdio.h>	
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "symbol_table.h"
#include "expressions.h"

int type; // The current variable declaration type
struct symbol_table* table = NULL;

%}

%union
{
	float num_f;
	int num_i;
	char* str;
	struct exprn* EXPRN;
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
%type <num_f> VALUE
%type <EXPRN> E

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

PROG: VAR_DEC_GLOBAL SEMI PROG | VAR_DEC_GLOBAL SEMI | E;

VALUE: NUM_INT {$$ = $1;} | NUM_FLOAT {$$ = $1;};

DATA_TYPE: TYPE_INT {$$ = 0;}| TYPE_FLOAT {$$ = 1;};

VAR_DEC: NAME 
{
	if (sym_table_search(table, $1) / 10 == 1){printf("Variable '%s' already declared in current scope\n", $1); exit(1);}
	sym_table_insert(table, $1, type);
} 
| NAME 
{
	if (sym_table_search(table, $1) / 10  == 1){printf("Variable '%s' already declared in current scope\n", $1); exit(1);}
	sym_table_insert(table, $1, type);
} 
EQUAL VALUE 
{
	if (type == 0) // int
	{
		int x = (int) $4;
		printf("%s, %d\n", $1, x);
	}
	else // float
	{
		float x = $4;
		printf("%s, %f\n", $1, x);	
	}
};

VAR_DEC_LIST: VAR_DEC COMMA VAR_DEC_LIST | VAR_DEC;

VAR_DEC_GLOBAL: DATA_TYPE {type = $1;} VAR_DEC_LIST;

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



