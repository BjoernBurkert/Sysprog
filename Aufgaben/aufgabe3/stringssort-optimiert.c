#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
 
 
 
 
int main(int argc, char *argv[1])
{
    int n;
    int m;
    int i;
    int j;
    char* tmp;
    char* a;
    char* string;
 
    srand((unsigned int) time(NULL));
 
    /*---------------------------------------------- Feldgroesse bestimmen */
 
    if(argc != 2)
    {
        printf("Aufruf: c Bubblesort Anzahl\n");
        return 1;
    }
 
 
 
    n = atoi(argv[1]);
    m = strlen(argv[1]) + 1;
 
    if(n == 0)
    {
        printf("Aufruf: c Bubblesort Anzahl = 0\n");
        return 1;
    }
 
    /*--------------------------------------------------- Strings wuerfeln */
 
    a = (char*) calloc(m * n, sizeof(char));
    if(a == NULL)
    {
        printf("Speicherfehler");
        return 1;
    }
 
 
    printf("Unsortiertes Feld:\n");
 
 
    for (i = 0; i < n; ++i)
    {
 
        sprintf(a + m * i, "%d", rand() % n);
 
        printf("%s ", a + m * i);
    }
 
    printf("\n");
 
 
    /*-------------------------------------------------- Strings sortieren */
 
    tmp = (char*) malloc(n * sizeof(char));
    if(tmp == NULL)
    {
        printf("Speicherfehler");
        return 1;
    }
    for (i = n; i > 1; i--)
    {
        /* groessten Wert nach hinten schieben */
        for (j = 0; j < i - 1; ++j)
        {
            /* if(*a[j] > *a[j+1]) */
            if (strcmp(a + (m * j), a + m * (j + 1)) > 0)
            {
                /* Werte tauschen*/
 
                memcpy(tmp, a + m * (j + 1), m);
                memcpy(a + m * (j + 1), a + m * j, m );
                memcpy(a + (m * j), tmp, m);
 
 
            }
        }
    }
 
 
 
    /*--------------------------------------------------- Strings ausgeben */
    printf("Sortiertes Feld:\n");
 
 
    string = (char*) malloc(m * n * sizeof(char));
    if(a == NULL)
    {
        printf("Speicherfehler");
        return 1;
    }
    
    strcpy(string, a);
 
    for (i = 1; i < n; ++i)
    {
        if (strcmp(a + m * i, a + m * (i - 1)) == 0)
        {
            strcat(string, "*");
        }
        else
        {
            strcat(string, " ");
            strcat(string, a + m * i);
        }
    }
 
    printf("%s \n", string);
 
    free (a);
    free(tmp);
    free(string);
 
    return 0;
}