assign5: assign5.l assign5.y
	bison -d assign5.y
	flex assign5.l
	cc -o $@ assign5.tab.c lex.yy.c -lfl


