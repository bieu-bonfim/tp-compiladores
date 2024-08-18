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
void Nulo
break Que[ ]assim[ ]seja
continue Prossiga

import Tutorar[ ]

/* acesso */
variavel {caractere}({caractere}|{digito})*
abrearray \-\|
fechaarray \|\-
definidorarray \|
acessarValor \>
acessarPonteiro \>\>
ponteiro Essência[ ]de[ ]


/* aritméticos */
soma fundido[ ]a[ ]
subtracao dissolvido[ ]de[ ]
multiplicacao replicado[ ]por[ ]
divisao fragmentado[ ]em[ ]
mod transmoglifado[ ]por[ ]

/* lógicos */
maior for[ ]superior[ ]a[ ]
menor for[ ]inferior[ ]a[ ]
maior_igual for[ ]superequivalente[ ]a[ ]
menor_igual for[ ]infraequivalente[ ]a[ ]
ou ou[ ]entao[ ]
e assim[ ]como[ ]
negado contrariando[ ]
igualdade for[ ]equivalente[ ]a[ ]
diferente for[ ]distinto[ ]de[ ]
atribuicao será[ ]

/* Tipos Primitivos */
tipoInt Glifo[ ]
tipoLongInt Arquiglifo[ ]
tipoShortInt Semiglifo[ ]
tipoFloat Fractal[ ]
tipoDouble Arquifractal[ ]
tipoBool Axioma[ ]
tipoChar Runa[ ]
tipoVoid Nulo[ ]


/* hierarquias e blocos */
abre_bloco \_\/
fecha_bloco \\\_
abre \[
fecha \]
divisor \,
delimitadorChar \"
delimitadorCase \;


/* Palavras reservadas */
while Dilatar[ ]tempo[ ]enquanto[ ]
for Fraturar[ ]tempo[ ]se[ ]
if Ponderar[ ]se[ ]
else Ou[ ]optar[ ]por[ ]
elseif Ou[ ]optar[ ]por[ ]ponderar[ ]se[ ]
switch   Iniciar[ ]profecia[ ]de[ ]
case Profetizar[ ]que[ ]se[ ]
default Cumprir[ ]profecia[ ]
goto Translocar[ ]para[ ]



/* Estruturas */
typedef Transmutar[ ]
struct Componentização[ ]em[ ]
union Conjuntura[ ]em[ ]
enum Glifos[ ]em[ ]
const Imutável[ ]
volatile Volátil[ ]

/* Funções */
declFunc Preparar[ ]magia[ ]de[ ]
chamarFunc Conjurar[ ]
parametros Componentes:[ ]
return Regressus[ ]


/* Unários */
adicionarUm Encantar[ ]
subtrairUm Desencantar[ ]
derreferenciar Alma[ ]de[ ]
referenciar Lembrança[ ]de[ ]
/* Pattern Action */ 
%% 



{ws}		  { } 
{end_line} {printf("(fim de linha)\n");}


{digito_positivo} { yylval.ival = atoi(yytext); return INT; }
{digito_negativo} { yylval.ival = atoi(yytext); return NEGINT; }
{float_posit} { yylval.ival = atof(yytext); return FLOAT; }
{float_negat} { yylval.ival = atof(yytext); return NEGFLOAT; }
{true} { yylval.ival = 1; return TRUE; }
{false} { yylval.ival = 0; return FALSE; }

{soma} { return PLUS }
{subtracao} { return MINUS }
{multiplicacao} { return MULT }
{divisao} { return DIV }
{mod} { return MOD }

{adicionarUm} { return PLUSONE }
{subtrairUm} { return MINUSONE }
{derreferenciar} {printf("\033[0;34m%s \033[0m", yytext);}
{referenciar} {printf("\033[0;34m%s \033[0m", yytext);}


{maior} {printf("\033[0;36m%s \033[0m", yytext);}
{menor} {printf("\033[0;36m%s \033[0m", yytext);}
{maior_igual} {printf("\033[0;36m%s \033[0m", yytext);}
{menor_igual} {printf("\033[0;36m%s \033[0m", yytext);}
{ou} {printf("\033[0;36m%s \033[0m", yytext);}
{e} {printf("\033[0;36m%s \033[0m", yytext);}
{diferente} {printf("\033[0;36m%s \033[0m", yytext);}
{atribuicao} {printf("\033[0;36m%s \033[0m", yytext);}
{igualdade} {printf("\033[0;36m%s \033[0m", yytext);}

{tipoInt} {printf("\033[0;32m%s \033[0m", yytext);}
{tipoLongInt} {printf("\033[0;32m%s \033[0m", yytext);}
{tipoShortInt} {printf("\033[0;32m%s \033[0m", yytext);}
{tipoFloat} {printf("\033[0;32m%s \033[0m", yytext);}
{tipoDouble} {printf("\033[0;32m%s \033[0m", yytext);}
{tipoBool} {printf("\033[0;32m%s \033[0m", yytext);}
{tipoChar} {printf("\033[0;32m%s \033[0m", yytext);}
{tipoVoid} {printf("\033[0;32m%s \033[0m", yytext);}

{abre_bloco} {printf("\nabre bloco %s\n", yytext);}
{fecha_bloco} {printf("fecha bloco %s\n", yytext);}
{abre} {printf("%s ", yytext);}
{fecha} {printf("%s ", yytext);}
{divisor} {printf("%s ", yytext);}
{delimitadorChar} {printf("%s ", yytext);}
{delimitadorCase} {printf("%s ", yytext);}

{while} {printf("\033[0;33m%s \033[0m", yytext);}
{for} {printf("\033[0;33m%s \033[0m", yytext);}
{if} {printf("\033[0;33m%s \033[0m", yytext);}
{else} {printf("\033[0;33m%s \033[0m", yytext);}
{elseif} {printf("\033[0;33m%s \033[0m", yytext);}
{switch} {printf("\033[0;33m%s \033[0m", yytext);}
{case} {printf("\033[0;33m%s \033[0m", yytext);}
{default} {printf("\033[0;33m%s \033[0m", yytext);}
{goto} {printf("\033[0;33m%s \033[0m", yytext);}

{typedef} {printf("\033[0;33m%s \033[0m", yytext);}
{struct} {printf("\033[0;33m%s \033[0m", yytext);}
{union} {printf("\033[0;33m%s \033[0m", yytext);}

{parametros} {printf("\033[0;33m%s \033[0m", yytext);}
{chamarFunc} {printf("\033[0;33m%s \033[0m", yytext);}
{declFunc} {printf("\033[0;33m%s \033[0m", yytext);}
{return} {printf("\033[0;33m%s \033[0m", yytext);}
{const} {printf("\033[0;33m%s \033[0m", yytext);}
{volatile} {printf("\033[0;33m%s \033[0m", yytext);}

{variavel} {printf("\033[0;31m%s \033[0m", yytext);}
{abrearray} {printf("\033[0;31m%s \033[0m", yytext);}
{fechaarray} {printf("\033[0;31m%s \033[0m", yytext);}
{acessarValor} {printf("\033[0;31m%s \033[0m", yytext);}
{acessarPonteiro} {printf("\033[0;31m%s \033[0m", yytext);}
{ponteiro} {printf("\033[0;31m%s \033[0m", yytext);}

{definidorarray} {printf("%s ", yytext);}


.         { }


%% 

/* C Code */

int main(void) 
{ 
    yylex(); 
    return 0; 
}