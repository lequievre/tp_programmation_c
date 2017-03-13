/*
 * Laurent LEQUIEVRE - Institut Pascal UMR6602 - 2017
 * laurent.lequievre@univ-bpclermont.fr
 * 
 * Exemples de declaration et utilisation de chaines de caracteres.
 * 
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (void)
{
	// La représentation interne d'une chaîne de caractères est terminée par le symbole '\0' (NULL). 
	// Ainsi, pour un texte de n caractères, nous devons prévoir n+1 octets.
	char chaine1[] = {'H','e','l','l','o','\0'}; // Ici on initialise caractere par caractere et on pense a mettre le '\0' a la fin !
	char chaine2[] = "Hello"; // Ici on utilise [] qui ajoute automatiquement le '\0' a la fin ! Il y a 6 octets en tout ! La chaine "Hello" est une chaine constante.
	
	// Attention: Il est interdit d'affecter une chaine de caracteres en dehors de son initialisation.
	// char chaine[6];
	// chaine = "Test"; --> Ici c'est INTERDIT !

	printf("\nchaine1=%s, chaine2=%s\n",chaine1,chaine2);
	printf("\ntaille de chaine1=%lu octets, chaine2=%lu octets\n",sizeof(chaine1),sizeof(chaine2));
	
	char chaine3[5] = "Hello"; // Ici il manque 1 octet pour le '\0', cela donnera un comportement aleatoire a l'execution.
    printf("\nchaine3=%s\n",chaine3);
    
    char chaine4[10] = "Hello"; // Ici plus d'octets que necessaire. 6 octets sur 10 sont utilises !
    printf("\nchaine4=%s, taille de chaine4=%lu\n",chaine4,sizeof(chaine4));
    
    // ATTENTION
    char c1 = 'A'; // est codé sur 1 octet.
    char c2[] = "A";// est codé sur 2 octets.
    char c3[] = ""; // une chaine vide codee sur 1 octet.
    printf("\ntaille de c1=%lu octets, c2=%lu octets, c3=%lu octets\n",sizeof(c1),sizeof(c2),sizeof(c3));
    
    // Une chaine est un tableau de caracteres.
    int i=0;
    char c = chaine4[i];
    while (c) // le 6ieme caractere de 'chaine4' sera '\0' qui vaut 0.
    {
		printf("\ni=%d -> c=%c",i,c);
		++i;
		c = chaine4[i];
	}
	
	// On peut aussi definir des tableaux a plusieurs dimensions.
	char jours[7][9] = { "lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche"};
	printf("\nle deuxieme jour de la semaine est \"%s\"\n",jours[1]);
	printf("\nle troisieme caractere du quatrieme jour de la semaine est \'%c\'\n",jours[3][2]);

    // ********************************************************
    // Utilisation des fonctions contenues dans 'string.h'
    // ********************************************************
    
    // 'srtlen' : Taille d'une chaine de caracteres sans compter le '\0'.
    // size_t strlen(const char* chaine);
    printf("\nNb de caracateres de chaine4 = %zu\n",strlen(chaine4));
    
    // 'strcpy' : Copie d'une chaine dans une autre (incluant le '\0').
    // char* strcpy(char* copieDeLaChaine, const char* chaineACopier);
    char chaineCopie[100] = {'\0'};
    strcpy(chaineCopie,chaine4);
    printf("\nNb de caracateres de chaineCopie = %zu\n",strlen(chaineCopie));
    printf("\nchaineCopie = %s\n",chaineCopie);
    
    // 'strcat' : Concatene 2 chaines de caracteres.
    // char* strcat(char* chaine1, const char* chaine2);
    char chaine5[100] = "Salut ", chaine6[] = "les informaticiens !";
    strcat(chaine5, chaine6); // On concatène chaine6 dans chaine5.
    printf("\nla concatenation se trouve dans chaine5 = \"%s\", chaine6 = \"%s\"\n", chaine5, chaine6);
    
    // 'strcmp' : comparer 2 chaines de caracteres.
    // int strcmp(const char* chaine1, const char* chaine2);
    // retourne : 0 si les chaînes sont identiques, une autre valeur (positive ou négative) si les chaînes sont différentes.
    char chaine7[] = "Coucou", chaine8[] = "Coucou";
    if (strcmp(chaine7, chaine8) == 0) // Si chaînes identiques
    {
        printf("Les chaines 'chaine7' et 'chaine8' sont identiques\n");
    }
    else
    {
        printf("Les chaines 'chaine7' et 'chaine8' sont differentes\n");
    }
    
    // 'strchr' : rechercher la premiere occurence d'un caractere.
    // char* strchr(const char* chaine, int caractereARechercher);
    // La fonction renvoie un pointeur vers le premier caractère qu'elle a trouvé, NULL si elle n'a rien trouvé.
    char chaine9[] = "Une chaine de test", *suiteChaine = NULL;

    suiteChaine = strchr(chaine9, 'e');

    if (suiteChaine != NULL) // Si on a trouvé le caractere
    {
        printf("\nVoici la fin de la chaine a partir du premier \'e\' : \"%s\"", suiteChaine);
    }
    
    // variante 'strrchr' : recherche la derniere occurence d'un caractere.
    // char *strrchr(const char *str, int c)
    suiteChaine = strrchr(chaine9, 'e');

    if (suiteChaine != NULL) // Si on a trouvé le caractere
    {
        printf("\nVoici la fin de la chaine a partir du dernier \'e\' : \"%s\"", suiteChaine);
    }
    
    // 'strstr' : rechercher une chaîne dans une autre.
    // char* strstr(const char* chaine, const char* chaineARechercher);
    
    // On cherche la première occurrence de "test" dans "Texte de test" :

    suiteChaine = strstr(chaine9, "test");

    if (suiteChaine != NULL)
    {
        printf("\nPremiere occurrence de \"test\" dans 'chaine9' : \"%s\"\n", suiteChaine);
    }
    
    // 'sprintf' : écrire dans une chaîne (fait partie de 'stdio.h')
    char chaine10[100];
    int age = 15;

    // On écrit "Tu as 15 ans" dans chaine10
    sprintf(chaine10, "Tu as %d ans !", age);

    printf("'chaine10' = \"%s\"", chaine10);
    
    // ************************************************************************
    // Utilisation des fonctions de conversion chaine -> nombre dans 'stdib.h'
    // ************************************************************************
    
    // Règles générales pour la conversion :
    // - Les espaces au début d'une chaîne sont ignorés
    // - Il n'y a pas de contrôle du domaine de la cible
    // - La conversion s'arrête au premier caractère non convertible
    // - Pour une chaîne non convertible, les fonctions retournent zéro
    
    // 'atoi' : conversion d'une chaine de caracteres en un entier.
    // int atoi(const char *nptr);
    
    char chaine11[100] = "645";
	printf("\nLa conversion en int de 'chaine11' = %d",atoi(chaine11));
	
	strcpy(chaine11,"     56  ");
	printf("\nLa conversion en int de 'chaine11' = %d",atoi(chaine11));
	
	strcpy(chaine11,"     567b78  ");
	printf("\nLa conversion en int de 'chaine11' = %d",atoi(chaine11));
	
	strcpy(chaine11,"     toto567b78  ");
	printf("\nLa conversion en int de 'chaine11' = %d",atoi(chaine11));
	
	// 'atof' : conversion d'une chaine de caracteres en un double
	// double atof(const char *nptr);
	
	strcpy(chaine11,"     123.789  ");
	printf("\nLa conversion en double de 'chaine11' = %f",atof(chaine11));
    
	printf("\n\nFIN\n\n");

	return 0;
}
