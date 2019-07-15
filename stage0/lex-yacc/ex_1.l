%{
    #include <stdio.h> 
    #include "y.tab.h"
%}


%%

[a-zA-Z] {
          yylval = *yytext;
          return CHARACTER;
        }
"+"	return *yytext;
"-"	return *yytext;
"*"	return *yytext;
"\/"	  return *yytext;
[()]	  return *yytext;
[\n]      return NEWLINE;
(.)       return yyerror("unknown character\n");
%%

int yywrap()
{
	return 1;
}
