%{ 
/* C Code */

#include <stdio.h>

%} 

/* Name Definition */ 
%option noyywrap 


delim		 [ \t\n\r] 
ws		   {delim}+ 

end_line  (\.\.\.)

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



.         { }


%% 

/* C Code */

int main(void) 
{ 
    yylex(); 
    return 0; 
}