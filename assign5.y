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

%%

PROG: VAR_DEC_GLOBAL SEMI PROG | VAR_DEC_GLOBAL SEMI;

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



