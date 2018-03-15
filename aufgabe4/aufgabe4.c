/*
 * aufgabe4.c
 *
 * Liest Fachnamen mit Beurteilung ein und gibt dann einen Notenspiegel aus.
 *
 * Autor: Björn Burkert
 * Erstellt am: 09.05.17
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define fach_name_laenge 20


enum pruefungsart {benotet, unbenotet};

struct fach_note_liste
{
    struct fach_note_liste *previous;
    struct fach_note_liste *next;
    char fach_name[fach_name_laenge];
    enum pruefungsart note_typ;
    union
    {
        int i;
        char c;
    } note;
};
typedef struct fach_note_liste fach_note;


int einlesen(fach_note*);
void ausgeben(const fach_note*);
fach_note *einfuegen(fach_note*, fach_note*, fach_note**);
void schleife(fach_note*, void (*)(const fach_note *));
fach_note *entfernen(fach_note*, fach_note**);

char *fach, *ersetzen;
char notechar, leerzeichen, unterstrich;
int noteint;
fach_note *neue_fach_note;
fach_note *current;

int main(void)
{
    fach_note *notenspiegel = NULL;
    fach_note *p;
    fach_note *q;

    /*------------------------------------------- Notenspiegel einlesen */
    fprintf(stderr, "Faecher mit Noten eingeben (Ende mit Strg-D):\n");

    for (;;)
    {
        p = (fach_note *) malloc(sizeof (fach_note));
        if (p == NULL)
        {
            fprintf(stderr, "Zu viele Faecher!\n");
            break;
        }

        if (! einlesen(p))
        {
            fprintf(stderr, "Eingabeende!\n");
            free(p);
            break;
        }

        notenspiegel = einfuegen(notenspiegel, p, &q);
        if (q != NULL)
        {
            fprintf(stderr, "Alte Eingabe ueberschrieben!\n");
            free(q);
        }
    }

    /*------------------------------------------- Notenspiegel ausgeben */
    printf("Notenspiegel:\n");

    schleife(notenspiegel, ausgeben);

    /*------------------------------------------- Notenspiegel loeschen */
    while (notenspiegel != NULL)
    {
        notenspiegel = entfernen(notenspiegel, &p);
        free(p);
    }

    return 0;
}

int einlesen(fach_note *fachnote)
{
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

fach_note *einfuegen(fach_note* notenspiegel, fach_note* fachnote,
                     fach_note** ausgabeparameter)
{
    *ausgabeparameter = NULL;
    if (notenspiegel == NULL)
    {
        return fachnote;
    }

    notenspiegel->previous = fachnote;
    fachnote->next = notenspiegel;

    current = notenspiegel;
    if(current->next == NULL)
    {
        if (strcmp(notenspiegel->fach_name, fachnote->fach_name) == 0 &&
                notenspiegel->note_typ == fachnote->note_typ)
        {
            *ausgabeparameter = current;
            current->previous->next = NULL;
            current->next = NULL;
            current->previous = NULL;
        }
    }

    while (current->next != NULL)
    {
        
        if (strcmp(current->fach_name, fachnote->fach_name) == 0 &&
                current->note_typ == fachnote->note_typ)
        {
            *ausgabeparameter = current;
            if (current->next == NULL)
            {
                current->previous->next = NULL;
            }
            else
            {
                current->next->previous = current->previous;
                current->previous->next = current->next;
            }
            current->next = NULL;
            current->previous = NULL;
            return fachnote;
        }
        current = current->next;
    }
    return fachnote;
}

void schleife(fach_note* notenspiegel, void (funktion)(const fach_note *))
{
    if (notenspiegel == NULL)
    {
        return;
    }

    current = notenspiegel;
    funktion(current);

    while (current->next != NULL)
    {
        current = current->next;
        funktion(current);
    }
}

fach_note *entfernen(fach_note* notenspiegel, fach_note** entfernt)
{
    *entfernt = notenspiegel;
    if (notenspiegel->next == NULL)
    {
        notenspiegel = NULL;
    }
    else
    {
        notenspiegel = notenspiegel->next;
    }
    return notenspiegel;
}
