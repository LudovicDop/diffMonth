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
int diffMonth(date dateDeDebut,date dateDeFin);
date sepMonth(char *date);


#endif 