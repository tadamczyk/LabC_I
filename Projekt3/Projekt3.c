/********************************
*       TOMASZ ADAMCZYK    	*
*       Nr albumu: 243217       *
*       Informatyka I ROK       *
*       Projekt3.c              *
********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/********** STRUKTURA **********/
typedef struct data
{
    char imie[15];
    char nazwisko[21];
    int indeks;
    struct data *next;
} Student;
/**********  FUNKCJE  **********/
int size(Student *lista);
void add(Student **lista);
void del(Student **lista);
void find(Student *lista);
void show(Student *lista);
Student *merge(Student *a, Student *b);
void split(Student *lista, Student **begin, Student **end);
void sort(Student **lista);
/**********   MAIN    **********/
int main()
{
    Student *Students=NULL;
    char wyb;
    do
    {
        printf("A-dodaj studenta, D-usun studenta, F-szukaj studenta\n");
        printf("W-pokaz baze danych, S-sortuj baze danych, E-zakoncz\n");
        scanf("%c",&wyb);
        switch(wyb)
        {
            case 'A':
            case 'a':
                add(&Students);
            break;
       	    case 'D':
            case 'd':
                del(&Students);
            break;
            case 'F':
            case 'f':
                find(Students);
            break;
            case 'W':
            case 'w':
                show(Students);
            break;
            case 'S':
            case 's':
                sort(&Students);
                if (size(Students)!=0) printf("Baza danych zostala posortowana.\n");
                else printf("Baza danych jest pusta!\n");
            break;
            case 'E':
            case 'e':
                return 0;
            break;
            default:
            break;
        }
    }
    while(scanf("%c",&wyb));
    return 0;
}
/**********   SIZE    **********/
int size(Student *lista)
{
    Student *wsk=lista;
    int l=0;
    while(wsk!=NULL)
    {
        l++;
        wsk=wsk->next;
    }
    return l;
}
/**********   DODAJ   **********/
void add(Student **lista)
{
    Student *wsk=(Student*)malloc(sizeof(Student));
    while(*lista!=NULL)
        lista=&((*lista)->next);
    *lista=wsk;
    printf("Podaj dane: imie, nazwisko oraz unikatowy nr indeksu:\n");
    scanf("%14s %20s %d", wsk->imie, wsk->nazwisko, &(wsk->indeks));
    wsk->next=NULL;
}
/**********   USUN    **********/
void del(Student **lista)
{
    Student *wsk=*lista;
    Student *prev=NULL;
    int ID;
    printf("Podaj nr indeksu:\n");
    scanf("%d", &ID);
    while(wsk!=NULL && wsk->indeks!=ID)
    {
        prev=wsk;
        wsk=wsk->next;
    }
    if(wsk==NULL) printf("Nie ma studenta o takim indeksie!\n");
    else
    {
        if(prev==NULL)
        {
            (*lista)=(*lista)->next;
            free(wsk);
        }
        else
        {
            prev->next=wsk->next;
            free(wsk);
        }
        printf("Student o podanym nr indeksu zostal usuniety!\n");
    }
}
/**********  ZNAJDZ   **********/
void find(Student *lista)
{
    Student *wsk=lista;
    int ID,i;
    printf("Podaj nr indeksu:\n");
    scanf("%d", &ID);
    for(i=1;i<=size(lista);i++)
    {
        if(wsk->indeks==ID) break;
        wsk=wsk->next;
    }
    if(i>size(lista)) printf("Nie ma studenta o takim indeksie!\n");
    else
    {
        printf("\t\tSTUDENT\n");
        printf("----------------------------------------\n");
        printf("%d#\t%s %s\t\t%d\n", i, wsk->imie, wsk->nazwisko, wsk->indeks);
    }
}
/**********   POKAZ   **********/
void show(Student *lista)
{
    Student *wsk=lista;
    int i=1;
    if(lista==NULL) printf("Baza danych jest pusta!\n");
    else printf("Baza danych zawiera %d elementow:\n", size(lista));
    while(wsk!=NULL)
    {
        printf("%d#\t%14s%20s\t%d\n", i, wsk->imie, wsk->nazwisko, wsk->indeks);
        wsk=wsk->next;
        i++;
    }
}
/*********   SORTUJ   **********/
Student *merge(Student *a, Student *b)
{
    Student *wsk=NULL;
    if(a==NULL) return b;
    else if(b==NULL) return a;
    char name_a[36],name_b[36];
    strcpy(name_a,a->nazwisko);
    strcat(name_a,a->imie);
    strcpy(name_b,b->nazwisko);
    strcat(name_b,b->imie);
    int k=0,maxk=36;
    while((int)name_a[k]==(int)name_b[k] && k<maxk)
        k++;
    if((int)name_a[k]<(int)name_b[k] || (k==36 && a->indeks<b->indeks))
    {
        wsk=a;
        wsk->next=merge(a->next,b);
    }
    else
    {
        wsk=b;
        wsk->next=merge(a,b->next);
    }
    return wsk;
}
void split(Student *lista, Student **begin, Student **end)
{
    Student *first,*second;
    if(lista==NULL || lista->next==NULL)
    {
        *begin=lista;
        *end=NULL;
    }
    else
    {
        second=lista;
        first=lista->next;
        while(first!=NULL)
        {
        	first=first->next;
        	if(first!=NULL)
        	{
        		second=second->next;
        		first=first->next;
        	}
        }
        *begin=lista;
        *end=second->next;
        second->next=NULL;
    }
}
void sort(Student **lista)
{
    Student *wsk=*lista;
    Student *a,*b;
    if(wsk==NULL || wsk->next==NULL) return;
    split(wsk,&a,&b);
    sort(&a);
    sort(&b);
    *lista=merge(a,b);
}
