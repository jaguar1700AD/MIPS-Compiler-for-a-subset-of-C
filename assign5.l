%{
	#include "assign5.tab.h"
%}

%%

"int" {return TYPE_INT; }
"float" {return TYPE_FLOAT; }

"main" {return KEY_MAIN; }
"void" {return KEY_VOID; }
"return" {return KEY_RETURN; }
"break" {return KEY_BREAK; }
"default" {return KEY_DEFAULT; }
"if" {return KEY_IF; }
"else" {return KEY_ELSE; }
"switch" {return KEY_SWITCH; }
"case" {return KEY_CASE; }
"for" {return KEY_FOR; }
"while" {return KEY_WHILE; }

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

[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return NAME; }
([0-9]+) {yylval.num_i = atoi(yytext); return NUM_INT;}
([0-9]+.[0-9]+) {yylval.num_f = strtof(yytext, NULL); return NUM_FLOAT;}

[ \t\n\r] {; }
. {printf("Unknown character %s\n", yytext);}

%%

