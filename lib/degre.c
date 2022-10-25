#include <stdlib.h>
#include <stdio.h>


#include "degre.h"
#include "anf.h"
#include "tbv.h"
#include "poids.h"



int degre(char *f, int m){
	int u, res = -1 ;
	ANF(f, 1 << m);
	for(u=0; u <( 1<<m); u++){
		if(f[u] && (wt(u)>res))
			res = wt(u);
	}
	ANF(f, 1 << m);
	return res;
	}

