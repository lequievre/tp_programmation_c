/*
 * Laurent LEQUIEVRE - Institut Pascal UMR6602 - 2017
 * laurent.lequievre@univ-bpclermont.fr
 * 
 * Exemple de l'utilisation de la fonction qsort du langage c sur un tableau d'entiers.
 * 
 * prototype de la fonction qort() : void qsort (void *tableau, size_t nb_elem, size_t taille_elem, int (*compare) (void const *a, void const *b));
 * 
*/

#include <stdio.h>
#include <stdlib.h>
 
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
 * Fonction utilisateur de comparaison fournie a qsort(). (Tri croissant d'entiers).
 * void * : est un pointeur generique. Un  pointeur  générique  accepte  de  prendre  pour  valeur  l'adresse  de  n'importe  quel  objet,  quel  
qu'en soit le type.
 * Attention il ne connait pas la taille de l'espace memoire des objets vers lequel il pointe. C'est la raison pour laquelle on ne peut le dereferencer.
 */
int compareTabCroissant(void const *a, void const *b)
{
   // On sait que cette fonction va comparer des int, donc des pointeurs vers des int.
   // La fonction de comparaison ne doit en aucun cas modifier les elements compares, c'est la raison pour laquelle on a des pointeurs vers des valeurs constantes.
   int const *pa = a;
   int const *pb = b;
 
   // Evaluer et retourner l'etat de l'evaluation.
   
   // 0 si le critère de a est égal au critère de b
   // < 0 si le critère de a est inférieur au critère de b
   // > 0 si le critère de a est supérieur au critère de b

   return *pa - *pb;
}
 
int main (void)
{
   // Declaration et initialisation du tableau a trier.
   int tab[] = { 4, 6, -3, 4, 7 };
   
    // Calcul du nb d'elements du tableau.
	int size_of_tab = sizeof(tab)/sizeof(*tab);
 
   // Affichage du tableau non trie.
   printf("\n\nTableau non trie :");
   afficheTab(tab, size_of_tab);
 
   // Tri du tableau via la fonction qsort().
   qsort(tab, size_of_tab, sizeof(*tab), compareTabCroissant);
 
   // Affichage du tableau trie
   printf("\n\nTableau trie :");
   afficheTab(tab, size_of_tab);
   
   printf("\n\nFIN\n\n");
 
   return 0;
}
