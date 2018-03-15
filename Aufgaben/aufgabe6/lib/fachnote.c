#include "fachnote.h"
#include  <stdio.h>
#include <string.h>

int einlesen(fach_note *fachnote)
{
    char leerzeichen;
    char unterstrich;
    char *ersetzen;
    
    scanf ("%s", fachnote->fach_name);

    if (scanf("%d", &fachnote->note.i) == 1)
    {
        fachnote->note_typ = benotet;
        fachnote->previous = NULL;
        fachnote->next = NULL;
    }
    else if (scanf("%c", &fachnote->note.c) == 1)
    {
        fachnote->note_typ = unbenotet;
        fachnote->previous = NULL;
        fachnote->next = NULL;
    }
    else
    {
        return 0;
    }

    leerzeichen = ' ';
    unterstrich = '_';
    
    while ((ersetzen = strchr(fachnote->fach_name, unterstrich)) != NULL)
    {
        memcpy(ersetzen, &leerzeichen, sizeof (char));
    }
    return 1;
}

void ausgeben(const fach_note* fachnote)
{
    printf("%-*s\t", fach_name_laenge , fachnote->fach_name);

    if (fachnote->note_typ == benotet)
    {
        if ((fachnote->note.i >= 10 && fachnote->note.i <= 40) ||
                fachnote->note.i == 50)
        {
            printf("%d%c%d\n", fachnote->note.i / 10, ',',
                   fachnote->note.i % 10);
        }
        else
        {
            printf("Fehler: %d\n", fachnote->note.i);
        }
    }
    else
    {
        if (fachnote->note.c == 'B')
        {
            printf("bestanden\n");
        }
        else if (fachnote->note.c == 'N')
        {
            printf("nicht bestanden\n");
        }
        else
        {
            printf("Fehler: %c\n", fachnote->note.c);
        }
    }
}