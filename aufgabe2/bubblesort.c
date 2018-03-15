#include <stdio.h>
#include <stdlib.h> /* calloc, malloc, free, ...*/
#include <time.h>
int main(int argc, char *argv[])
{
    int anIntArraySize;
    int *a;
    int i;
    int j;
    int tmp;
    int eingabe;
    srand((unsigned int) time(NULL));

    if (argc != 2)
    {
        printf("Aufruf: Bubblesort Anzahl \n");
        return 1; /* Um einen Error anzugeben */
    }

    anIntArraySize = atoi(argv[1]);
    a = (int*) calloc(anIntArraySize, sizeof (int));
    
    if (a != NULL){
        printf("Speicher ist reserviert \n");
    } else {
        printf("Kein freier Speicher vorhanden!");
        return 1;
    }
    
    printf("Bitte %d ganze Zahlen eingeben: \n", anIntArraySize);

    for (i = 0; i < anIntArraySize; i++)
    {
        if (scanf("%d", &eingabe) > 0)
        {
            a[i] = eingabe;
        }
        else
        {
            for (i = i; i < anIntArraySize; i++)
            {
                a[i] = rand();
                printf("%d\n", a[i]);
            }
        }
    }

    for (i = anIntArraySize; i > 1; i--)
    {
        for (j = 0; j < i - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }

    printf("Sortierte Zahlenfolge: \n");
    for (i = 0; i < anIntArraySize; ++i)
    {
        printf("%d\n", a[i]);
    }
    free (a);
    return 0;
}