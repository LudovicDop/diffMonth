#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "diffMonth.h"

/*Déclaration de ma fonction sepMonth*/
/*Permet de recevoir des dates au format char puis des les retourner dans la structure date (int)*/
date sepMonth(char *dateUti){

    /*Déclaration de mes variables*/
    date dateDeDepart;
    char dateAuFormatChar[20];
    const char *separateur;
    char *strToken;
    int buffer;
    int i = 0;
    /*Initialisation de mes variables*/
    strToken = malloc(sizeof(100));
    separateur = malloc(sizeof(2));
    separateur = "/";

        /*Traitement de la date dateUti entrée par l'utilisateur de la fonction*/
        strcpy(dateAuFormatChar,dateUti);

        /*Séparation du char dateAuFormatChar en trois parties jour, mois & annee*/
        /*On demande le premier tocken*/
        strToken = strtok(dateAuFormatChar,separateur);

        while(strToken != NULL){

            /*Je convertis strToken en un int stocké dans buffer*/
            sscanf(strToken,"%d",&buffer);

            /*J'intègre la date fragmentée stockée dans buffer dans la structure date*/
            switch (i)
            {
            case 0:
                dateDeDepart.jour = buffer;
                break;

            case 1:
                dateDeDepart.mois = buffer;
                break;

            case 2:
                dateDeDepart.annee = buffer;
                break;  

            default:
                EXIT_FAILURE;
                break;
            }

            /*On demande le tocken suivant*/
            strToken = strtok(NULL,separateur);

            /*J'incrémente i pour affecter une autre variable de ma structure*/
            i++;
        }

        /*Je libère la mémoire allouée à mes variables*/
        free(strToken);

    /*Retourne 0 si aucune erreur n'est constaté durant le lancement du programme*/
    return dateDeDepart;
}

/*Je déclare mes define*/
#define dateDebut printf("La date de debut est plus ancienne.\n");
#define dateFin printf("La date de fin est plus ancienne.\n");

/*Déclaration de ma fonction diffMonth*/
/*Permet de comparer deux dates et voir qui est la plus ancienne des deux*/

int diffMonth(date dateDeDebut,date dateDeFin){

    /*On vérifie quelle date est la plus ancienne*/
    /*On compare les années*/
    if(dateDeDebut.annee < dateDeFin.annee){
        dateDebut
    }
    if(dateDeDebut.annee > dateDeFin.annee){
        dateFin
    }
    /*Si les années sont identiques*/
    if(dateDeDebut.annee == dateDeFin.annee){
        /*Alors on passe à la comparaison des mois*/
        if(dateDeDebut.mois < dateDeFin.mois){
            dateDebut
        }
        if(dateDeDebut.mois > dateDeFin.mois){
            dateFin
        }
        /*Si les mois sont identiques on compare les jours*/
        if(dateDeDebut.mois == dateDeFin.mois){
            if(dateDeDebut.jour < dateDeFin.jour){
                dateDebut
            }
            if(dateDeDebut.jour > dateDeFin.jour){
                dateFin
            }
            /*Si les jours sont égaux alors les deux dates sont identiques*/
            if(dateDeDebut.jour == dateDeFin.jour){
                printf("Les deux dates sont identiques!\n");
            }
        }
    }
    return 0;
}