%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"y.tab.h"

	#include"task1.h"
	int yyerror(char const*);
	int number;
	
%}

%%
[0-9]+	{ 
		number=atoi(yytext);
		//printf("lex tree call 1:\n");
		yylval.tnode=create_tree(number,TLookup("int"),NULL,iconst_node,NULL,NULL,NULL);
		return NUM;
	}
	  

"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"%"	{return MOD;}

";"	{return *yytext;}
"="	{return *yytext;}
[()]	{return *yytext;}
","	{return *yytext;}
"."	{return *yytext;}

">="	{return GE;}
"<="	{return LE;}
"=="	{return EE;}
"!="	{return NE;}
">"	{return GT;}
"<"	{return LT;}
"and"	{return ANDTK;}
"or"	{return ORTK;}
"not"	{return NOTTK;}

"begin" {bodyflag=1;return PBEGIN;}
"end"	{bodyflag=0;return PEND;}
"write"	{return WRITE;}
"read"	{return READ;}


"if"	{return IF;}
"then"	{return THEN;}
"else"	{return ELSE;}
"endif"	{return ENDIF;}

"while"	{return WHILE;}
"do"	{return DO;}
"endwhile" {return ENDWHILE;}

"continue" {return CONTINUE;}
"break"    {return BREAK;}

"decl"  {declflag=1; return DECL;}
"enddecl" {declflag=0; return ENDDECL;}
[\[\]]	{return *yytext;}

"main"	{return MAINFN;}
"return" {return RETURN;}
[{}]	{return *yytext;}
"type"	{typedeclflag=1;return TYPE;}
"endtype" {typedeclflag=0;return ENDTYPE;}
"null"	{	//printf("lex tree call 2:\n");
		yylval.tnode=create_tree(0,TLookup("null"),yytext,null_node,NULL,NULL,NULL);
	return NULLTK;
	}
"alloc" {return ALLOC;}
"free"	{return FREE;}
"initialize"	{return INITIALIZE;}

"class"	{return CLASS;}
"endclass"	{return ENDCLASS;}
"self"	{return SELF;}
"extends" {return EXTENDS;}
"new"	{return NEW;}
"delete" {return DELETE;}



[ \t\n]+ { }

[a-zA-Z][a-zA-Z0-9_]*	{
				
				//printf("lex tree call 3:\n");
				yylval.tnode=create_tree(0,TLookup("null"),yytext,var_node,NULL,NULL,NULL);
				return VAR;
			}
["][^"\n]*["]  {	
			 //printf("lex tree call 4:\n");	
			 yylval.tnode=create_tree(0,TLookup("str"),yytext,sconst_node,NULL,NULL,NULL);
			return MESG;	
		}

. {printf("unknown character\n");
   exit(1);
   }
%%

int yywrap(void)
{
	 return 1;
}
