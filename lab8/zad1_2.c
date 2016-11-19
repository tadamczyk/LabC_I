#include <stdio.h>
enum {PESEL, NIP} ID;
struct dane
{
    char imie[20];
    char nazwisko[32];
    union
    {
        char PESEL[11];
        char NIP[10];
    } TID;
} Prac;
void ustawPESEL(struct dane *Prac)
{
    printf("Podaj PESEL:\n");
    scanf("%11s", Prac->TID.PESEL);
}
void ustawNIP(struct dane *Prac)
{
    printf("Podaj NIP:\n");
    scanf("%10s", Prac->TID.NIP);
}
void pokazPrac(struct dane Prac)
{
    printf("\n\t\t*****************************************\n");
    printf("\t\t*\t\tPRACOWNIK:\t\t*\n");
    printf("\t\t*---------------------------------------*\n");
    printf("\t\tIMIE:\t\t%s\n", Prac.imie);
    printf("\t\tNAZWISKO:\t%s\n", Prac.nazwisko);
    if (ID==PESEL) printf("\t\tPESEL:\t\t%s\n", Prac.TID.PESEL);
    if (ID==NIP) printf("\t\tNIP:\t\t%s\n", Prac.TID.NIP);
    printf("\t\t*****************************************\n");
}
int main()
{
    printf("Podaj dane pracownika: imie, nazwisko oraz PESEL lub NIP:\n");
    scanf("%20s %32s", Prac.imie, Prac.nazwisko);
    printf("PESEL (0) czy NIP (1):\n");
    scanf("%ud", &ID);
    switch(ID)
    {
        case PESEL:
            ustawPESEL(&Prac);
        break;
        case NIP:
            ustawNIP(&Prac);
        break;
        default:
            printf("Blad wejscia!\n");
    }
    pokazPrac(Prac);
    return 0;
}
