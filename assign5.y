%{
#include <stdio.h>	
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "symbol_table.h"

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

%left IS_EQUAL OR AND NOT
%left NOT_EQUAL GREATER_EQUAL LESS_EQUAL GREATER LESS
%left PLUS MINUS MUL DIV MOD

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
{exprn_operate($$, $1, $3, PLUS);}
| E MINUS E
{exprn_operate($$, $1, $3, MINUS);}
| E MUL E
{exprn_operate($$, $1, $3, MUL);}
| E DIV E
{exprn_operate($$, $1, $3, DIV);}
| E MOD E
{exprn_operate($$, $1, $3, MOD);}
| E LESS E
{exprn_operate($$, $1, $3, LESS);}
| E GREATER E
{exprn_operate($$, $1, $3, GREATER);}
| E LESS_EQUAL E
{exprn_operate($$, $1, $3, LESS_EQUAL);}
| E GREATER_EQUAL E
{exprn_operate($$, $1, $3, GREATER_EQUAL);}
| E NOT_EQUAL E
{exprn_operate($$, $1, $3, NOT_EQUAL);}
| E IS_EQUAL E
{exprn_operate($$, $1, $3, IS_EQUAL);}
| E AND E
{exprn_operate($$, $1, $3, AND);}
| E OR E
{exprn_operate($$, $1, $3, OR);}
| NOT E 
{exprn_operate($$, $1, NULL, NOT);}
| LB E RB
{exprn_operate($$, $1, NULL, LB);}
| MINUS E
{exprn_operate($$, $1, NULL, -1);}
| NUM_INT
{exprn_init_with_int_value($$, $1);}
| NUM_FLOAT
{exprn_init_with_float_value($$, $1);}
| NAME
{
	int x = sym_table_search(table, $1);
	if (x == 0) {printf("Variable %s undeclared\n", $1); exit(1);}
	exprn_init_with_name($$, $1, x % 10);
}
; 

%%

int main(int argc, char** argv)
{
	type = -1;
	table = sym_table_new(NULL);
	yyparse();
	sym_table_print(table);

	// int tok;
	// while(tok = yylex()) 
	// {
	// 	printf("%d", tok);
	// 	if(tok == NUM_INT) printf(" = %d\n", yylval.num_i);
	// 	else if(tok == NUM_FLOAT) printf(" = %f\n", yylval.num_f);
	// 	else if(tok == NAME) printf(" = %s\n", yylval.str);
	// 	else printf("\n"); 
	// }
}

yyerror(const char* s)
{
	fprintf(stderr, "error: %s\n", s);
}



