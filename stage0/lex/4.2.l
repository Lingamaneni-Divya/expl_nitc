%{
	#include<stdio.h>
	char *file1;
%}

%%

[0-9]+ 	{printf("number found:%d\n",atoi(yytext));}

%%

int yywrap()
{
  	FILE *newfile_pointer;
  	char *file2="input_file_2.l";
  	newfile_pointer=fopen("input_file_2.l","r");
  	if(strcmp(file1,file2)!=0)
  	{
  		file1=file2;  
  		yyin = newfile_pointer;
    		return 0;
  	}
  	else
  		return 1;
}

int main()
{
	file1="input_file.l";
  	yyin = fopen("input_file.l","r");
  	yylex();
  	return 1;
}
