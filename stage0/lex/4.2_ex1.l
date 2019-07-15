/*first from console and then from a file input_file.l*/

%{
    #include <stdio.h>
    int cnt=0;
%}

%%
[0-9]+ {printf("number found :%d\n",atoi(yytext));}

%%

int yywrap()
{
  if(!cnt)
  {
    cnt++;
    yyin=fopen("input_file.l","r");
    return 0;
  }
  else 
  return 1;
}

int main()
{
  yylex();
  return 1;
}
