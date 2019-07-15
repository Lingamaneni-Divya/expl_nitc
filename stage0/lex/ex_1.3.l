/*number of 3 letter words starting with A*/
%{
     #include <stdio.h>
     #include <stdlib.h>
     int c=0;
%}

seq A..[ |\n|\.|\.\n]           
  
%%

{seq} {c++;}

%%
int yywrap()
{
  return 1;
}

int main()
{
   yyin=fopen("input_file_ex_1.3.l","r");
   yylex();
   printf("no of 3 letter words starting with A = %d\n",c);
   
   return 1;
}
