#ifndef FACHNOTE_H
#define FACHNOTE_H

#define fach_name_laenge 20

enum pruefungsart {benotet, unbenotet};

typedef struct fach_note_liste fach_note;

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

int einlesen(fach_note*);

void ausgeben(const fach_note*);

#endif