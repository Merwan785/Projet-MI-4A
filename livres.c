#include "livres.h"

void chargerLivres(Livre livres[], int *nombreLivres){

    FILE *fichier;

    fichier = fopen("livres.txt", "r");
    *nombreLivres = 0;
    if(fichier == NULL){
    
        return;
    }

    while(fscanf(fichier, "%d;%99[^;];%99[^;];%99[^;];%d;%99[^;];%ld\n",
                 &livres[*nombreLivres].id,
                 livres[*nombreLivres].titre,
                 livres[*nombreLivres].auteur,
                 livres[*nombreLivres].categorie,
                 &livres[*nombreLivres].emprunte,
                 livres[*nombreLivres].empruntePar,
                 &livres[*nombreLivres].dateEmprunt) == 7)
    {
        (*nombreLivres)++;
    }

    fclose(fichier);
}

void sauvegarderLivres(Livre livres[], int nombreLivres){

    FILE *fichier;
    
    fichier = fopen("livres.txt", "w");

    for(int i = 0; i < nombreLivres; i++){
    
        fprintf(fichier, "%d;%s;%s;%s;%d;%s;%ld\n",
                livres[i].id,
                livres[i].titre,
                livres[i].auteur,
                livres[i].categorie,
                livres[i].emprunte,
                livres[i].empruntePar,
                livres[i].dateEmprunt);
    }

    fclose(fichier);
}

void afficherLivres(Livre livres[], int nombreLivres){ 

    printf("\n===== LIVRES =====\n");

    for(int i = 0; i < nombreLivres; i++){
   
        printf("\nID : %d\n", livres[i].id);
        printf("Titre : %s\n", livres[i].titre);
        printf("Auteur : %s\n", livres[i].auteur);
        printf("Categorie : %s\n", livres[i].categorie);

        if(livres[i].emprunte == 1){
        
            printf("Emprunte par : %s\n", livres[i].empruntePar);
        }
        else{
        
            printf("Disponible\n");
        }
    }
}

int idExiste(Livre livres[], int nombreLivres, int id){

    for(int i = 0; i < nombreLivres; i++){

        if(livres[i].id == id){

            return 1;
        }
    }

    return 0;
}

void ajouterLivre(Livre livres[], int *nombreLivres, char role[]){

    if(strcmp(role, "professeur") != 0){
   
        printf("Acces refuse.\n");
        
        return;
    }

    Livre nouveauLivre;

    printf("ID : ");
    scanf("%d", &nouveauLivre.id);

    while(idExiste(livres, *nombreLivres, nouveauLivre.id)){

        printf("Cet ID existe deja. Entrez un autre ID : ");
        scanf("%d", &nouveauLivre.id);
    }

    printf("Titre : ");
    scanf(" %[^\n]", nouveauLivre.titre);

    printf("Auteur : ");
    scanf(" %[^\n]", nouveauLivre.auteur);

    printf("Categorie : ");
    scanf(" %[^\n]", nouveauLivre.categorie);

    nouveauLivre.emprunte = 0;
    strcpy(nouveauLivre.empruntePar, "-");
    nouveauLivre.dateEmprunt = 0;
    livres[*nombreLivres] = nouveauLivre;
    (*nombreLivres)++;

    printf("Livre ajoute.\n");
}
