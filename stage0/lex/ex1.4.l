/*single line and multiline comments*/
%{
     #include <stdio.h>
     #include <stdlib.h>
     
%}

slinecomment \/\/(.)*\n
mlinecomment \/\*(\n|.)*\*\/\n      
%%

{slinecomment} {printf("Singleline comment:\n%s\n",yytext);}
{mlinecomment} {printf("Multiline comment:\n%s\n",yytext);}
. {printf(" ");}

%%
int yywrap()
{
  return 1;
}

int main()
{
   yyin=fopen("input_file_ex_1.4.l","r");
   yylex();
   
   return 1;
}
