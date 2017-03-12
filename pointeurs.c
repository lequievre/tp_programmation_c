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
 
int main (void)
{
  int age;
  age = 32;
  printf("Valeur de la variable age = %d\n", age);
  int * unPointeur = NULL;
  printf("Valeur de 'unPointeur' = %p\n",unPointeur);
  unPointeur = &age;
  printf("Valeur de 'unPointeur' = %p\n",unPointeur);
  printf("Valeur pointee par 'unPointeur' = %d\n",*unPointeur);
  
  printf("\n\nFIN\n\n");
 
  return 0;
}
