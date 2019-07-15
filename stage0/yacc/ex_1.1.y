%{

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int yyparse();

int yyerror(char const *);
int c=0;
int prev='\0';
/*initiate prev character as null*/
%}

%token ANY IF THEN ELSE NEWLINE

%%
 
start:stmt NEWLINE {return 0;};
stmt: IF'('stmt')'THEN'{'stmt'}' {c++;}
     	|ANY 
     	|ANY stmt
        ;
%%


yylex()
{

  char c;
  if(prev=='\0')
  	c=getchar();
  else
        c=prev;
 
 if(c=='i')
  {
    c=getchar();
    if(c=='f')
     {
      prev='\0';
      return IF;
     }
    else
     { 
       prev=c;
       return ANY;
     }
  }
  if (c=='t')
   {
     c=getchar();
     if(c=='h')
      {
        c=getchar();
         if(c=='e')
          {
             c=getchar();
             if(c=='n')
             {
               prev='\0';
              return THEN;
             }
           
           }
         
       }
      prev=c;
      return ANY;
    }
    if (c==' ')
    {
     prev='\0';
     return yylex();
    }
    if (c=='\n')
     {
       prev='\0';
       return NEWLINE;
     }
     if(c=='{')
     {
       prev='\0';
       return c;
     }
     if(c=='}')
     {
       prev='\0';
       return c;
     }
    if(c=='(')
     {
       prev='\0';
       return c;
     }
    if(c==')')
     {
       prev='\0';
       return c;
     } 
     prev='\0';
     return ANY;
}

int yyerror(char const* s)
{
  printf("yyerror %s",s);
}
int main()
{
  yyparse();
  printf("\nno .of levels of nesting is %d\n",c);
  return 1;
}

