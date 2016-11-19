#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int count;
typedef struct lifo
{
    int val;
    struct lifo* next;
} LIFO;
int push(LIFO** stack, int data)
{
    LIFO* nowy;
    nowy=(LIFO*)malloc(sizeof(LIFO));
    nowy->val=data;
    if(size(&nowy)>=MAX) {printf("Stos ma wartosc MAX.\n"); return 1;};
    if(*stack)
    {
        nowy->next=*stack;
    }
    else
    {
        nowy->next=0;
    }
    *stack=nowy;
    count++;
}
int pop(LIFO** stack)
{
    if(*stack)
    {
        LIFO* ptr;
        ptr=*stack;
        *stack=(*stack)->next;
        free(ptr);
    }
    count--;
}
int empty(LIFO** stack)
{
    return !(*stack);
}
int size()
{
    return count;
}
int top(LIFO** stack, int* retval)
{
    if(*stack)
    {
        *retval=(*stack)->val;
        return 1;
    }
    return 0;
}
int main()
{
    LIFO* stos=0;
    int data;
    char war;
    printf("Co chcesz zrobić?\nA-dodaj, D-usun, \nE-sprawdz, czy jest pusty, S-sprawdz rozmiar\nX-konczy program\n");
    while(scanf("%c",&war)!=EOF)
    {
        int x;
        switch (war)
        {
            case 'A':
            scanf("%d",&x);
            push(&stos,x);
            break;
            case 'D':
            if (empty(&stos)) {printf("Stos jest pusty.\n"); break;}
            if (!empty(&stos)) {printf("%d\n",stos->val); pop(&stos);}
            break;
            case 'E':
            printf("Stos jest %s.\n", (empty(&stos) ? "pusty" : "niepusty"));
            break;
            case 'S':
            printf("Rozmiar stosu wynosi %d.\n", size(&stos));
            break;
            case 'X':
            return 0;
        }
    }
    return 0;
}
