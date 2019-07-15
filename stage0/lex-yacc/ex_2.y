/*1. Print operands as they arrive.						REDUCE

2. If stack=empty or stack top='(' , push i/p operator onto the stack. 		SHIFT

3. If i/p='(', push it on the stack.						SHIFT

4. If ')', pop the stack and print the operators until you see a ')'. 		REDUCE
   Discard  parentheses.

5. If i/p precedence > top of the stack, push it on the stack.			SHIFT

6. If i/p precedence = top of the stack, use association. 
   If %left, 									REDUCE
   If %right,									SHIFT

7. If i/p precedence < top of the stack, 					REDUCE 
Then test the incoming operator against the new top of stack.

8. At the end of the expression, pop and print all operators on the stack. (No parentheses should remain.)
*/
%{
	#include<stdio.h>
	#include<stdlib.h>
	
	int yyerror(char const *s);
     	int yyparse();
     	int yylex(void);
%}
%union {
	 char *str;
	}

%token STRI NEWLINE
%left '+' '-'
%left '*' '/'
%type <str>  STRI
%%
start: expr NEWLINE {printf("\nComplete\n");
			return 0;
		    }
	;
expr	:expr '+' expr	{printf("+ ");}
	|expr '-' expr	{printf("- ");}
	|expr '*' expr	{printf("* ");}
	|expr '/' expr	{printf("/ ");}	
	| '(' expr ')'	{ }
	|STRI	{printf("%s ",$1);}
	;

%%
int yyerror(char const *s)
{
    printf("yyerror  %s\n",s);
  
}
int main()
{
  yyparse();
  return 1;
}
















 
