/*
* einstieg.c
*
* Das erste C-Programm gibt einen Text aus.
*
* Autor(en): . . .
* Erstellt am: . . .
*/

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int anzahl;
    char *vorname = (char*) malloc(8);

    printf("Anzahl bisher geschriebener C-Programme eingeben: ");
    scanf("%d", &anzahl);

    printf("Vorname eingeben: ");
    scanf("%s", vorname);

    printf("%ss %d. C-Programm funktioniert!\n", vorname, anzahl + 1);

    
    return 0;
}