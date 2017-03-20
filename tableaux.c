/*
 * Laurent LEQUIEVRE - Institut Pascal UMR6602 - 2017
 * laurent.lequievre@univ-bpclermont.fr
 * 
 * Exemples de creation et utilisation (passage par parametre de fonction)
 * de tableaux.
 * Un point aussi sur les pointeurs.
 * 
*/

#include <stdio.h>
#include <stdlib.h>

#define NB_ELEMENTS 3

void afficheTab(int [], int n);
void afficheTabPt(int *[], int n);
void afficheTabPt2(int **, int n);
void afficheTabPt3(int (*)[], int n);

int main()
{	
	int tab1[NB_ELEMENTS] = { 1, 2, 3 }; // On déclare et initialise un tableau de 3 entiers.
	
	printf("\n&tab1[0]=%p, &tab1[1]=%p, &tab1[2]=%p\n",&tab1[0], &tab1[1], &tab1[2]);
	// Imaginons pour la suite que : &tab1[0]=0x101, &tab1[1]=0x102, &tab1[2]=0x103
		
	int *pt;
	
	pt = tab1; // pt pointe sur le 1er element de tab1, soit tab1[0].
	
	printf("\n pt = %p, tab1 = %p \n",pt,tab1); // pt = 0x101 et tab1 = 0x101.
	// tab1 est automatiqument interprété comme un pointeur qui pointe sur l'emplacement mémoire du 1er élément du tableau.
	
	pt = tab1 + 2; // Ici on utilise l'arithmétique des pointeurs (le '2' ne veut pas dire 2 octets !!). On saute 2 'int'. pt pointe sur tab1[2].
	printf("\n pt = %p, *pt=%d \n", pt,*pt);  // pt = 0x103 et *pt=3.
	
	// L'opérateur [] est interprété comme ceci : X[Y] est equivalent à *((X) + (Y)).
	// X[Y] = n est interprété comme : *((X) + (Y)) = n
	// tab1[2] = 7 est interprété comme : *((tab1) + (2)) = 7
	
	pt[-1] = 6; // pt pointe sur tab1[2]. pt[-1] = 6 est equivalent à *((pt) + (-1)) = 6.
	// Comme pt pointe sur tab1[2], on retire 1 à pt et la valeur pointee par (pt -1) vaut maintenant '6'. Donc tab1[1] vaut maintenant '6' !
	
	printf("\n tab1[1] = %d \n",tab1[1]); // va afficher : tab1[1]=6.
	
	// Mais Attention, pt pointe toujours sur tab1[2]
	printf("\n pt=%p, *pt=%d \n",pt,*pt); // pt = 0x103 et *pt=3.
	
	int *pt1;
	pt1 = &tab1[0]; // Ici on est plus explicite, on affecte l'adresse du premier element de tab1 au pointeur pt1.
	printf("\n pt1 = %p \n",pt1); // pt1 = 0x101.
	
	int **pt2; // On déclare un pointeur de pointeur de 'int'.
	pt2 = &pt1; // Ici pt2 contient l'adresse de pt1. pt2 pointe donc sur pt1 et pt1 pointe sur tab1[0] qui contient la valeur '1'.
	
	printf("\n Valeur pointee par le contenu de pt2 = %d \n", *(*pt2)); // Valeur pointee par le contenu de pt2 = 1;
	
	afficheTab(tab1,NB_ELEMENTS); // Appel de la fonction 'afficheTab' en lui passant un tableau de int et son nb d'élements.
	
	int *tab2[NB_ELEMENTS]; // On déclare un tableau de NB_ELEMENTS pointeurs de 'int'.
	tab2[0] = &tab1[0]; // On affecte à chaque case du tableau tab2 l'adresse des cases du tableau tab1.
	tab2[1] = &tab1[1];
	tab2[2] = &tab1[2];
	
	// Imaginons pour la suite que : &tab2[0]=0x1001, &tab2[1]=0x1002, &tab2[2]=0x1003
	
	afficheTabPt(tab2,NB_ELEMENTS); // Appel de la fonction 'afficheTabPt' en lui passant 'tab2' qui est un tableau de pointeurs de int et son nb d'élements.
	
	afficheTabPt2(tab2,NB_ELEMENTS); // Appel de la fonction 'afficheTabPt2' en lui passant tab2' et son nb d'élements.
	
	int (*pt3)[NB_ELEMENTS]; // On déclare un pointeur sur un tableau de NB_ELEMENTS de 'int'. Observer les parenthèses autour de '*'.
	// ATTENTION de ne pas confondre avec : int *p3[NB_ELEMENTS] -> qui un tableau de NB_ELEMENTS de pointeurs de 'int'.
	
	pt3 = &tab1; // On affecte à pt3 qui est pointeur, l'adresse du tableau 'tab1', c'est à dire l'adresse de son 1er élément.
	printf("\n pt3 = %p \n",pt3); // pt3 = 0x101.
	
	afficheTabPt3(pt3,NB_ELEMENTS);
	
	printf("\nFIN\n");
	return EXIT_SUCCESS;	
}


