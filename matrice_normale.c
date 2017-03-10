/*
 * Laurent LEQUIEVRE - Institut Pascal UMR6602 - 2017
 * laurent.lequievre@univ-bpclermont.fr
 * 
 * Exemples de creation et utilisation (passage par parametre de fonction)
 * d'une matrice d'entiers non crees dynamiquement.
 * 
*/

#include <stdio.h>

#define NB_LIGNES 4
#define NB_COLONNES 3

/*
 * Ici on specifie les dimensions de la matrice
 */
void afficheMat1(int mat[NB_LIGNES][NB_COLONNES])
{
	int i, j;
	for (i = 0; i < NB_LIGNES; i++)
	{
		for (j = 0; j < NB_COLONNES; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

/*
 * Ici on specifie uniquement la deuxieme dimension.
 * La premiere dimension n'etant pas obligatoire.
 */
void afficheMat2(int m, int n, int mat[][n])
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

/*
 * Ici on passe la matrice par pointeur simple.
 */
void afficheMat3(int *mat, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
		for (j = 0; j < n; j++)
			printf("%d ", *((mat+i*n) + j)); //Pour obtenir mat[i][j], on doit passer les 'i' lignes de 'n' colonnes (soit i*n) puis ajouter 'j' colonnes.
		printf("\n");
	}
}

int main()
{	
	int m1[NB_LIGNES][NB_COLONNES] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
	
	printf("\nAffichage 1\n");
	afficheMat1(m1);
	
	printf("\nAffichage 2\n");
	afficheMat2(NB_LIGNES,NB_COLONNES,m1);
	
	printf("\nAffichage 3\n");
	afficheMat3((int *)m1,NB_LIGNES,NB_COLONNES);
	
	printf("\nAffichage 3 bis\n");
	afficheMat3(&m1[0][0],NB_LIGNES,NB_COLONNES);
	
	printf("\nFIN\n");
	
}
