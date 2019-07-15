%{
	#include<stdio.h>
	#include<stdlib.h>
	
	#include"task1.h"
	#include"task1.c"
	//int yyerror(char const*);
	int number;
	int instcnt=0,wrapcnt=0;
	int x,i;
	FILE *fp,*yyin;
	
	
%}

%%

L[0-9]+\n {	
	   	if(wrapcnt==0)//just copy label when jmp L0 etc and increment count since one of the \n matches with this
	   	{
	    		fp=fopen("task1i.xsm","a");
			fprintf(fp,"%s",yytext);
			fclose(fp);
			++instcnt;
          	}
		else if(wrapcnt==1)
		{
			fp=fopen("task1f.xsm","a");
			char *temp;
			temp=malloc(yyleng*sizeof(char));
			for(i=0;yytext[i]!='\n';i++)
			{
				temp[i]=yytext[i];
			}
			temp[i]='\0';
			x=searchlabel(temp);
			fprintf(fp,"%d\n",x);
			fclose(fp);
		}
	  }
L[0-9]+:\n {	
		if(wrapcnt==0)
		{//do not write this line back to task1i.xsm
			char *temp;
			temp=malloc(yyleng*sizeof(char));
			for(i=0;yytext[i]!=':';i++)
			{
				temp[i]=yytext[i];
			}
			temp[i]='\0';
		  	insertlabel(temp);
		
	        }


	   }

F[0-9]+\n {	
	   	if(wrapcnt==0)//just copy label when jmp L0 etc and increment count since one of the \n matches with this
	   	{
	    		fp=fopen("task1i.xsm","a");
			fprintf(fp,"%s",yytext);
			fclose(fp);
			++instcnt;
          	}
		else if(wrapcnt==1)
		{
			fp=fopen("task1f.xsm","a");
			char *temp;
			temp=malloc(yyleng*sizeof(char));
			for(i=0;yytext[i]!='\n';i++)
			{
				temp[i]=yytext[i];
			}
			temp[i]='\0';
			x=searchlabel(temp);
			fprintf(fp,"%d\n",x);
			fclose(fp);
		}
	  }
F[0-9]+:\n {	
		if(wrapcnt==0)
		{//do not write this line back to task1i.xsm
			char *temp;
			temp=malloc(yyleng*sizeof(char));
			for(i=0;yytext[i]!=':';i++)
			{
				temp[i]=yytext[i];
			}
			temp[i]='\0';
		  	insertlabel(temp);
		
	        }


	   }

[ \t\n]+ {	
		if(wrapcnt==0)
		{
			fp=fopen("task1i.xsm","a");
			fprintf(fp,"%s",yytext);
			fclose(fp);
			if(strcmp(yytext,"\n")==0)
			{
				++instcnt;
			}
		}
		if(wrapcnt==1)
		{
			fp=fopen("task1f.xsm","a");
			fprintf(fp,"%s",yytext);
			fclose(fp);
		}


	 }
0\n2056\n0\n0\n0\n0\n0\n0\n {	
				if(wrapcnt==0)
				{
					fp=fopen("task1i.xsm","a");
					fprintf(fp,"%s",yytext);
					fclose(fp);
					instcnt=instcnt+4;
				}
				if(wrapcnt==1)
				{
					fp=fopen("task1f.xsm","a");
					fprintf(fp,"%s",yytext);
					fclose(fp);
				}

			     }
. {		
		if(wrapcnt==0)
		{
			fp=fopen("task1i.xsm","a");
			fprintf(fp,"%c",*yytext);
			fclose(fp);
		}
		if(wrapcnt==1)
		{
			fp=fopen("task1f.xsm","a");
			fprintf(fp,"%c",*yytext);
			fclose(fp);
		}
  }

%%


int yywrap(void)
{
	
	if(wrapcnt==0)
	{
          yyin=fopen("task1i.xsm","r");
	  fp=fopen("task1f.xsm","w");
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
int main()
{
	yyin = fopen("task1.xsm","r");
	fp=fopen("task1i.xsm","w");
	fclose(fp);
	yylex();
	return 0;
}

