%{
	#include<stdio.h>
	#include<stdlib.h>
	
	#include"task2.h"
	#include"task2.c"
	int yyerror(char const*);
	int number;
	int instcnt=0,wrapcnt=0;
	int x;
	FILE *fp,*yyin;
	int declflag=0;
	
%}

%%

L[0-9]+\n {	
	   	if(wrapcnt==0)//just copy label when jmp L0 etc and increment count since one of the \n matches with this
	   	{
	    		fp=fopen("task2i.xsm","a");
			fprintf(fp,"%s",yytext);
			fclose(fp);
			++instcnt;
          	}
		else if(wrapcnt==1)
		{
			fp=fopen("task2f.xsm","a");
			int num=0;
			for(int i=1;yytext[i]!='\n';i++)
			{
				num=num*10+(yytext[i]-'0');
				printf("label num:%d\n",num);
			}
			x=searchlabel(num);
			fprintf(fp,"%d\n",x);
			fclose(fp);
		}
	  }
L[0-9]+:\n {	
		if(wrapcnt==0)
		{//do not write this line back to task2i.xsm
		  int num=0;
		  for(int i=1;yytext[i]!=':';i++)
		  {
			num=num*10+(yytext[i]-'0');
		  }
		  insertlabel(num);
		
	        }


	   }


[ \t\n]+ {	
		if(wrapcnt==0)
		{
			fp=fopen("task2i.xsm","a");
			fprintf(fp,"%s",yytext);
			fclose(fp);
			if(strcmp(yytext,"\n")==0)
			{
				++instcnt;
			}
		}
		if(wrapcnt==1)
		{
			fp=fopen("task2f.xsm","a");
			fprintf(fp,"%s",yytext);
			fclose(fp);
		}


	 }
0\n2056\n0\n0\n0\n0\n0\n0\n {	
				if(wrapcnt==0)
				{
					fp=fopen("task2i.xsm","a");
					fprintf(fp,"%s",yytext);
					fclose(fp);
					instcnt=instcnt+4;
				}
				if(wrapcnt==1)
				{
					fp=fopen("task2f.xsm","a");
					fprintf(fp,"%s",yytext);
					fclose(fp);
				}

			     }
. {		
		if(wrapcnt==0)
		{
			fp=fopen("task2i.xsm","a");
			fprintf(fp,"%c",*yytext);
			fclose(fp);
		}
		if(wrapcnt==1)
		{
			fp=fopen("task2f.xsm","a");
			fprintf(fp,"%c",*yytext);
			fclose(fp);
		}
  }

%%


int yywrap(void)
{
	
	if(wrapcnt==0)
	{
          yyin=fopen("task2i.xsm","r");
	  fp=fopen("task2f.xsm","w");
	  fclose(fp);
	  wrapcnt++;
	  yylex();
	  print_label_table();
	  return 0;
	}
	else if(wrapcnt==1)
	{
	
          return 1;
	}
	
}
int yyerror(char const *s)
{
	printf("yyerror %s",s);
}
int main()
{
	yyin = fopen("task2.xsm","r");
	fp=fopen("task2i.xsm","w");
	fclose(fp);
	yylex();
	return 0;
}

