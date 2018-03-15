#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
 
 
 
 
int main(int argc, char *argv[])
{
    int n;
    int m;
    int i;
    int j;
    int r;
    char** a;
    char* string;
    char* test;
 
    srand((unsigned int) time(NULL));
 
    /*---------------------------------------------- Feldgroesse bestimmen */
 
    if(argc != 2)
    {
        printf("Aufruf: c stringsort Anzahl\n");
        return 1;
    }
 
 
 
    n = atoi(argv[1]);
    m = strlen(argv[1]) + 1;
 
    if(n == 0)
    {
        printf("Aufruf: c stringsort Anzahl = 0\n");
        return 1;
    }
 
    /*--------------------------------------------------- Strings wuerfeln */
 
    a = (char**) malloc(n * sizeof(char*));
    if(a == NULL)
    {
        printf("Speicherfehler");
        return 1;
    }
 
 
    printf("Unsortiertes Feld:\n");
 
    for (i = 0; i < n; ++i)
    {
 
 
 
        r = rand() % n;
 
        test = (char*) malloc((m) * sizeof(char));
        if(test == NULL)
        {
            printf("Speicherfehler");
            return 1;
        }
 
 
        sprintf(test, "%d", r);
        a[i] = test;
 
        printf("%s ", a[i]);
    }
 
    printf("\n");
 
 
    /*-------------------------------------------------- Strings sortieren */
 
    for (i = n; i > 1; i--)
    {
        /* groessten Wert nach hinten schieben */
        for (j = 0; j < i - 1; ++j)
        {
            if (strcmp(a[j], a[j + 1]) > 0)
            {
                /* Werte tauschen*/
 
                char *tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
 
 
            }
        }
    }
 
 
 
    /*--------------------------------------------------- Strings ausgeben */
    printf("Sortiertes Feld:\n");
 
 
    string = (char*) calloc(m * n, sizeof(char));
    if(a == NULL)
    {
        printf("Speicherfehler");
        return 1;
    }

    strcpy(string, a[0]);
 
    for (i = 1; i < n; ++i)
    {
        if (strcmp(a[i], a[i - 1]) == 0)
        {
            strcat(string, "*");
        }
        else
        {
            strcat(string, " ");
            strcat(string, a[i]);
        }
    }
 
    printf("%s \n", string);
 
 
    for(i = 0; i < n; i++)
    {
 
        free(a[i]);
    }
    free (a);
    free(string);
    /*free(test);*/
 
    return 0;
}