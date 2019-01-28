/*
Laurent LEQUIEVRE
Exemple simple d'utilisation de la fonction fgets et sscanf
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOUR_MOIS_ANNEE 100

int main()
{

    printf("saisir une date sous la forme : Jour Mois(en lettres) Annee\n");
    char jour_mois_annee[MAX_JOUR_MOIS_ANNEE];
    int jour = 0;
    char mois[MAX_JOUR_MOIS_ANNEE/2] = {'\0'};
    int annee = 0;

    fgets(jour_mois_annee,MAX_JOUR_MOIS_ANNEE,stdin);

    sscanf(jour_mois_annee,"%d %s %d", &jour, mois, &annee);
    printf("\njour = %d, mois = \"%s\", annee = %d\n", jour, mois, annee);

    return 0;
}
