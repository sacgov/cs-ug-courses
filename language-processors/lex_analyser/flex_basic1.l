%{

%}
sp [ \t]
num [0-9]+
float \.[0-9]+
exp E[+\-][0-9]+
%option noyywrap
%%
[0-9]+ printf("%s integer\n",yytext);
[+\-]{num}{float} printf("%s floating point\n",yytext);
[+\-]{num}{float}?{exp} printf("%s exponential point\n",yytext);
auto|break |case|char|const|continue|do|double|else|enum|extern|float |
for|goto|if|int|long|register|return|short|signed|sizeof|static|struct |
switch|typedef|union|unsigned|void|volatile|while|printf|scanf|using|namespace|std|main printf("%s \t KEYWORD\n",yytext);
[ \t\n] ;
{sp}*#.*> printf("%s header\n",yytext);
{sp}*#.* printf("%s macro\n",yytext);
\; ;
[~&^\|]|(\|\|)|(&&) printf("%s logical operator \n",yytext);
, printf("%s comma",yytext);
[\{|\(|\[|\]|\)|\}] printf("%s is parenthesis\n",yytext  );
==|<=|>=|!=|[<>] printf("%s \t RELATIONAL OP\n",yytext);
= printf("%s \t ASSIGNMENT OP\n",yytext);
[a-zA-Z][a-zA-Z0-9]* printf("%s \t IDENTIFIER\n",yytext);
[0-9]+[a-zA-Z]+ printf("%s \t UNDEFINED TOKEN\n",yytext);
\/\*.*\*\/|\/\/.*$ printf("%s \t COMMENT \n",yytext);
[\+\-*/](=)? printf("%s \t ARITHMATIC OP\n",yytext);
(\+\+)|(\-\-) printf("%s \t ARITHMATIC OP\n",yytext);
\".*\" printf("%s \t STRING \n",yytext);


%%
int main(int argc,char **argv)
{
	///enter basic1.txt as input
	//yyin is the input file pointer
	//yylex generates the lex
	//yytext is text TOKEN
    yyin=fopen(argv[1],"r");
    yylex();
    fclose(yyin);
	return 0;
}
