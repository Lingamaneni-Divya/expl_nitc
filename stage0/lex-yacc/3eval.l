%{
  #include "y.tab.h"
  #include<stdlib.h>
  #include <stdio.h>
%}

number [0-9]+

%%
{number} {
           yylval=atoi(yytext);
           return DIGIT;
         }
[\n] return *yytext;
(.) return *yytext;
%%
int yywrap()
{
return 1;
}
