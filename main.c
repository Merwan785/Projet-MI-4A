
#include "livres.h"

void chargerLivres(Livre livres[], int *nombreLivres);

int main(){

    Livre livres[MAX_LIVRES];
    int nombreLivres = 0;
    chargerLivres(livres, &nombreLivres);
    char utilisateur[100];
    char role[100];
    int choix;

    printf("===== CY BIBLIOTECH =====\n");
    printf("1. Connexion\n");
    printf("2. Creer compte\n");

    while(scanf("%d", &choix) != 1 || (choix != 1 && choix != 2)){

        while(getchar() != '\n');
        printf("Choix invalide. Entrez 1 ou 2 : ");
    }

    if(choix == 2){

        creerCompte();
    }

    if(connexion(utilisateur, role) == 0){

        printf("Connexion refusee.\n");

        return 0;
    }

    int programme = 1;

    while(programme == 1){

        printf("\n===== MENU =====\n");
        printf("1. Afficher livres\n");
        printf("2. Trier par titre\n");
        printf("3. Trier par auteur\n");
        printf("4. Emprunter livre\n");
        printf("5. Rendre livre\n");
        printf("6. Ajouter livre\n");
        printf("0. Quitter\n");

        while(scanf("%d", &choix) != 1 || choix < 0 || choix > 6){

            while(getchar() != '\n');
            printf("Choix invalide. Entrez un numero entre 0 et 6 : ");
        }

        switch(choix){
            case 1:

                afficherLivres(livres, nombreLivres);

                break;

            case 2:

                trierParTitre(livres, nombreLivres);
                afficherLivres(livres, nombreLivres);

                break;

            case 3:

                trierParAuteur(livres, nombreLivres);
                afficherLivres(livres, nombreLivres);

                break;

            case 4:

                emprunterLivre(livres, nombreLivres, utilisateur, role);
                sauvegarderLivres(livres, nombreLivres);

                break;

            case 5:

                rendreLivre(livres, nombreLivres, utilisateur);
                sauvegarderLivres(livres, nombreLivres);

                break;

            case 6:

                ajouterLivre(livres, &nombreLivres, role);
                sauvegarderLivres(livres, nombreLivres);

                break;

            case 0:

                programme = 0;

                break;

            default:

                printf("Choix invalide.\n");
        }
    }

    return 0;
}
