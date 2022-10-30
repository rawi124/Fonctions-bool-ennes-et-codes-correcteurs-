#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


#include "code.h"
#include "poids.h"
#include "decodage.h"



int decode(code C, int t[], int*cpt, int lim ){
	//ici notre t est le mot à decoder
	// il s arrete s il trouve un mot de poids plus grand que W

	//recherche un mot de c telque 
		//wt(c+t) < w ou sans depasser cpt iteration 
	//p est ici la position du pivot qu'on va tirer ==> utiliser ce pivot et nettoyer toute la matrice 
	//position d un pivot c est la colonne 


	int i, p, w, k ;
	do{
		for(i=0; i< C.n; i++)
		{
			do
			{p = random()%C.n; } 
			while(C.mat[i][p]) ;//trouver un 1 aleatroirement sur la ligne mat[i]
			for(k = 0 ; k < C.k ; k++){
				if(k != i && C.mat[k][p])
					add(C.mat[k], C.mat[i], C.n);
			if(t[p]) 
				add(t, C.mat[i], C.n);}
		}
		w = weight(t, C.n);
	}while((*cpt)-- > 0 && w >= lim) ; 
	return w ;
}


int distance(code C,  int*cpt, int lim ){
	int i, p, w = C.n, k, t ;
	do{
		for(i=0; i< C.k; i++)
		{
			do
			{p = random()%C.n; } 
			while(! C.mat[i][p]) ;//trouver un 1 aleatroirement sur la ligne mat[i]
			for(k = 0 ; k < C.k ; k++){
				if(k != i && C.mat[k][p])
					add(C.mat[k], C.mat[i], C.n);
			}
			t = weight(C.mat[i], C.n);
			if(t < w) w = t ;
		}
	*cpt = *cpt - 1;
	}while( *cpt > 0 && w >= lim) ; 
	return w ;

}



/******************************ALGEBRIC NORMAL FORM ***********************************
Algebraic normal form (ANF) is a way of writing a boolean function using only XOR and AND.
Since it’s a normal form, two functions that do the same thing will be the same thing in ANF.

An example of boolean logic in ANF is the below:
f(x1, x2, x3, x4) = x1x2 + x1x3 + x1x4


********************************************************************************************/
void ANF(char *f, int q){
	int u;
	if(q == 1)
		return;
	ANF(f, q/2);
	ANF(f+(q/2), q/2);
	for(u=0; u<q/2; u++)
		f[(q/2)+u] ^= f[u];
		
}

	
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



	
void print(char*fct, int m){
	int u, v, l;
	printf("anf =");
	ANF(fct, 1 << m);
	for(u = 0; u < (1 <<m) ;u++)
		if (fct[u]) { v = u; l ='a' ;
			while(v){ if (v &1) putchar(l);
			
			l++;
			v = v >> 1 ;}
			putchar('+');
		}
	ANF( fct, 1 << m);
	printf("\n");
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
					 

	
