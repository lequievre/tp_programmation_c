/*
 * Laurent LEQUIEVRE - Institut Pascal UMR6602 - 2017
 * laurent.lequievre@univ-bpclermont.fr
 * 
 * Exemple de creation et utilisation d'une matrice d'entiers crees dynamiquement.
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 5
#define MAX 40

/*
 * Creation dynamique d'une matrice de 'nblignes' lignes et 'nbcolonnes' colonnes.
 * Prototype de 'malloc' -> void * malloc ( size_t t );
 * 'malloc' permet de réserver (si possible) un bloc de taille t (en bytes) et renvoie un pointeur vers l'adresse du bloc
 * alloué s'il y a suffisament de mémoire disponible, la valeur NULL en cas d'erreur.
 * 
 */
int ** creerMat(int nblignes, int nbcolonnes)
{
  int ** mat = (int **)malloc(nblignes * sizeof(int *));
  if (mat == NULL)
  {
	  fprintf(stderr, "Allocation matrice impossible sur fichier %s a la ligne %d!\n", __FILE__, __LINE__-2);
	  exit(EXIT_FAILURE);
  }
  int i;
  for (i=0;i<nblignes;i++)
  {
	mat[i] = (int *)malloc(nbcolonnes * sizeof(int));
  }

  return mat;
}

/*
 * Liberation d'une matrice dynamique de 'nblignes' lignes.
 */
void libererMat(int **mat, int nblignes)
{
  int i;
  for (i=0; i<nblignes; i++)
  {
    free(mat[i]);
  }
  free(mat);
}

/*
 * Initialisation d'une matrice dynamique de 'nblignes' lignes et 'nbcolonnes' colonnes
 * avec des nombres aleatoires.
 */
void initMat(int **mat, int nblignes, int nbcolonnes)
{
   int i,j;
   for (i=0; i<nblignes; i++)
   {
     for (j=0; j<nbcolonnes; j++)
       mat[i][j] = rand()%(MAX-MIN+1)+MIN;
   }
}


/*
 * Affichage d'une matrice dynamique de 'nblignes' lignes et 'nbcolonnes' colonnes
 */
void afficheMat(int **mat, int nblignes, int nbcolonnes)
{
   int i,j;
   for (i=0; i<nblignes; i++)
   {
     for (j=0; j<nbcolonnes; j++)
       printf(" %d",mat[i][j]);
     printf("\n");
   }
}



int main()
{
  // Declaration de la matrice qui est un pointeur de pointeurs.
  int **mat;

  // Definition du nb de lignes et de colonnes de la matrice.
  int nblignes = 5;
  int nbcolonnes = 3;
  
  // Initialisation du tirage aleatoire.
  srand(time(NULL));

  // Allocation dynamique de la matrice.
  mat = creerMat(nblignes,nbcolonnes);
  
  // Remplissage de la matrice avec des nombres aleatoires.
  initMat(mat,nblignes,nbcolonnes);
  
  // Affichage de la matrice.
  afficheMat(mat,nblignes,nbcolonnes);

  // Liberation de la matrice.
  libererMat(mat,nblignes);

}
