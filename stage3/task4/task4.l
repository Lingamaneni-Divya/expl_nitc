%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"y.tab.h"
	#include"task4.h"
	int yyerror(char const*);
	int number;
	int wrapcnt=0,t;
	int instcnt=0,x;
	FILE *fp,*yyin;
	struct labeltable *head=NULL,*tail=NULL;
	
%}

%%
[0-9]+	{ if(wrapcnt==0)
		{number=atoi(yytext);
		yylval.no=create_tree(number,inttype,NULL,const_node,NULL,NULL,NULL);
		return NUM;
		}
	  else if(wrapcnt==1)//needed for MOV R0,1 etc
	  	{
		 fp=fopen("task4i.xsm","a");
		 fprintf(fp,"%s",yytext);
		 fclose(fp);
		}
	  else if(wrapcnt==2)
		{
		 fp=fopen("task4f.xsm","a");
		 fprintf(fp,"%s",yytext);
		 fclose(fp);
		}
	}
[a-z]	{
		if(wrapcnt==0)
		{
		yylval.no=create_tree(0,inttype,yytext,var_node,NULL,NULL,NULL);
		return ID;
		}
		else if(wrapcnt==1)//needed for "Read" etc
		{
			fp=fopen("task4i.xsm","a");
			fprintf(fp,"%c",*yytext);
			fclose(fp);
		}
		else if(wrapcnt==2)
		{
			fp=fopen("task4f.xsm","a");
			fprintf(fp,"%c",*yytext);
			fclose(fp);
		}
		
	}
"begin" {return PBEGIN;}
"end"	{return PEND;}
"write"	{return WRITE;}
"read"	{return READ;}

"+"	{return PLUS;}
"-"	{
		if(wrapcnt==0)
		{
			return MINUS;
		}
		else if(wrapcnt==1)//for arg1 of Read and Write etc
		{
			fp=fopen("task4i.xsm","a");
			fprintf(fp,"%s",yytext);
			fclose(fp); 
		}
		else if(wrapcnt==2)
		{
			fp=fopen("task4f.xsm","a");
			fprintf(fp,"%s",yytext);
			fclose(fp); 
		}
	}
"*"	{return MUL;}
"/"	{return DIV;}

";"	{return *yytext;}
"="	{return *yytext;}

">="	{return GE;}
"<="	{return LE;}
"=="	{return EE;}
"!="	{return NE;}
">"	{return GT;}
"<"	{return LT;}

"if"	{return IF;}
"then"	{return THEN;}
"else"	{return ELSE;}
"endif"	{return ENDIF;}

"while"	{return WHILE;}
"do"	{return DO;}
"endwhile" {return ENDWHILE;}

"continue" {return CONTINUE;}
"break"    {return BREAK;}
[()]	{return *yytext;}

[ \t\n]+ {
		if(wrapcnt==1)
		{
			fp=fopen("task4i.xsm","a");
			fprintf(fp,"%s",yytext);
			fclose(fp);
			if(strcmp(yytext,"\n")==0)
			{
				++instcnt;
			}
		}
		if(wrapcnt==2)
		{
			fp=fopen("task4f.xsm","a");
			fprintf(fp,"%s",yytext);
			fclose(fp);
		}
	 }

L[0-9]+\n {
	   	if(wrapcnt==1)//just copy label when jmp L0 etc and increment count since one of the \n matches with this
	   	{
	    		fp=fopen("task4i.xsm","a");
			fprintf(fp,"%s",yytext);
			fclose(fp);
			++instcnt;
          	}
		else if(wrapcnt==2)
		{
			fp=fopen("task4f.xsm","a");
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
		if(wrapcnt==1)
		{//do not write this line back to task4i.xsm
		  int num=0;
		  for(int i=1;yytext[i]!=':';i++)
		  {
			num=num*10+(yytext[i]-'0');
		  }
		  insertlabel(num);
		
	        }


	   }
0\n2056\n0\n0\n0\n0\n0\n0\n {
				if(wrapcnt==1)
				{
					fp=fopen("task4i.xsm","a");
					fprintf(fp,"%s",yytext);
					fclose(fp);
					instcnt=instcnt+4;
				}
				if(wrapcnt==2)
				{
					fp=fopen("task4f.xsm","a");
					fprintf(fp,"%s",yytext);
					fclose(fp);
				}

			     }

.	   {
		if(wrapcnt==0)
		{	
		yyerror("unknown character\n");
		exit(1);
		}
		if(wrapcnt==1)
		{
			fp=fopen("task4i.xsm","a");
			fprintf(fp,"%c",*yytext);
			fclose(fp);
		}
		if(wrapcnt==2)
		{
			fp=fopen("task4f.xsm","a");
			fprintf(fp,"%c",*yytext);
			fclose(fp);
		}
	}
%%

int yywrap(void)
{
	if(wrapcnt==0)
	{
          yyin=fopen("task4.xsm","r");
	  fp=fopen("task4i.xsm","w");
	  fclose(fp);
	  wrapcnt++;
	  yylex();
	  return 0;
	}
	else if(wrapcnt==1)
	{
          yyin=fopen("task4i.xsm","r");
	  fp=fopen("task4f.xsm","w");
	  fclose(fp);
	  wrapcnt++;
	  yylex();
	  printtable();
	  return 0;
	}
	else if(wrapcnt==2)
	{
          return 1;
	}
	
}
