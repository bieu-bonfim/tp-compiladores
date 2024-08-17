%{ 
/* C Code */

#include <stdio.h>


%} 

/* Name Definition */ 
%option noyywrap 


delim		 [ \t\n\r] 
ws		   {delim}+ 

end_line  (\.\.\.)

/* identificação */
digito [0-9]
caractere [a-zA-Z]
digito_positivo [+]?{digito}+
digito_negativo [-]{digito}+
float_negat [-]?{digito}+\.{digito}+
float_posit [+]?{digito}+\.{digito}+
palavra [a-zA-Z]+

true Veritas
false Falsum

/* aritméticos */
soma fundido[ ]a[ ]
subtracao dissolvido[ ]de[ ]
multiplicacao replicado[ ]por[ ]
divisao fragmentado[ ]em[ ]
mod transmoglifado[ ]por[ ]

atribuicao será[ ]

%% 



{ws}		  { } 
{end_line} { return ENDLINE }

{digito_positivo} { yylval.ival = atoi(yytext); return INT; }
{digito_negativo} { yylval.ival = atoi(yytext); return INT; }
{float_posit} { yylval.ival = atof(yytext); return FLOAT; }
{float_negat} { yylval.ival = atof(yytext); return FLOAT; }
{true} { yylval.ival = 1; return TRUE; }
{false} { yylval.ival = 0; return FALSE; }
{atribuicao} { return ASSIGN; }

{soma} { return PLUS }
{subtracao} { return MINUS }
{multiplicacao} { return MULT }
{divisao} { return DIV }
{mod} { return MOD }

.         { printf("Extra characters: %s\n", yytext); }


%% 

/* C Code */

int main(void) 
{ 
    yylex(); 
    return 0; 
}