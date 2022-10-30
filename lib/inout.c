#include <stdio.h>
#include <stdlib.h>

#include "inout.h"
#include "code.h"
#include "decodage.h"

code LireCode(char*src)
{
    int k ,n ;
    FILE*fichier = fopen(src ,"r");
    code res ;
    if ( NULL == fichier )
    {
	perror(" lire code : ");
	exit(1);
	// exit(1) car erreur ,doit etre different de 0
    }
    else
    {
        char ligne[1024];
        int i = 0, j = 0 , x = 0;
	while(! feof(fichier))
	{

	    fgets(ligne,1024,fichier);
	    switch (ligne[0])
	    {
	        case '#' : break ;
		case 'n' :
		     sscanf(ligne , "n = %d",&n);
		     	break ;
		case 'k' :
		     	sscanf(ligne , "k = %d",&k);
		     	res = CreerCode(k, n);
		     	break ;
		default :
			while((ligne[j] != '\n') && (ligne[j] != '\0') && (ligne[j] != EOF)&& (i  < k ))
			{
				if (ligne[j] == '1')
				{
					
					res.mat[i][x] = 1;
					x++;
				}
				if (ligne[j] == '0')
				{	
					res.mat[i][x] = 0 ;
					x++;
				}
				j++;
			}
			i++;
			j = 0;
			x = 0 ;
			break;
	    }
	}
    }
    //AfficherCode(res);
    fclose(fichier);
    return res ;
}
	
void EcrireCode(char*dest , code cc)
{
    FILE*fichier ;
    if (NULL == dest )
	fichier = stdout ;
    else
	fichier = fopen(dest ,"w");
    if (NULL == fichier)
    {
         perror("ecrire code : ");
	 exit(1);
    }
    else
    {
	fprintf(fichier , "n = %d \n",cc.n);
	fprintf(fichier , "k = %d \n",cc.k);
        for(int i = 0 ; i < cc.k ; i++)
	{
		for(int j = 0 ; j < cc.n ; j++)
			fprintf(fichier,"%d ",cc.mat[i][j]);
                fputc('\n',fichier);
                //fputc ecrit un caractere
       }

   }
   fclose(fichier);
}


void LireFonction(char*s){
	FILE * src ;
	char * fct;
	char ligne[1024];
	
	src = fopen(s, "r");
	if(!src){
		perror("errrrrr ");
		exit(1);}
	while( fgets(ligne, 1024, src)){
		fct = tbv(ligne, 8);
		if(degre(fct, 8) <= 5)
			print(fct, 8);
	
	}
}




















