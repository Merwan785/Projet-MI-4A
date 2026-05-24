
#include "livres.h"

void trierParTitre(Livre livres[], int nombreLivres){

    Livre temporaire;

    for(int i = 0; i < nombreLivres - 1; i++){
    
        for(int j = 0; j < nombreLivres - i - 1; j++){
        
            if(strcmp(livres[j].titre, livres[j + 1].titre) > 0){
            
                temporaire = livres[j];
                livres[j] = livres[j + 1];
                livres[j + 1] = temporaire;
            }
        }
    }
}

void trierParAuteur(Livre livres[], int nombreLivres){

    Livre temporaire;
    
    for(int i = 0; i < nombreLivres - 1; i++){
    
        for(int j = 0; j < nombreLivres - i - 1; j++){
        
            if(strcmp(livres[j].auteur, livres[j + 1].auteur) > 0){
            
                temporaire = livres[j];
                livres[j] = livres[j + 1];
                livres[j + 1] = temporaire;
            }
        }
    }
}