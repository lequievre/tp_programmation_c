/*

 Laurent LEQUIEVRE
 Exemple d'utilisation de la fonction fgets pour lecture d'une chaine de caracteres.
 On en profite pour tester la presence du caractere retour chariot '\n' pour vider la memoire d'entree standard : stdin.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH_BUFFER 12
#define MAX_LENGTH_S 10

void viderBuffer()
{
    char c;

    printf("Il y a des caracteres dans le buffer de stdin\nSuppression en cours...\n");

    do
      c=getchar();
    while (c!='\n' && c!=EOF);

    printf("Le buffer est maintenant vide\n");
}

int main()
{
    char s[MAX_LENGTH_S];

    printf("Saisir une chaine de caractères : ");
    if (fgets(s,sizeof(s),stdin) != NULL)
    {
        // On recherche la presence du retour chariot '\n' dans la chaine saisie.
        char *nc = strchr(s,'\n');

        // Si la chaine contient le '\n', l'utilisateur a saisit moins de caracteres que la taille max de la chaine.
        // Dans ce cas, il faut remplacer le '\n' par le caractere de fin de chaine : '\0'.
        // Sinon il faut penser a vider le buffer de l'entree standard stdin !
        if (nc != NULL)
           *nc = '\0';
        else
            viderBuffer();


        printf("\ns[%lu]=%d\n",strlen(s),s[strlen(s)]);

        printf("\nchaine saisie = %s , taille = %lu\n", s, strlen(s));
    }
    else
    {
       //La fonction perror affiche une chaine de caracteres passee en paramatre sur
       // la sortie d'erreur standard : stderr !
       perror("\nErreur lors de la saisie de la chaine de carateres !\n");

       //  constantes de la libc : EXIT_FAILURE = 1; EXIT_SUCCESS = 0;
       exit(EXIT_FAILURE);
    }

    char * buffer = (char *) malloc( MAX_LENGTH_BUFFER );

    printf("Saisir une chaine de caractères : ");
    if (fgets(buffer,MAX_LENGTH_BUFFER,stdin) != NULL)
    {
        char *nc = strchr(buffer,'\n');
        if (nc != NULL)
           *nc = '\0';
        else
            viderBuffer();

        printf("\nbuffer[%lu]=%d\n",strlen(buffer),buffer[strlen(buffer)]);
        printf("\nchaine saisie = %s , taille = %lu\n", buffer, strlen(buffer));
    }
    else
    {
       //void perror(const char *str) prints a descriptive error message to stderr
       perror("\nErreur lors de la saisie de la chaine de carateres !\n");
       //  constantes de la libc : EXIT_FAILURE = 1; EXIT_SUCCESS = 0;
       exit(EXIT_FAILURE);
    }

    free(buffer); // On pense a liberer la memoire pointee par le pointeur !

    exit(EXIT_SUCCESS);
}
