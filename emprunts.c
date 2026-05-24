#include "livres.h"

int verifierRetard(Livre livre, char role[]){
    long tempsActuel;
    tempsActuel = time(NULL);
    int limite;

    if(strcmp(role,"etudiant") == 0){
    
        limite = 120;
    }
    else{
    
        limite = 180;
    }

    if(livre.emprunte == 1 && tempsActuel - livre.dateEmprunt > limite){
    
        return 1;
    }

    return 0;
}

int compterEmprunts(Livre livres[], int nombreLivres, char utilisateur[]){

    int compte = 0;

    for(int i = 0; i < nombreLivres; i++){

        if(livres[i].emprunte == 1 && strcmp(livres[i].empruntePar, utilisateur) == 0){

            compte++;
        }
    }

    return compte;
}

void emprunterLivre(Livre livres[], int nombreLivres, char utilisateur[], char role[]){

    int limite;

    if(strcmp(role, "etudiant") == 0){

        limite = 3;
    }
    else{

        limite = 5;
    }

    int empruntsActuels = compterEmprunts(livres, nombreLivres, utilisateur);

    if(empruntsActuels >= limite){

        printf("Limite atteinte : vous ne pouvez pas emprunter plus de %d livres.\n", limite);

        return;
    }

    int id;
    printf("ID du livre : ");
    scanf("%d", &id);

    for(int i = 0; i < nombreLivres; i++){
        if(livres[i].id == id){
        
            if(livres[i].emprunte == 1){
            
                printf("Livre deja emprunte.\n");

                return;
            }

            livres[i].emprunte = 1;
            strcpy(livres[i].empruntePar, utilisateur);
            livres[i].dateEmprunt = time(NULL);
            printf("Livre emprunte. (%d/%d emprunts utilises)\n", empruntsActuels + 1, limite);

            return;
        }
    }

    printf("Livre introuvable.\n");
}

void rendreLivre(Livre livres[], int nombreLivres, char utilisateur[]){

    int id;
    printf("ID du livre : ");
    scanf("%d", &id);

    for(int i = 0; i < nombreLivres; i++){
    
        if(livres[i].id == id && strcmp(livres[i].empruntePar, utilisateur) == 0){
        
            livres[i].emprunte = 0;
            strcpy(livres[i].empruntePar, "-");
            livres[i].dateEmprunt = 0;
            printf("Livre rendu.\n");

            return;
        }
    }

    printf("Livre non trouve.\n");
}
