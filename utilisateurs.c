#include "livres.h"

void creerCompte(){

    FILE *fichier;

    fichier = fopen("utilisateurs.txt", "a");

    if(fichier == NULL){
    
        printf("Erreur fichier.\n");
        return;
    }

    Utilisateur u;

    printf("Nom : ");
    scanf("%s", u.nom);

    printf("Mot de passe : ");
    scanf("%s", u.motDePasse);

    printf("Role (etudiant/professeur) : ");
    scanf("%s", u.role);

    while(strcmp(u.role, "etudiant") != 0 && strcmp(u.role, "professeur") != 0){

        printf("Role invalide. Choisissez un autre role (etudiant/professeur) : ");
        scanf("%s", u.role);
    }

    fprintf(fichier, "%s %s %s\n", u.nom, u.motDePasse, u.role);

    fclose(fichier);

    printf("Compte cree.\n");
}

int connexion(char nom[], char role[]){

    FILE *fichier;

    fichier = fopen("utilisateurs.txt", "r");

    if(fichier == NULL){
    
        return 0;
    }

    char nomTemp[100];
    char mdpTemp[100];
    char nomFichier[100];
    char mdpFichier[100];
    char roleFichier[100];

    printf("Nom : ");
    scanf("%s", nomTemp);

    printf("Mot de passe : ");
    scanf("%s", mdpTemp);

    while(fscanf(fichier, "%s %s %s", nomFichier, mdpFichier, roleFichier) != EOF){
    
        if(strcmp(nomTemp, nomFichier) == 0 && strcmp(mdpTemp, mdpFichier) == 0){
        
            strcpy(nom, nomFichier);
            strcpy(role, roleFichier);
            fclose(fichier);

            return 1;
        }
    }

    fclose(fichier);

    return 0;
}
