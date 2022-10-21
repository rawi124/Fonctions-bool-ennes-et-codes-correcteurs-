#include <stdlib.h>
#include <stdio.h>

#include "code.h"

code CreerCode(int k, int n){
  int i ;
  code res;
  res.n = n;
  res.k = k ;
  res.mat = calloc(k, sizeof(int*));
  for(i = 0 ; i < k ; i++)
	res.mat[i]=calloc(n, sizeof(int));
  return res;
}

void LibererCode(code cc){
 int i;
 for(i=0;i < cc.k; i++)
   free(cc.mat[i]);

 free(cc.mat);
}

void AfficherCode(code cc){
  printf("n =  %d k = %d\n", cc.n, cc.k);
  int i,j ;
  for(i = 0; i < cc.k ; i++){
  	printf("[");
  	for(j = 0 ; j < cc.n ; j++)
  		printf("%d ",cc.mat[i][j]);
  	printf("]\n");
  }
}

 

