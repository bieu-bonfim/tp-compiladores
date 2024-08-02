%{ 
/* C Code */

#include <stdio.h>

%} 

/* Name Definition */ 
%option noyywrap 


delim		 [ \t\n\r] 
ws		   {delim}+ 

end_line  (\.\.\.)

/* identificação de dígitos */
digito [0-9]
digito_positivo [+]?[digit]+
digito_negativo [-][digit]+
float_negat [-]?[digit]+\.[digit]+
float_posit [+]?[digit]+\.[digit]+

palavra [a-zA-Z]+

true Veritas
false Falsum
void Nulo

/* aritméticos */
soma fundido[ ]
subtracao extraido[ ]de[ ]
igual equivale[ ]a[ ]
multiplicacao replicado[ ]de[ ]
divisao se[ ]fragmenta[ ]em[ ]
mod transmoglifado[ ]a[ ]

/* lógicos */
maior é[ ]superior[ ]a[ ]
menor é[ ]inferior[ ]a[ ]
maior_igual é[ ]superequivalente[ ]a[ ]
menor_igual é[ ]infraequivalente[ ]a[ ]
ou ou[ ]entao[ ]
e assim[ ]como[ ]
diferente distinto[ ]de[ ]
atribuicao será[ ]

/* Tipos Primitivos */
tipoInt Glifo[ ]
tipoFloat Fractal[ ]
tipoBool Axioma[ ]
tipoChar Runa[ ]
tipoVoid Nulo[ ]



profetizar (?i:profetizar)
sob        (?i:sob)
switch   {profetizar}{delim}{sob}{delim}



caso  (?i:caso)
venha (?i:venha)
ser   (?i:ser)
case {caso}{delim}{venha}{delim}{ser}{delim}

trivial (?i:trivial)
default {caso}{delim}{trivial}






/* Pattern Action */ 
%% 


{ws}		  { } 
{end_line} {printf("Fim de linha%s\n", yytext);}
{digito} {printf("Dígito: %s\n", yytext);}
{digito_positivo} {printf("Digito +: %s\n", yytext);}
{digito_negativo} {printf("Digito -: %s\n", yytext);}
{float_posit} {printf("Float +: %s\n", yytext);}
{float_negat} {printf("Float -: %s\n", yytext);}
{true} {printf("True: %s\n", yytext);}
{false} {printf("False: %s\n", yytext);}
{void} {printf("Fim de linha: %s\n", yytext);}

{soma} {printf("Soma: %s\n", yytext);}
{subtracao} {printf("Subtracao: %s\n", yytext);}
{igual} {printf("Igual: %s\n", yytext);}
{multiplicacao} {printf("Multiplicacao: %s\n", yytext);}
{divisao} {printf("Divisao: %s\n", yytext);}
{mod} {printf("Mod: %s\n", yytext);}

{maior} {printf("Maior: %s\n", yytext);}
{menor} {printf("Menor: %s\n", yytext);}
{maior_igual} {printf("Maior_igual: %s\n", yytext);}
{menor_igual} {printf("Menor_igual: %s\n", yytext);}
{ou} {printf("Ou: %s\n", yytext);}
{e} {printf("E: %s\n", yytext);}
{diferente} {printf("Diferente: %s\n", yytext);}
{atribuicao} {printf("Atribui: %s\n", yytext);}


{tipoInt} {printf("Tipo int: %s\n", yytext);}
{tipoFloat} {printf("Tipo float: %s\n", yytext);}
{tipoBool} {printf("Tipo bool: %s\n", yytext);}
{tipoChar} {printf("Tipo char: %s\n", yytext);}
{tipoVoid} {printf("Tipo void: %s\n", yytext);}

{palavra} {printf("Variavel: %s\n", yytext);}



.         { }


%% 

/* C Code */

int main(void) 
{ 
    yylex(); 
    return 0; 
}