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
/*
********generation du code de reed muller *******************************
le code de RM contenant k vecteurs est construit de la maniere suivante :
	vi=2⁽i-1)
	par defaut v0=1..........1
	exemple pour RM(2, 4) qui a 11 vecteurs de longeur 16( 2⁴)
	v1===> i = 1 ===> 2¹-1 = 2⁰ = 1 donc 1 zero un 1
	v2 ==>2 zero deux 1 
	etc etc 
	v5=v1.v2
	v6=v1.v3
	v7=v1.v4
	v8=v2.v3
	v9=v2.v4
	v10=v3.v4
	
	v0 de deg 0
	v1...v4 de deg 1
	v5..v10 deg 2
*************************************************************************
*/
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

 
