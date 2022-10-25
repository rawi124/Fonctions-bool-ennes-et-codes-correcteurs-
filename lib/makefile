libcodage.a : code.o poids.o RM.o inout.o decodage.o degre.o tbv.o anf.o
	ar crs libcodage.a code.o poids.o RM.o inout.o decodage.o degre.o tbv.o anf.o

code.o: code.c 
	gcc -c -g -Wall code.c
	
poids.o: poids.c 
	gcc -c -g -Wall poids.c
RM.o: RM.c 
	gcc -c -g -Wall RM.c 
	
inout.o : inout.c
	gcc -c -g -Wall inout.c

decodage.o : decodage.c
	gcc -c -g -Wall decodage.c
	
anf.o: anf.c 
	gcc -c -g -Wall anf.c
	
degre.o: degre.c 
	gcc -c -g -Wall degre.c
	
tbv.o: tbv.c 
	gcc -c -g -Wall tbv.c
