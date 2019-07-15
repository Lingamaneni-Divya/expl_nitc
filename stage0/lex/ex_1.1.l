%{
     #include <stdio.h>
     #include <stdlib.h>
     int l=0,w=0,c=0;
%}
space [ |\t]+
newline [\n]
anychar .          
 
%%
{newline}  {l++;w++;printf("l,w,c:%d %d %d\n",l,w,c);}
{newline}{space} {l++;w++;printf("l,w,c:%d %d %d\n",l,w,c);}
{space}{newline} {l++,w++;printf("l,w,c:%d %d %d\n",l,w,c);}
 /*
{newline}{anychar} {l++;w++;c++;printf("l,w,c:%d %d %d\n",l,w,c);}*/

{space}   {w++;printf("l,w,c:%d %d %d\n",l,w,c);}
{anychar} {c++;printf("l,w,c:%d %d %d\n",l,w,c);}

%%
int yywrap()
{
  return 1;
}

int main()
{
   yyin=fopen("input_file_ex_1.1.l","r");
   yylex();
   printf("no of lines      = %d\n",l);
   printf("no of words      = %d\n",w);
   printf("no of characters = %d\n",c);
   return 1;
}
