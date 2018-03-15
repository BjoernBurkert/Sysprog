#include "liste.h"

/* #include "fachnote.h" */

#include <string.h>

fach_note *einfuegen(fach_note* notenspiegel, fach_note* fachnote,
                     fach_note** ausgabeparameter)
{
    fach_note *current;
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

void schleife(fach_note* notenspiegel, /* void (funktion)(const fach_note *) */ void (*ausgeben) (const fach_note *n))
{
    /* if (notenspiegel == NULL)
    {
        return;
    }

    current = notenspiegel;
    funktion(current);

    while (current->next != NULL)
    {
        current = current->next;
        funktion(current);
    } */
    fach_note *p;
    
    for (p = notenspiegel; p != 0; p = p->next) 
    {
        ausgeben(p);
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