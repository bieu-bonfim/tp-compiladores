%{ 
/* C Code */

#include <stdio.h>
#include "yacc.tab.h"

%} 

/* Name Definition */ 



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
switch Iniciar[ ]profecia[ ]de[ ]
case Profetizar[ ]que[ ]se[ ]
default Cumprir[ ]profecia
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
{end_line} { return ENDLINE; }

{digito_positivo} { yylval.ival = atoi(yytext); return INT; }
{digito_negativo} { yylval.ival = atoi(yytext); return INT; }
{float_posit} { yylval.fval = atof(yytext); return FLOAT; }
{float_negat} { yylval.fval = atof(yytext); return FLOAT; }
{true} { yylval.ival = 1; return TRUE; }
{false} { yylval.ival = 0; return FALSE; }
{atribuicao} { return ASSIGN; }

{soma} { return PLUS; }
{subtracao} { return MINUS; }
{multiplicacao} { return MULT; }
{divisao} { return DIV; }
{mod} { return MOD; }

{adicionarUm} { return PLUSONE; }
{subtrairUm} { return MINUSONE; }
{derreferenciar} { return DEREF; }
{referenciar} { return REF; }

{maior} { return GT; }
{menor} { return LT; }
{maior_igual} { return GE; }
{menor_igual} { return LE; }
{ou} { return OR; }
{e} { return AND; }
{diferente} { return NE; }
{igualdade} { return EQ; }

{tipoInt} { return TYPEINT; }
{tipoLongInt} { return TYPELONG; }
{tipoShortInt} { return TYPESHORT; }
{tipoFloat} { return TYPEFLOAT; }
{tipoDouble} { return TYPEDOUBLE; }
{tipoBool} { return TYPEBOOL; }
{tipoChar} { return TYPECHAR; }
{tipoVoid} { return TYPEVOID; }

{abre_bloco} { return OPENBLOCK; }
{fecha_bloco} { return CLOSEBLOCK; }
{abre} { return OPENBRACK; }
{fecha} { return CLOSEBRACK; }
{divisor} { return COMMA; }
{delimitadorChar} { return QUOTE; }
{delimitadorCase} { return DELIMCASE; }

{while} { return WHILE; }
{for} { return FOR; }
{if} { return IF; }
{else} { return ELSE; }
{elseif} { return ELSEIF; }
{switch} { return SWITCH; }
{case} { return CASE; }
{default} { return DEFAULT; }
{goto} { return GOTO;}

{typedef} { return TYPEDEF;}
{struct} { return STRUCT;}
{union} { return UNION; }

{parametros} { return PARAMS; }
{chamarFunc} { return CALLFUNC; }
{declFunc} { return DECLFUNC; }
{return} { return RETURNT; }
{const} { return CONST; }
{volatile} { return VOLATILE; } 




{variavel} { yylval.sval = strdup(yytext); return ID; }

.         { printf("Extra characters: %s\n", yytext); }


%% 

/* C Code */

int yywrap() {
    return 1;
}