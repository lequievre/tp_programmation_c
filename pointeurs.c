/*
 * Laurent LEQUIEVRE - Institut Pascal UMR6602 - 2017
 * laurent.lequievre@univ-bpclermont.fr
 * 
 * Exemples de declaration et utilisation de pointeurs.
 * 
 * 
*/

#include <stdio.h>
#include <stdlib.h>


/*
 * 'donneLeDouble' multiplie par 2 la valeur pointee par le pointeur 'v' passe en parametre.
 * Un test si le pointeur 'v' vaut 'NULL' est effectue.
 * 
 */
void donneLeDouble(int *v)
{
	if (v!=NULL)
	{
		(*v)*=2; // On dereference la variable 'v' puis on la multiplie par 2.
	}
	else
	{
		// On affiche sur le 'flux standard d'erreur' ce message. On indique aussi, via les macros '__FILE__' et '__LINE__' le nom du fichier et le numero de la ligne ou se trouve le pb.
		// __FILE__ -> retourne le nom du fichier courant.
		// __LINE__ -> retourne le numero de la ligne courante.
		fprintf(stderr, "Danger : Access a un pointeur NULL sur fichier %s a la ligne %d!\n", __FILE__, __LINE__-4);
	}
}
 
int main (void)
{
  int age;
  
  age = 32;
  printf("Adresse de 'age' = %p, Valeur de 'age' = %d\n", &age, age);
  
  // Declaration d'un pointeur d'entier, on pense a initialiser le pointeur a NULL.
  int * unPointeur = NULL;
  printf("Valeur de 'unPointeur' = %p\n",unPointeur);
  
  // Appel de la fonction 'donneLeDouble' avec le pointeur 'unPointeur' en parametre. Mais ce pointeur vaut NULL !!
  donneLeDouble(unPointeur);
  
  // On affecte au pointeur 'unPointeur' l'adresse de la variable 'age'. Le pointeur 'unPointeur' pointe donc maintenant sur 'age'.
  unPointeur = &age;
  printf("Valeur de 'unPointeur' = %p\n",unPointeur);
  printf("Valeur pointee par 'unPointeur' = %d\n",*unPointeur);
  
  // Appel de la fonction 'donneLeDouble' avec le pointeur 'unPointeur' en parametre. Au retour de cette fonction, 
  // la valeur pointee par un 'unPointeur' (c'est a dire celle de 'age') sera multipliee par 2 !
  donneLeDouble(unPointeur);
  printf("Adresse de 'age' = %p, Valeur de 'age' = %d\n", &age, age);
  printf("Valeur de 'unPointeur' = %p, Valeur pointee par 'unPointeur' = %d\n", unPointeur, *unPointeur);
  
  
  printf("\n\nFIN\n\n");
 
  return 0;
}
