#include <stdlib.h>
#include <stdio.h>

#include "code.h"
#include "anf.h"

void ANF(char *f, int q){
	int u;
	if(q == 1)
		return;
	ANF(f, q/2);
	ANF(f+(q/2), q/2);
	for(u=0; u<q/2; u++)
		f[(q/2)+u] ^= f[u];
		
}

void Fourier(int *F, int q){ //calcule le coef de Walsh
	int u, tmp;
	if(q == 1)
		return;
	Fourier(F, q/2);
	Fourier(F+(q/2), q/2);
	for(u=0; u<q/2; u++){
		tmp = F[u];
		F[u] = tmp + F[u+(q/2)];
		F[u+(q/2)] = tmp - F[u+(q/2)];
	}
}
