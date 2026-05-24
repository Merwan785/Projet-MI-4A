CY BIBLIOTECH - README
======================

CY Bibliotech est un système de gestion de bibliothèque développé en C. Il permet à des utilisateurs (étudiants et professeurs) de consulter un catalogue de livres, 
d'emprunter et de rendre des ouvrages, et pour les professeurs, d'en ajouter de nouveaux.
Le projet est composé de plusieurs fichiers sources : main.c contient le point d'entrée du programme, livres.c gère l'affichage, l'ajout et la sauvegarde des livres,
emprunts.c s'occupe des emprunts et des retours, tris.c regroupe les fonctions de tri, et utilisateurs.c gère la connexion et la création de compte. Les données sont 
stockées dans deux fichiers texte : livres.txt pour le catalogue et utilisateurs.txt pour les comptes.


COMPILATION :

La méthode recommandée est d'utiliser le Makefile fourni. Il suffit d'exécuter la commande "make" dans le dossier du projet pour compiler tous les fichiers et générer
l'exécutable "exec1". Pour recompiler depuis zéro, on peut enchaîner "make clean" puis "make".
Une fois compilé, le programme se lance avec la commande : ./exec1


UTILISATION :

Au démarrage, le programme propose de se connecter avec un compte existant ou d'en créer un nouveau. Lors de la création d'un compte, il faut choisir un nom, un mot de
passe et un rôle parmi "etudiant" ou "professeur".
Une fois connecté, un menu permet d'afficher les livres, de les trier par titre, par auteur ou par ID, d'emprunter ou de rendre un livre, et pour les professeurs uniquement,
d'en ajouter de nouveaux. Les emprunts sont sauvegardés automatiquement après chaque action. Un étudiant peut emprunter jusqu'à 3 livres simultanément, un professeur jusqu'à 5.

COMPTES DE TEST :

Plusieurs comptes sont disponibles par défaut pour tester le programme. Du côté étudiants : mourad (mot de passe : radmou), merwan (wanmer) et zakaria (zak123).
Du côté professeurs : eva (meilleureprof) et romuald (azerty).
