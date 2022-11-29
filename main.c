#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "diffMonth.h"

int main(int argc, const char * argv[]) {

    /*Déclaration de mes variables*/
    date dateDeDepart,dateDeFin;
    int programmeEnCours = 1;
    char date1[20];
    char date2[20];

    /*Tant que programmeEnCours est vrai*/
    while(programmeEnCours){

        /*Attente d'une réponse de l'utilisateur pour la date 1*/
        printf("Entrer une date (format dd/mm/yyyy) : \n");
        scanf("%s",date1);

        /*Attente d'une réponse de l'utilisateur pour la date 2*/
        printf("Entrer une date (format dd/mm/yyyy) : \n");
        scanf("%s",date2);

        /*Envoie des infos entrée par l'utilisateur à ma fonction sepMonth*/
        /*On envoie la première date puis on vient la stocker dans ma structure dateDeDepart*/
        dateDeDepart = sepMonth(date1);

        /*On envoie la deuxième date puis on vient la stocker dans ma structure dateDeFin*/
        dateDeFin = sepMonth(date2);

        /*J'affiche mes variables date*/
        printf("Affichage de la premiere date : \njour : %d\nmois : %d\nannee : %d\n",dateDeDepart.jour,dateDeDepart.mois,dateDeDepart.annee);
        printf("Affichage de la deuxieme date : \njour : %d\nmois : %d\nannee : %d\n",dateDeFin.jour,dateDeFin.mois,dateDeFin.annee);
        
        diffMonth(dateDeDepart,dateDeFin);
        
        /*Continuer ou quitter le programme*/
        printf("Taper 0 pour quitter ou 1 pour continuer le programme : ");
        scanf("%d",&programmeEnCours);

    }
}