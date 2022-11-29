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

int nombreDeJourDansUnMois(date moisSource){

    /*Déclaration de mes variables*/
    int listeMois_31[7] = {1,3,5,7,8,10,12};
    int listeMois_30[4] = {4,6,9,11};
    int listeMois_28_29[2] = {2};

    /*Je regarde si moisSource fait partie des mois contenant 31 jours*/
    for(int i = 0; i < 6;i++){
        if(moisSource.mois == listeMois_31[i]){
            printf("31");
        }
    }

    /*Je regarde si moisSource fait partie des mois contenant 30 jours*/
    for(int i = 0; i < 3;i++){
        if(moisSource.mois == listeMois_30[i]){
            printf("30");
        }
    }

    /*Je regarde si moisSource fait partie des mois contenant 28/29 jours*/
    for(int i = 0; i < 1;i++){
        if(moisSource.mois == listeMois_28_29[i]){
            printf("28"); 
        }
    }

    return 0;
}


/*Fonction final permettant de calculer la différence en mois entre deux dates*/
int diffMonth(date dateLaPlusAncienne,date dateLaPlusRecente){
    
    /*Déclaration de mes variables*/
    int annee;
    int mois;
    int jour;
    
    annee = dateLaPlusAncienne.annee - dateLaPlusRecente.annee;
    mois = dateLaPlusAncienne.mois - dateLaPlusRecente.mois;

    nombreDeJourDansUnMois(dateLaPlusAncienne);
    nombreDeJourDansUnMois(dateLaPlusRecente);

}

/*Déclaration de ma fonction putInOrder*/
/*Permet de comparer deux dates et voir qui est la plus ancienne des deux*/

void putInOrder(date dateDeDebut,date dateDeFin){

    /*On vérifie quelle date est la plus ancienne*/
    /*On compare les années*/
    if(dateDeDebut.annee < dateDeFin.annee){
        diffMonth(dateDeDebut,dateDeFin);
    }
    if(dateDeDebut.annee > dateDeFin.annee){
        diffMonth(dateDeFin,dateDeDebut);
    }
    /*Si les années sont identiques*/
    if(dateDeDebut.annee == dateDeFin.annee){
        /*Alors on passe à la comparaison des mois*/
        if(dateDeDebut.mois < dateDeFin.mois){
            diffMonth(dateDeDebut,dateDeFin);
        }
        if(dateDeDebut.mois > dateDeFin.mois){
            diffMonth(dateDeFin,dateDeDebut);
        }
        /*Si les mois sont identiques on compare les jours*/
        if(dateDeDebut.mois == dateDeFin.mois){
            if(dateDeDebut.jour < dateDeFin.jour){
                diffMonth(dateDeDebut,dateDeFin);
            }
            if(dateDeDebut.jour > dateDeFin.jour){
                diffMonth(dateDeFin,dateDeDebut);
            }
            /*Si les jours sont égaux alors les deux dates sont identiques*/
            if(dateDeDebut.jour == dateDeFin.jour){
                printf("Les deux dates sont identiques!\n");
            }
        }
    }
 
}



