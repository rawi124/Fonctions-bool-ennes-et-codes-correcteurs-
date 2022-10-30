#ifndef DECODAGE_H
#define DECODAGE_H

#include "code.h"
#include "poids.h"

int decode(code C, int t[], int*cpt, int lim );
int distance(code C,  int*cpt, int lim );
int degre(char *f, int m);
char* tbv(char * exp, int m);
void Fourier(int *F, int q);
void print(char*fct, int m);

#endif
