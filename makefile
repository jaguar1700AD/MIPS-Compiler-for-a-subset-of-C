assign5: assign5.l assign5.y symbol_table.h expressions.h
	bison -d assign5.y
	flex assign5.l
	cc -g -o $@ assign5.tab.c lex.yy.c -lfl


