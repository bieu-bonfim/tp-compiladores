%{ 
/* C Code */

#include <stdio.h>
#include "translate.tab.h"

int line_number = 1;

%}
/* Name Definition */
delim		 [ \t\r] 
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
null_literal Nulo[ ]
break Que[ ]assim[ ]seja
continue Prossiga
string  \"([^\"]*)\"
char  \'([^\'])\'

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
tipoVoid Vazio[ ]


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
switch Iniciar[ ]profecia[ ]de[ ]
case Profetizar[ ]que[ ]se[ ]
default Cumprir[ ]profecia
goto Translocar[ ]para[ ]



/* Estruturas */
typedef Transmutar[ ]
struct Componentização[ ]
union Conjuntura[ ]
enum Glifos[ ]
const Imutável[ ]
volatile Volátil[ ]


/* Nova conjuntura */
conjuncture em[ ]

/* Funções */
declFunc Preparar[ ]magia[ ]de[ ]
chamarFunc Conjurar[ ]
parametros \,[ ]Componentes:[ ]
return Regressus[ ]


/* Unários */
adicionarUm Encantar[ ]
subtrairUm Desencantar[ ]
derreferenciar Alma[ ]de[ ]
referenciar Lembrança[ ]de[ ]
/* Pattern Action */ 

%% 

{string} {
    yylval.sval = strdup(yytext + 1);
    yylval.sval[strlen(yylval.sval) - 1] = '\0';
    return LITERALSTRING;
}

{char} {
    yylval.ival = yytext[1]; 
    return LITERALCHAR;     
}

{ws}		  { } 
\n             { printf("%s| %d |", yytext, line_number); line_number++; }



{end_line} { return ENDLINE; }

{digito_positivo} { yylval.ival = atoi(yytext); return INT; }
{digito_negativo} { yylval.ival = atoi(yytext); return INT; }
{float_posit} { yylval.fval = atof(yytext); return FLOAT; }
{float_negat} { yylval.fval = atof(yytext); return FLOAT; }
{true} { yylval.ival = 1; return TRUE; }
{false} { yylval.ival = 0; return FALSE; }
{atribuicao} { return ASSIGN; }

{soma} { yylval.arOp = PLUS; return AROP; }
{subtracao} { yylval.arOp = MINUS; return AROP; }
{multiplicacao} { yylval.arOp = MULT; return AROP; }
{divisao} { yylval.arOp = DIV; return AROP; }
{mod} { yylval.arOp = MOD; return AROP; }

{adicionarUm} { return PLUSONE; }
{subtrairUm} { return MINUSONE; }
{derreferenciar} { return DEREF; }
{referenciar} { return REF; }

{maior} { yylval.relOp = GT; return RELOP; }
{menor} { yylval.relOp = LT; return RELOP; }
{maior_igual} { yylval.relOp = GE; return RELOP; }
{menor_igual} { yylval.relOp = LE; return RELOP; }
{diferente} { yylval.relOp = NE; return RELOP; }
{igualdade} { yylval.relOp = EQ; return RELOP; }

{ou} { return OR; }
{e} { return AND; }
{negado} { return NOT; }

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
{switch} { return SWITCH; }
{case} { return CASE; }
{default} { return DEFAULT; }
{goto} { return GOTO;}
{break} { return BREAK; }
{continue} { return CONTINUE; }

{typedef} { return TYPEDEF;}
{struct} { return STRUCT;}
{union} { return UNION; }
{enum} { return ENUM; }
{conjuncture} {return CONJUNCTURE;}

{parametros} { return PARAMS; }
{chamarFunc} { return CALLFUNC; }
{declFunc} { return DECLFUNC; }
{return} { return RETURNT; }
{const} { return CONST; }
{volatile} { return VOLATILE; } 
{null_literal} { return NULLT; }

{abrearray} { return OPENARRAY; }
{fechaarray} { return CLOSEARRAY; }

{acessarPonteiro} { return POINT; }
{acessarValor} { return DOT; }


{variavel} { yylval.sval = strdup(yytext); return ID; }

.                 { printf("\033[0;36mErro de Infusao...\033[0m A magia foi profanada na linha %d... A seguinte ranhura foi condenada: %s\n", line_number, yytext); }


%% 

/* C Code */

int yywrap() {
    return 1;
}

