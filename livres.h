#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LIVRES 100

typedef struct{

    int id;
    char titre[100];
    char auteur[100];
    char categorie[100];
    int emprunte;
    char empruntePar[100];
    long dateEmprunt;

} Livre;

typedef struct{

    char nom[100];
    char motDePasse[100];
    char role[50];

} Utilisateur;


void chargerLivres(Livre livres[], int *nombreLivres);

void sauvegarderLivres(Livre livres[], int nombreLivres);

void afficherLivres(Livre livres[], int nombreLivres);

void ajouterLivre(Livre livres[], int *nombreLivres, char role[]);

void trierParTitre(Livre livres[], int nombreLivres);

void trierParAuteur(Livre livres[], int nombreLivres);

int verifierRetard(Livre livre, char role[]);

void emprunterLivre(Livre livres[], int nombreLivres, char utilisateur[], char role[]);

void rendreLivre(Livre livres[], int nombreLivres, char utilisateur[]);

void creerCompte();

int connexion(char nom[], char role[]);
