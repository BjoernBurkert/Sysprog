#include <stdio.h>

int main(void)
{
    int iZahl = 345;
    printf("Adresse: %p; Platzbedarf: %zu; Typ: int , Name: iZahl , Wert: %d\n"
           , (void*) &iZahl, sizeof iZahl, iZahl);

    short int SiZahl = 3;
    printf("Adresse: %p; Platzbedarf: %zu; Typ: short , Name: SiZahl , Wert: %d\n"
           , (void*) &SiZahl, sizeof SiZahl, SiZahl);

    long int LiZahl = 13L;
    printf("Adresse: %p; Platzbedarf: %zu; Typ: long , Name: LiZahl , Wert: %ld\n"
           , (void*) &LiZahl, sizeof LiZahl, LiZahl);

    unsigned int UiBytefolge = 0xfff;
    printf("Adresse: %p; Platzbedarf: %zu; Typ: unsigned int , Name: UiBytefolge , Wert: %u\n"
           , (void*) &UiBytefolge, sizeof UiBytefolge, UiBytefolge);

    unsigned short int USiBytefolge = 0xffU;
    printf("Adresse: %p; Platzbedarf: %zu; Typ: unsigned short int , Name: USiBytefolge , Wert: %u\n"
           , (void*) &USiBytefolge, sizeof USiBytefolge, USiBytefolge);

    unsigned long int ULiBytefolge = 0xfffUL;
    printf("Adresse: %p; Platzbedarf: %zu; Typ: unsigned long int , Name: ULiBytefolge , Wert: %lu\n"
           , (void*) &ULiBytefolge, sizeof ULiBytefolge, ULiBytefolge);

    float fZahl = 3.15F;
    printf("Adresse: %p; Platzbedarf: %zu; Typ: float , Name: fZahl , Wert: %f\n"
           , (void*) &fZahl, sizeof fZahl, fZahl);

    double dZahl = 3.13;
    printf("Adresse: %p; Platzbedarf: %zu; Typ: double , Name: dZahl , Wert: %g\n"
           , (void*) &dZahl, sizeof dZahl, dZahl);


    long double ldZahl = 3.12L;
    printf("Adresse: %p; Platzbedarf: %zu; Typ: long double , Name:  ldZahl , Wert: %Lf\n"
           , (void*) &ldZahl, sizeof ldZahl, ldZahl);


    const char zeichen = 'a';
    printf("Adresse: %p; Platzbedarf: %zu; Typ: char , Name: zeichen , Wert: %c\n"
           , (void*) &zeichen, sizeof zeichen, zeichen);


    signed char scByte = -1;
    printf("Adresse: %p; Platzbedarf: %zu; Typ: signed char , Name: scByte , Wert: %hhi\n"
           , (void*) &scByte, sizeof scByte, scByte);


    unsigned char ucByte = 0xf;
    printf("Adresse: %p; Platzbedarf: %zu; Typ: unsigned char , Name: ucByte , Wert: %hhu\n"
           , (void*) &ucByte, sizeof ucByte, ucByte);

    char* s = "Hallo";
    printf("Adresse: %p; Platzbedarf: %zu; Typ: String , Name: s , Wert: %s\n"
           , (void*) &s, sizeof s, s);

    long long int lliZahl = 5;
    printf("Adresse: %p; Platzbedarf: %zu; Typ: long long int , Name: lliZahl , Wert: %lld\n"
           , (void*) &lliZahl, sizeof lliZahl, lliZahl);

    unsigned long long int ulliZahl = 63;
    printf("Adresse: %p; Platzbedarf: %zu; Typ: unsigned long long int , Name: ulliZahl , Wert: %llu\n"
           , (void*) &ulliZahl, sizeof ulliZahl, ulliZahl);

    if (sizeof(iZahl) == 4 && sizeof(LiZahl) == 4 && sizeof(ulliZahl) == 8 && sizeof(s) == 8)
        printf("Es liegt ein LLP64 Datenmodell vor.\n");
    else if (sizeof(iZahl) == 4 && sizeof(LiZahl) == 4)
        printf("Es liegt ein ILP32 Datenmodell vor.\n");

    printf("\nSpeicherbedarf: %lu\n", (unsigned long) &iZahl - (unsigned long) &ulliZahl);

    return 0;
}