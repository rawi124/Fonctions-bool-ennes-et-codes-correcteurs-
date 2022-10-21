#include <stdlib.h>
#include <stdio.h>

#include "code.h"
#include "poids.h"

int weight(int * vec, int n){
   //calcule le poids d un vecteur de taille n
   int i, wt = 0 ;
   for(i=0; i < n ; i++){
   	if (vec[i] == 1)
   		wt ++ ;
   }
   return wt ; 
}
int wt(int x){
//calcul le poids d un mot donné en entier 
	int cpt = 0 ;
	while (x){
		if (x & 1)
			cpt++;
		x >>= 1 ;
		}
	return cpt ;
}
	

void add(int * d, int * s, int n)
{
	int j ;
	for( j=0; j< n ;j++)
		d[j] = d[j] ^s[j];
}

//la distance minimale d un code est la plus petite distance entre deux mots du code 

int poids(code cc){
  //calcule le poids minimal du code cc excepté 0
  //notre code est lineaire donc la distance minimale est egale au poids minimale 
  int score = cc.n;
  int z, t, wt;
  int vec[cc.n];
  int limite = 1 << cc.k ;
  for(z = 1 ; z < limite ; z++){
  	for(int j = 0 ; j < cc.n ; j++)
  		vec[j] = 0 ;
  	t = z; int i = 0 ;
  	while(t){
  		//printf("je suis t %d et i est egale a %d \n",t, i);
  		if(t & 1)
  			//generer tous les mots du code 
  			add(vec, cc.mat[i], cc.n);
  		t >>=  1 ;
  		i++ ;
  		}
  	//printf("je suis sorti de la boucle \n");
  	wt = weight(vec, cc.n);
  	if(wt < score) 
  		score = wt ;
  }
  printf("le poids de ce code est ");
  return score ; 
 }
  	 

