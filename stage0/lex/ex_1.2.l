/*number of intergers and floating point numbers*/
%{
     #include <stdio.h>
     #include <stdlib.h>
     int i=0,f=0;
%}
            
  
%%
[0-9]+[ |\n] {i++;}
[0-9]+\.[0-9]+[ |\n] {f++;}

%%
int yywrap()
{
  return 1;
}

int main()
{
   yyin=fopen("input_file_ex_1.2.l","r");
   yylex();
   printf("no of integers             = %d\n",i);
   printf("no of floating numbers     = %d\n",f);
   return 1;
}
