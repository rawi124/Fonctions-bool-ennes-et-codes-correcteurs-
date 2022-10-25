#include <stdlib.h>
#include <stdio.h>

#include "code.h"
#include "poids.h"
#include "decodage.h"



int decode(code C, int t[], int*cpt, int lim ){
	//ici notre t est le mot à decoder
	// il s arrete s il trouve un mot de poids plus grand que W

	//recherche un mot de c telque 
		//wt(c+t) < ou sans depasser cpt iteration 
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
			if(t[p]) add(t, C.mat[i], C.n);}
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
					 

	
