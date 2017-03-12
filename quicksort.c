/*
 * Laurent LEQUIEVRE - Institut Pascal UMR6602 - 2017
 * laurent.lequievre@univ-bpclermont.fr
 * 
 * Quick Sort d'un tableau d'entiers.
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 5
#define MAX 40
#define MAX_SIZE_TAB 10

void triTab(int[], int);
void triSousTab(int[], int, int);
int rangerTab(int[], int, int);
void initialiseTab(int[], int);
void afficheTab(int[], int);

void main() 
{
  // Initialisation du tirage aleatoire.
  srand(time(NULL));

  // Declaration d'un tableau d'entiers de taille MAX_SIZE_TAB.
  int tab[MAX_SIZE_TAB];

  // Calcul le nb d'elements du tableau (pour le fun car connu par MAX_SIZE_TAB).
  int size_of_tab = sizeof(tab)/sizeof(*tab);

  // Initialise le tableau avec des valeurs aleatoires
  initialiseTab(tab, size_of_tab);

  // Affiche le tableau non trie
  printf("\n\nTableau non trie :");
  afficheTab(tab, size_of_tab);

  // Effectue le tri du tableau
  triTab(tab,size_of_tab);

  // Affiche le tableau trie
  printf("\n\nTableau trie :");
  afficheTab(tab, size_of_tab);

  printf("\n\nFIN\n\n");
}

/*
 * Initialise le tableau tab de taille size
 * avec des valeurs aleatoires comprises entre MIN et MAX.
 */
void initialiseTab(int tab[], int size)
{
  int i;
  
  for (i=0; i<size; i++)
    tab[i] = rand()%(MAX-MIN+1)+MIN;
}

/*
 * Affiche les valeurs du tableau tab de taille size.
 */
void afficheTab(int tab[], int size)
{
  int i;
  
  for (i=0; i<size; i++)
    printf(" %d ",tab[i]);
}

/*
 * Tri un tableau tab de taille size.
 */
void triTab(int tab[], int size)
{
    triSousTab(tab,0,size-1);
}


/*
 * Tri une sous partie d'un tableau tab
 * compris entre les indices left et right.
 */ 
void triSousTab(int tab[], int left, int right)
{
   int j;

   if( left < right ) 
   {
       j = rangerTab(tab, left, right); // Range le sous tableau d'indices [left,right] en fonction d'un pivot. L'indice du pivot est retourne.
       triSousTab(tab, left, j-1); // Relance le tri sur la partie du gauche du sous tableau (sans le pivot).
       triSousTab(tab, j+1, right); // Relance le tri sur la partie droite du sous tableau (sans le pivot).
   }
   
}

/*
 * Range les elements du tableau tab entre les indices [left,right] (un sous tableau) en fonction d'un pivot.
 * Le pivot est arbitrairement pris comme l'element a l'indice left (premier element du sous tableau).
 * On va parcourir le sous tableau de gauche à droite en icrementant left, mais aussi de droite a gauche en decrementant right.
 */
int rangerTab(int tab[], int left, int right) {
   
   int pivot, i, j, t;
   
   pivot = tab[left]; // Le pivot est l'element de tab d'indice left.
   i = left; j = right+1; // On utilise une boucle de type 'do ... while', on entre forcement une fois dans la boucle, on pense donc a incrementer 'right' de 1.
   // L'indice i doit traiter tous les elements plus petit que le pivot (ceux a gauche du pivot).
   // L'indice j doit traiter tous les elements plus grand que le pivot (ceux a droite du pivot). 
   
   while(1)
   {
   	do ++i; while( tab[i] <= pivot && i <= right );
   	do --j; while( tab[j] > pivot );
   	if( i >= j ) break; // Les indices se croisent on a donc balaye tout le tableau.
   	t = tab[i]; tab[i] = tab[j]; tab[j] = t; // A l'indice i il y a un element plus gand que le pivot, a l'indice j un element plus petit que le pivot, il faut donc les inverser.
   }
   
   t = tab[left]; tab[left] = tab[j]; tab[j] = t; // On pense a inverser le pivot (qui est au debut du sous tableau) avec le dernier plus petit element trouve.
   
   return j; // Retourne le nouvel indice du pivot.
}

