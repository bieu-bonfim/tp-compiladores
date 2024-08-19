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
{end_line} {printf("Fim de linha\n");}


{digito_positivo} {printf("Inteiro positivo: %s\n", yytext);}
{digito_negativo} {printf("Inteiro negativo: %s\n", yytext);}
{float_posit} {printf("Float positivo: %s\n", yytext);}
{float_negat} {printf("Float negativo: %s\n", yytext);}
{true} {printf("Verdadeiro: %s\n", yytext);}
{false} {printf("Falso: %s\n", yytext);}

{soma} {printf("Operador de soma: %s\n", yytext);}
{subtracao} {printf("Operador de subtracao: %s\n", yytext);}
{multiplicacao} {printf("Operador de multiplicacao: %s\n", yytext);}
{divisao} {printf("Operador de divisao: %s\n", yytext);}
{mod} {printf("Operador de resto: %s\n", yytext);}

{adicionarUm} {printf("Operador unario de adicao: %s\n", yytext);}
{subtrairUm} {printf("Operador unario de subtracao: %s\n", yytext);}
{derreferenciar} {printf("Derreferenciacao de ponteiro: %s\n", yytext);}
{referenciar} {printf("Referenciacao de ponteiro: %s\n", yytext);}


{maior} {printf("Operador relacional maior: %s\n", yytext);}
{menor} {printf("Operador relacional menor: %s\n", yytext);}
{maior_igual} {printf("Operador relacional maior ou igual: %s\n", yytext);}
{menor_igual} {printf("Operador relacional menor ou igual: %s\n", yytext);}
{ou} {printf("Operador logico or: %s\n", yytext);}
{e} {printf("Operador logico and: %s\n", yytext);}
{diferente} {printf("Operador relacional diferente: %s\n", yytext);}
{atribuicao} {printf("Operador de atribuicao: %s\n", yytext);}
{igualdade} {printf("Operador relacional de igualdade: %s\n", yytext);}

{tipoInt} {printf("Tipo primitivo: %s\n", yytext);}
{tipoLongInt} {printf("Tipo primitivo: %s\n", yytext);}
{tipoShortInt} {printf("Tipo primitivo: %s\n", yytext);}
{tipoFloat} {printf("Tipo primitivo: %s\n", yytext);}
{tipoDouble} {printf("Tipo primitivo: %s\n", yytext);}
{tipoBool} {printf("Tipo primitivo: %s\n", yytext);}
{tipoChar} {printf("Tipo primitivo: %s\n", yytext);}
{tipoVoid} {printf("Tipo primitivo: %s\n", yytext);}

{abre_bloco} {printf("\nAbre bloco %s\n", yytext);}
{fecha_bloco} {printf("Fecha bloco %s\n", yytext);}
{abre} {printf("Abre colchetes %s\n", yytext);}
{fecha} {printf("Fecha colchetes %s\n", yytext);}
{divisor} {printf("Vírgula divisora %s\n", yytext);}
{delimitadorChar} {printf("Abre aspas %s\n", yytext);}
{delimitadorCase} {printf("Fecha aspas %s\n", yytext);}

{while} {printf("Palavra reservada: %s\n", yytext);}
{for} {printf("Palavra reservada: %s\n", yytext);}
{if} {printf("Palavra reservada: %s\n", yytext);}
{else} {printf("Palavra reservada: %s\n", yytext);}
{switch} {printf("Palavra reservada: %s\n", yytext);}
{case} {printf("Palavra reservada: %s\n", yytext);}
{default} {printf("Palavra reservada: %s\n", yytext);}
{goto} {printf("Palavra reservada: %s\n", yytext);}

{typedef} {printf("Palavra reservada de declaracao: %s\n", yytext);}
{struct} {printf("Palavra reservada de estrutura: %s\n", yytext);}
{union} {printf("Palavra reservada de uniao: %s\n", yytext);}

{parametros} {printf("Palavra reservada: %s\n", yytext);}
{chamarFunc} {printf("Palavra reservada: %s\n", yytext);}
{declFunc} {printf("Palavra reservada: %s\n", yytext);}
{return} {printf("Palavra reservada: %s\n", yytext);}
{const} {printf("Palavra reservada: %s\n", yytext);}
{volatile} {printf("Palavra reservada: %s\n", yytext);}

{variavel} {printf("Variavel: %s\n", yytext);}
{abrearray} {printf("Abre array: %s\n", yytext);}
{fechaarray} {printf("Fecha array: %s\n", yytext);}
{acessarValor} {printf("Unario de acesso a valor: %s\n", yytext);}
{acessarPonteiro} {printf("Unario de acesso a ponteiro: %s\n", yytext);}
{ponteiro} {printf("Unario de ponteiro: %s\n", yytext);}

{definidorarray} {printf("Delimitador de array: %s\n", yytext);}



.         { }


%% 

/* C Code */

int main(void) 
{ 
    yylex(); 
    return 0; 
}