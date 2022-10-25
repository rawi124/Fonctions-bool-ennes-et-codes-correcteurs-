#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "tbv.h"
#include "anf.h"

char* tbv(char * exp, int m){
	char * ptr ;
	ptr = exp;
	int u = 0 ;
	char * fct = calloc(1<<m, sizeof(char));
	while((*ptr) != '=')
		ptr++;
	ptr++;
	
	while (*ptr) {
		if(isalpha(*ptr)) u =u ^ 1 <<(*ptr -'a');
		if(*ptr == '+') {fct[u] = 1 ; u = 0;}
		ptr++;
	}
	fct[u] = 1 ; ANF(fct, 1 << m);
	return fct ;
}
		
