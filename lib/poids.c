#include <stdlib.h>
#include <stdio.h>

#include "code.h"
#include "poids.h"

int weight(int * vec, int n){
//calcule le poids d un vecteur de taille n
//le poids d un entier donné en base 2
   int i, wt = 0 ;
   for(i=0; i < n ; i++){
   	if (vec[i] == 1)
   		wt ++ ;
   }
   return wt ; 
}

int wt(int x){
//calcul le poids d un mot donné en base 10
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

void afficherVec(int * v, int n){
	int i;
	for(i=0; i < n ; i++)
		printf("%d ",v[i]);
	printf("\n\n\n");
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
  		
  		if(t & 1)
  			//generer tous les mots du code 
  			add(vec, cc.mat[i], cc.n);
  		t >>=  1 ;
  		i++ ;
  		}
  	printf("le nombre est %d \n",z);
 	afficherVec(vec, cc.n);
  	wt = weight(vec, cc.n);
  	if(wt < score) 
  		score = wt ;
  }
  printf("le poids de ce code est ");
  return score ; 
 }
  	 
  	 
  	 
/*
supposons RM(1, 2) 
n =  4 k = 3
et le code de RM est le suivant :
[1 1 1 1 ]
[0 1 0 1 ]
[0 0 1 1 ]

appliquons l algorithme de poids sur cette matrice 
z va varier de 1 à 8 (2³)

n oublions pas le mot du code 0000 ( en effet ce code contiendra 8 mots )

pour z = 1
le mot du code sera 1 1 1 1
 
pour z = 2 
le mot du code sera  0 1 0 1 

pour z = 3 
le mot du code sera 1 0 1 0 

pour z = 4 
le mot du code sera 0 0 1 1 

pour z = 5
le mot du code sera 1 1 0 0 

pour z = 6
le mot du code  sera 0 1 1 0 

pour z = 7  
le mot du code sera 1 0 0 1 

ces mots sont obtenus par des additions (xor) des differentes lignes de la matrice RM

en effet par exemple la ligne pour z = 3 est obtenu en faisant un xor bit à bit de la ligne 0 et 1 de la matrice (1111 ^ 0101 = 0101) 
remarquons que dans l exemple de z = 3, 3 = 11 deux bits sont à 1 donc xor des deux premieres lignes

prenons un exmple z = 7 ; 7 = 111 trois bits sont à 1 donc xor entre les 3 lignes de la matrice

prenons un exmple z = 1 ; un seul bit est à 1 donc on prend que la ligne 1 de la matrice 

donc les mots de la matrice ne sont que les combinaisons possibles(avec un XOR) de toutes les lignes du code
{ les mots du code seront v1, v2, v3, v1+v2, v1+v3, v2+v3, v1+v2+v3 et le mot 0000 ==> 8 mots au total }

*/
