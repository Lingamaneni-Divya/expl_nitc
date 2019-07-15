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
	file1="1.txt";
  	yyin = fopen("input_file.l","r");

        yylex();
  	return 1;
}
