%{
	#include "assign5.tab.h"
%}

%%

"int" {return INT; }
"float" {return FLOAT; }

[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = yytext; return NAME; }
([0-9]+) {yylval.num_i = atoi(yytext); return NUM_INT;}
([0-9]+.[0-9]+) {yylval.num_f = strtof(yytext, NULL); return NUM_FLOAT;}

"<" {return LESS;}
">" {return GREATER;}
"=" {return EQUAL;}
"<=" {return LESS_EQUAL; }
">=" {return GREATER_EQUAL;}
"!=" {return NOT_EQUAL; }
"==" {return IS_EQUAL; }

"&&" {return AND; }
"||" {return OR; }
"!" {return NOT; }

"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"%" {return MOD;}

";" {return SEMI;}
"," {return COMMA;}
":" {return COLON;}

"(" {return LB; }
")" {return RB; }
"{" {return LC; }
"}" {return RC; }

"main" {return MAIN; }
"void" {return VOID; }
"return" {return RETURN; }
"break" {return BREAK; }
"default" {return DEFAULT; }
"if" {return IF; }
"else" {return ELSE; }
"switch" {return SWITCH; }
"case" {return CASE; }
"for" {return FOR; }
"while" {return WHILE; }

[ \t\n\r] {; }
. {printf("Unknown character %s\n", yytext);}

%%