/*
 * Affiche le contenu d'un tableau t passé en paramètre. 
 * La variable 'n' contient le nb d'éléments du tableau.
 * Ici 'int t[]' sera interprété comme un pointeur vers le premier élément du tableau (qui est un 'int').
 */
void afficheTab(int t[], int n)
{
	
	printf("\n t = %p \n",t); // t = 0x101.
	
	int i;
	printf("\n Tableau : ");

	for (i=0; i<n; ++i)
	{
		printf(" %d",t[i]); // Ici t[i] sera interprété comme : *((t) + (i))
	}
	printf("\n");
}


/*
 * Affiche le contenu d'un tableau t de pointeurs de 'int' passé en paramètre. 
 * La variable 'n' contient le nb d'éléments du tableau.
 * Ici 'int *t[]' sera interprété comme un pointeur vers le premier élément d'un tableau 'int *' (pointeurs de 'int').
 */
void afficheTabPt(int *t[], int n)
{
	
	printf("\n t = %p \n",t); // t = 0x1001.
	
	int i;
	printf("\n Tableau de pointeurs : ");

	for (i=0; i<n; ++i)
	{
		printf(" %d",*t[i]); // Ici *t[i] sera interprété comme : *( *((t) + (i)) )
		// *((t) + (i)) donne le contenu de la ième case du tableau (qui est un 'int *')
		// Pour obtenir la valeur pointée il faut le déréférencer soit : *( *((t) + (i)) )
	}
	printf("\n");
}


/*
 * Affiche le contenu d'un tableau t passé en paramètre sous forme de pointeur de pointeur. 
 * La variable 'n' contient le nb d'éléments du tableau.
 * Ici 'int **t' sera interprété comme un pointeur de pointeur vers un int.
 * En fait un pointeur vers le premier élément du tableau de pointeurs, qui est donc un pointeur vers un 'int'.
 */
void afficheTabPt2(int **t, int n)
{
	
	printf("\n t = %p \n",t); // t = 0x1001.
	
	int i;
	printf("\n Tableau (pointeur de pointeur) : ");

	for (i=0; i<n; ++i)
	{
		// On peut utiliser l'opérateur [] comme ceci :
		printf(" %d",*t[i]); // Ici *t[i] sera interprété comme : *( *((t) + (i)) )
		
		// On peut aussi faire de l'arithmétique de pointeur comme ceci :
		printf(" %d",*( *((t) + (i)) )); // // *((t) + (i)) donne le pointeur de la ième case du tableau, pour obtenir la valeur pointée il faut le déréférencer.
		
	}
	printf("\n");
}


/*
 * Affiche le contenu d'un tableau pointé par le pointeur t.
 * La variable 'n' contient le nb d'éléments du tableau.
 * Ici 'int (*t)[]' sera interprété comme un pointeur sur un tableau de 'int'.
 * 
 */
void afficheTabPt3(int (*t)[], int n)
{
	int i;
	printf("\n Pointeur sur tableau : ");

	for (i=0; i<n; ++i)
	{
		printf(" %d",(*t)[i]); // Ici on déréférence t avec (*t) qui nous donne accès au tableau, puis on peut utiliser l'opérateur [].
	}
	printf("\n");
}

