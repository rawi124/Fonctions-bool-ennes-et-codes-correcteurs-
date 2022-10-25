#include <stdlib.h>
#include <stdio.h>

#include "poids.h"
#include "code.h"
#include "RM.h"
#include "inout.h"
#include "decodage.h"
#include "degre.h"
#include "tbv.h"
#include "anf.h"

int main(int argc , char*argv[])
{
	//code rm = RM(1, 3);
	//int dimension = rmdimension(2, 6);
	//int cpt = 5 ;
	//int x = distance(rm, &cpt, 5 );
	//code cc = LireCode(argv[1]);
	//EcrireCode(argv[1] ,rm);
	//AfficherCode(rm);
	//int p = poids(cc);
	//int tab[3] = {1, 0, 1};
	//int x = weight(tab, 3);
	//printf("%d\n", x);
	//int x = binomial(4, 10);
	//int dimension = rmdimension(atoi(argv[1]), atoi(argv[2]));
	//int x = atoi(argv[1]);
	//int y = atoi(argv[2]);
	//printf("%d\n",x);
	
	
	FILE * src ;
	char * fct;
	char ligne[1024];
	
	src = fopen(argv[1], "r");
	if(!src){
		perror(" lire code : ");
		exit(1);}
	while( fgets(ligne, 1024, src){
		fct = tbv(ligne, 8);
		if(degre(fct, 8) <= 5)
		
}
