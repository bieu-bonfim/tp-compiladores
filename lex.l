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

/* Palavras reservadas */
while Dilatar[ ]tempo[ ]enquanto[ ]
for Fraturar[ ]tempo[ ]se[ ]
if Ponderar[ ]se[ ]
else Ou[ ]optar[ ]por[ ]
switch Iniciar[ ]profecia[ ]de[ ]
case Profetizar[ ]que[ ]se[ ]
default Cumprir[ ]profecia
goto Translocar[ ]para[ ]


/* hierarquias e blocos */
abre_bloco \_\/
fecha_bloco \\\_
abre \[
fecha \]
divisor \,
delimitadorChar \"
delimitadorCase \;





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
\n             { printf("%s| %d | ", yytext, line_number+1); line_number++; }
{string} {
    yylval.sval = strdup(yytext + 1);
    yylval.sval[strlen(yylval.sval) - 1] = '\0';
    return LITERALSTRING;
}

{char} {
    yylval.ival = yytext[1]; 
    return LITERALCHAR;     
}

{ws}		  {printf("%s", yytext); } 




{end_line} {printf("%s", yytext); return ENDLINE; }

{digito_positivo} {printf("%s", yytext); yylval.ival = atoi(yytext); return INT; }
{digito_negativo} {printf("%s", yytext); yylval.ival = atoi(yytext); return INT; }
{float_posit} {printf("%s", yytext); yylval.fval = atof(yytext); return FLOAT; }
{float_negat} {printf("%s", yytext); yylval.fval = atof(yytext); return FLOAT; }
{true} {printf("%s", yytext); yylval.ival = 1; return TRUE; }
{false} {printf("%s", yytext); yylval.ival = 0; return FALSE; }
{atribuicao} {printf("%s", yytext); return ASSIGN; }

{soma} {printf("%s", yytext); yylval.arOp = PLUS; return AROP; }
{subtracao} {printf("%s", yytext); yylval.arOp = MINUS; return AROP; }
{multiplicacao} {printf("%s", yytext); yylval.arOp = MULT; return AROP; }
{divisao} {printf("%s", yytext); yylval.arOp = DIV; return AROP; }
{mod} {printf("%s", yytext); yylval.arOp = MOD; return AROP; }

{adicionarUm} {printf("%s", yytext); return PLUSONE; }
{subtrairUm} {printf("%s", yytext); return MINUSONE; }
{derreferenciar} {printf("%s", yytext); return DEREF; }
{referenciar} {printf("%s", yytext); return REF; }

{maior} {printf("%s", yytext); yylval.relOp = GT; return RELOP; }
{menor} {printf("%s", yytext); yylval.relOp = LT; return RELOP; }
{maior_igual} {printf("%s", yytext); yylval.relOp = GE; return RELOP; }
{menor_igual} {printf("%s", yytext); yylval.relOp = LE; return RELOP; }
{diferente} {printf("%s", yytext); yylval.relOp = NE; return RELOP; }
{igualdade} {printf("%s", yytext); yylval.relOp = EQ; return RELOP; }

{ou} {printf("%s", yytext); yylval.logOp = OROP; return LOGOP; }
{e} {printf("%s", yytext); yylval.logOp = ANDOP; return LOGOP; }
{negado} {printf("%s", yytext); return NOT; }

{tipoInt} {printf("%s", yytext); return TYPEINT; }
{tipoLongInt} {printf("%s", yytext); return TYPELONG; }
{tipoShortInt} {printf("%s", yytext); return TYPESHORT; }
{tipoFloat} {printf("%s", yytext); return TYPEFLOAT; }
{tipoDouble} {printf("%s", yytext); return TYPEDOUBLE; }
{tipoBool} {printf("%s", yytext); return TYPEBOOL; }
{tipoChar} { printf("%s", yytext);return TYPECHAR; }
{tipoVoid} {printf("%s", yytext); return TYPEVOID; }

{abre_bloco} { printf("%s", yytext);return OPENBLOCK; }
{fecha_bloco} { printf("%s", yytext);return CLOSEBLOCK; }
{abre} {printf("%s", yytext); return OPENBRACK; }
{fecha} {printf("%s", yytext); return CLOSEBRACK; }
{divisor} {printf("%s", yytext); return COMMA; }
{delimitadorChar} {printf("%s", yytext); return QUOTE; }
{delimitadorCase} {printf("%s", yytext); return DELIMCASE; }

{while} {printf("%s", yytext); return WHILE; }
{for} { printf("%s", yytext);return FOR; }
{if} {printf("%s", yytext); return IF; }
{else} {printf("%s", yytext); return ELSE; }
{switch} {printf("%s", yytext); return SWITCH; }
{case} {printf("%s", yytext); return CASE; }
{default} {printf("%s", yytext); return DEFAULT; }
{goto} {printf("%s", yytext); return GOTO;}
{break} { printf("%s", yytext);return BREAK; }
{continue} { printf("%s", yytext);return CONTINUE; }

{typedef} { printf("%s", yytext);return TYPEDEF;}
{struct} {printf("%s", yytext); return STRUCT;}
{union} {printf("%s", yytext); return UNION; }
{enum} {printf("%s", yytext); return ENUM; }
{conjuncture} {printf("%s", yytext);return CONJUNCTURE;}

{parametros} { printf("%s", yytext);return PARAMS; }
{chamarFunc} {printf("%s", yytext); return CALLFUNC; }
{declFunc} {printf("%s", yytext); return DECLFUNC; }
{return} {printf("%s", yytext); return RETURNT; }
{const} {printf("%s", yytext); return CONST; }
{volatile} {printf("%s", yytext); return VOLATILE; } 
{null_literal} {printf("%s", yytext); return NULLT; }

{abrearray} {printf("%s", yytext); return OPENARRAY; }
{fechaarray} { printf("%s", yytext);return CLOSEARRAY; }

{acessarPonteiro} { printf("%s", yytext);return POINT; }
{acessarValor} {printf("%s", yytext); return DOT; }


{variavel} {printf("%s", yytext); yylval.sval = strdup(yytext); return ID; }

.                 { printf("\033[0;36m\nErro de Infusao...\033[0m A magia foi profanada na linha %d... A seguinte ranhura foi condenada: %s\n", line_number, yytext); }


%% 

/* C Code */

int yywrap() {
    printf("\n| %d | ", line_number);
    return 1;
}

