%{
	#include<stdio.h>
	char *file1;
        int cnt;
%}

%%

[0-9]+ 	printf("found:%d\n",atoi(yytext));

%%

int yywrap()
{
       if(!cnt)
  	{
  		
  		yyin = stdin;
                ++cnt;
    		return 0;
  	}
  	
    return 1;
  	
      
}

int main()
{
	
  	yylex();
  	return 1;
}
