all : exec1

main.o : main.c livres.h
	gcc -o main.o -c main.c
	
livres.o : livres.c livres.h
	gcc -o livres.o -c livres.c	
	
emprunts.o : emprunts.c livres.h
	gcc -c emprunts.c -o emprunts.o
	
tris.o : tris.c livres.h
	gcc -o tris.o -c tris.c
	
utilisateur.o : utilisateurs.c livres.h
	gcc -c utilisateurs.c  -o utilisateurs.o
	

exec1 : main.o livres.o emprunts.o tris.o utilisateurs.o
	gcc  main.o livres.o emprunts.o tris.o utilisateurs.o -o exec1
	
	
