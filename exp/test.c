#include <stdlib.h>
#include <stdio.h>

#include "poids.h"
#include "code.h"
#include "RM.h"
#include "inout.h"

int main(int argc , char*argv[])
{
	//code rm = RM(2, 6);
	code cc = LireCode(argv[1]);
	//EcrireCode(argv[1] ,rm);
	AfficherCode(cc);
	int p = poids(cc);
	//int tab[3] = {1, 0, 1};
	//int x = weight(tab, 3);
	//printf("%d\n", x);
	//int x = binomial(4, 10);
	//int dimension = rmdimension(atoi(argv[1]), atoi(argv[2]));
	
	//int x = atoi(argv[1]);
	//int y = atoi(argv[2]);
	printf("%d\n",p);
}
