%{
#include <stdio.h>	
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "symbol_table.h"

%}

%union
{
	float num_f;
	int num_i;
	char* str;
}

%token INT FLOAT
%token <str> NAME <num_i> NUM_INT <num_f> NUM_FLOAT
%token LESS GREATER EQUAL LESS_EQUAL GREATER_EQUAL NOT_EQUAL IS_EQUAL
%token AND OR NOT
%token PLUS MINUS MUL DIV MOD
%token SEMI COMMA COLON
%token LB RB LC RC
%token MAIN VOID RETURN BREAK DEFAULT IF ELSE SWITCH CASE FOR WHILE

%%

PROG: SEMI
| SEMI PROG {printf("PROG\n");}
;

%%

int main(int argc, char** argv)
{
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



