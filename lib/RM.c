#include <stdlib.h>
#include <stdio.h>

#include "RM.h"
#include "code.h"
#include "poids.h"

int binomial(int k, int n){
//calcule coefficient binomial de k parmis n 
	int r = 1 ;
	int i ;
	for(i = 0 ; i < k ; i++)
		r *= (n-i);
		//pour obtenir ici le quotient de n! / (n-k)!
	for(i = 1 ; i <= k; i++)
		r = r/i ;
	return r ;
}

int rmdimension(int k, int n){
	int i ;
	int dim = 0 ;
	for(i = 0 ; i <= k ; i++)
	{
		//printf("%d \n",binomial(i, n));
		dim += binomial(i, n);
	}
	//printf("\n\n\n\n");
	return dim ;
}
code RM(int k, int n){
	code res ; 
	int u, i, x;
	res = CreerCode( rmdimension(k, n), 1 << n);
	//printf("%d %d\n", rmdimension(k, n), 1 << n); 
	i = 0 ;
	for(u=0; u < res.n ; u++){
		if (wt(u) <= k){
			for(x=0; x<res.n; x++)
				res.mat[i][x] = ((x&u) == u);
			i++;
		}
	}return res ;
		
 }
