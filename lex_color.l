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


/* variavel */
variavel {caractere}({caractere}|{digito})*

/* aritméticos */
soma fundido[ ]a[ ]
subtracao extraido[ ]de[ ]
multiplicacao replicado[ ]por[ ]
divisao fragmentado[ ]em[ ]
mod transmoglifado[ ]por[ ]

/* lógicos */
maior superior[ ]a[ ]
menor inferior[ ]a[ ]
maior_igual superequivalente[ ]a[ ]
menor_igual infraequivalente[ ]a[ ]
ou ou[ ]entao[ ]
e assim[ ]como[ ]
negado contrariando[ ]
igualdade equivalente[ ]a[ ]
diferente distinto[ ]de[ ]
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
delimitadorChar [\" | \"]


/* Comandos? nao sei o nome dessas coisa */
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

/* Funções */
declFunc Preparar[ ]magia[ ]de[ ]
chamarFunc Conjurar[ ]
parametros Componentes:[ ]
return Regressus[ ]


/* Unários */
adicionarUm Encantar[ ]
subtrairUm Desencantar[ ]







/* Pattern Action */ 
%% 


{ws}		  { } 
{end_line} {printf("(fim de linha)\n");}


{digito_positivo} {printf("\033[0;35m%s \033[0m", yytext);}
{digito_negativo} {printf("\033[0;35m%s \033[0m", yytext);}
{float_posit} {printf("\033[0;35m%s \033[0m", yytext);}
{float_negat} {printf("\033[0;35m%s \033[0m", yytext);}
{true} {printf("\033[0;35m%s \033[0m", yytext);}
{false} {printf("\033[0;35m%s \033[0m", yytext);}

{soma} {printf("\033[0;34m%s \033[0m", yytext);}
{subtracao} {printf("\033[0;34m%s \033[0m", yytext);}
{multiplicacao} {printf("\033[0;34m%s \033[0m", yytext);}
{divisao} {printf("\033[0;34m%s \033[0m", yytext);}
{mod} {printf("\033[0;34m%s \033[0m", yytext);}
{adicionarUm} {printf("\033[0;34m%s \033[0m", yytext);}
{subtrairUm} {printf("\033[0;34m%s \033[0m", yytext);}

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
{instanciar} {printf("\033[0;33m%s \033[0m", yytext);}

{parametros} {printf("\033[0;33m%s \033[0m", yytext);}
{chamarFunc} {printf("\033[0;33m%s \033[0m", yytext);}
{declFunc} {printf("\033[0;33m%s \033[0m", yytext);}
{return} {printf("\033[0;33m%s \033[0m", yytext);}

{variavel} {printf("\033[0;31m%s \033[0m", yytext);}



.         { }


%% 

/* C Code */

int main(void) 
{ 
    yylex(); 
    return 0; 
}