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
	code rm = RM(1, 2);
	AfficherCode(rm);
	int x = poids(rm);
	printf("%d\n",x);
	
	//int dimension = rmdimension(2, 6);
	//int cpt = 5 ;
	//code cc = LireCode(argv[1]);
	//EcrireCode(argv[1] ,rm);
	//int p = poids(cc);
	//int tab[3] = {1, 0, 1};
	//int x = weight(tab, 3);
	//printf("%d\n", x);
	//int x = binomial(4, 10);
	//int dimension = rmdimension(atoi(argv[1]), atoi(argv[2]));
	//int x = atoi(argv[1]);
	//int y = atoi(argv[2]);
	
	
	
	/*FILE * src ;
	char * fct;
	char ligne[1024];
	
	src = fopen(argv[1], "r");
	if(!src){
		perror("errrrrr ");
		exit(1);}
	while( fgets(ligne, 1024, src)){
		fct = tbv(ligne, 8);
		if(degre(fct, 8) <= 5)
			print(fct, 8);
	
	}*/
		
}
