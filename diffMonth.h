#ifndef diffMonth_h
#define diffMonth_h

/*Initialisation de ma structure date*/
    typedef struct date date;
        struct date{
            int jour;
            int mois;
            int annee;
        };

/* Mes fonctions */
int nombreDeJourDansUnMois(date moisSource);
void putInOrder(date dateDeDebut,date dateDeFin);
void diffMonth(date dateLaPlusAncienne,date dateLaPlusRecente);
date sepMonth(char *date);


#endif 