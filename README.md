Uses flex and bison to build a compiler that translates a simple subset of the C language to MIPS assembly
Implements int, float, main, void, return, break, default, if, else, switch, case, for, while, and basic arithmetic and boolean operators.
The file "assign5.l" is fed to flex which builds the lexical scanner "lex.yy.c"
The file "assign5.y" is fed to bison to builds the parser "assign5.tab.c" 
A symbol table "table" (definition in "symbol_table.h") is created within the main function in "assign5.y" to store vital information from the lexical analysis and parsing phases. 
