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
	
	afficheTab(tab1,NB_ELEMENTS); // Appel de la fonction 'afficheTab' en lui passant un tableau de int et son nb d'élements.
	
	printf("\nFIN\n");
	return EXIT_SUCCESS;	
}


/*
 * Affiche le contenu d'un tableau t passé en paramètre. 
 * La variable 'n' contient le nb d'éléments du tableau.
 * Ici t[] sera interprété comme un pointeur vers le premier élément du tableau (qui est un 'int').
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

