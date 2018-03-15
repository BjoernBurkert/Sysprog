#include <stdio.h>

int main(void)
{
    int iZahl = 345;
    short int SiZahl = 3;
    long int LiZahl = 13L;
    unsigned int UiBytefolge = 0xfff;
    unsigned short int USiBytefolge = 0xffffU;
    unsigned long int ULiBytefolge = 0xfffUL;
    float fZahl = 3.15F;
    double dZahl = 3.13;
    long double ldZahl = 3.12L;
    char zeichen = 'a';
    signed char scByte = -1;
    unsigned char ucByte = 0xff;
    const char* s = "Hallo";
    
    printf("Adresse: %p; Platzbedarf: %lu; Typ: int , Name: iZahl , Wert: %d\n"
        , (void*) &iZahl, (unsigned long) sizeof iZahl, iZahl);
    printf("Adresse: %p; Platzbedarf: %lu; Typ: short , Name: SiZahl , Wert: %d\n"
        , (void*) &SiZahl, (unsigned long) sizeof SiZahl, SiZahl);
    printf("Adresse: %p; Platzbedarf: %lu; Typ: long , Name: LiZahl , Wert: %ld\n"
        , (void*) &LiZahl, (unsigned long) sizeof LiZahl, LiZahl);
    printf("Adresse: %p; Platzbedarf: %lu; Typ: unsigned int , Name: UiBytefolge , Wert: %u\n"
        , (void*) &UiBytefolge, (unsigned long) sizeof UiBytefolge, UiBytefolge);
    printf("Adresse: %p; Platzbedarf: %lu; Typ: unsigned short int , Name: USiBytefolge , Wert: %u\n"
        , (void*) &USiBytefolge, (unsigned long) sizeof USiBytefolge, USiBytefolge);
    printf("Adresse: %p; Platzbedarf: %lu; Typ: unsigned long int , Name: ULiBytefolge , Wert: %lu\n"
        , (void*) &ULiBytefolge, (unsigned long) sizeof ULiBytefolge, ULiBytefolge);
    printf("Adresse: %p; Platzbedarf: %lu; Typ: float , Name: fiZahl , Wert: %f\n"
        , (void*) &fZahl, (unsigned long) sizeof fZahl, fZahl);
    printf("Adresse: %p; Platzbedarf: %lu; Typ: double , Name: dZahl , Wert: %f\n"
        , (void*) &dZahl, (unsigned long) sizeof dZahl, dZahl);
    printf("Adresse: %p; Platzbedarf: %lu; Typ: long double , Name: ldZahl , Wert: %Lf\n"
        , (void*) &ldZahl, (unsigned long) sizeof ldZahl, ldZahl);
    printf("Adresse: %p; Platzbedarf: %lu; Typ: char , Name: zeichen , Wert: %c\n"
        , (void*) &zeichen, (unsigned long) sizeof zeichen, zeichen);
    printf("Adresse: %p; Platzbedarf: %lu; Typ: signed char, Name: scByte , Wert: %d\n"
        , (void*) &scByte, (unsigned long) sizeof scByte, scByte);
    printf("Adresse: %p; Platzbedarf: %lu; Typ: unsigned cahr , Name: ucByte , Wert: %u\n"
        , (void*) &ucByte, (unsigned long) sizeof ucByte, ucByte);
    printf("Adresse: %p; Platzbedarf: %lu; Typ: String , Name: s , Wert: %s\n"
        , (void*) &s, (unsigned long) sizeof s, s);
    if (sizeof (int) == 4 && sizeof (long int) == 4 && sizeof (char*) == 4)
    {
        printf("Dieser Rechner ist ein ILP 32bit Rechner!");
    }
    else if (sizeof (int) == 4 && sizeof (long int) == 8 && sizeof (char*) == 8)
    {
        printf("Dieser Rechner ist ein LP 64bit Rechner!");
    } else 
    {
        printf("Dieser Rechner benutzt ein unbekanntes C-Datenmodell!");
    }
    return 0;
}
