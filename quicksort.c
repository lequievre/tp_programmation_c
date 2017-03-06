#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 5
#define MAX 40
#define MAX_SIZE_TAB 10

void triTab(int[], int);
void triSousTab(int[], int, int);
int choisirPivot(int[], int, int);
void initialiseTab(int[], int);
void afficheTab(int[], int);

void main() 
{
	srand(time(NULL));

	//int tab[] = { 7, 12, 1, -2, 0, 15, 4, 11, 9};
	 
        int tab[MAX_SIZE_TAB];
	int size_of_tab = sizeof(tab)/sizeof(int);

        initialiseTab(tab, size_of_tab);

	printf("\n\nTableau non trie :");
	afficheTab(tab, size_of_tab);

	//quickSort(tab, 0, size_of_tab -1);
	triTab(tab,size_of_tab);

	printf("\n\nTableau trie :");
	afficheTab(tab, size_of_tab);

	printf("\n\nFIN\n\n");

}

void initialiseTab(int tab[], int size)
{
  int i;
  for (i=0; i<size; i++)
    tab[i] = rand()%(MAX-MIN+1)+MIN;
}

void afficheTab(int tab[], int size)
{
  int i;
  for (i=0; i<size; i++)
    printf(" %d ",tab[i]);
}

void triTab(int tab[],int size)
{
	triSousTab(tab,0,size-1);
}

void triSousTab(int tab[], int left, int right)
{
   int j;

   if( left < right ) 
   {
       j = choisirPivot(tab, left, right);
       triSousTab(tab, left, j-1);
       triSousTab(tab, j+1, right);
   }
	
}

int choisirPivot(int tab[], int left, int right) {
   int pivot, i, j, t;
   pivot = tab[left];
   i = left; j = right+1;
		
   while(1)
   {
   	do ++i; while( tab[i] <= pivot && i <= right );
   	do --j; while( tab[j] > pivot );
   	if( i >= j ) break;
   	t = tab[i]; tab[i] = tab[j]; tab[j] = t;
   }
   t = tab[left]; tab[left] = tab[j]; tab[j] = t;
   return j;
}

