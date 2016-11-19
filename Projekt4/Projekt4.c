/********************************
*       TOMASZ ADAMCZYK    	*
*       Nr albumu: 243217       *
*       Informatyka I ROK       *
*       Projekt4.c              *
********************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int compared,swapped;
/**********  FUNKCJE  **********/
void BubbleSort(int tab[], int n);
void InsertionSort(int tab[], int i, int n);
void SelectionSort(int tab[], int i, int n);
void Merge(int tab[], int i, int s, int n);
void MergeSort(int tab[], int i, int n);
void QuickSort(int tab[], int i, int n);
/**********   MAIN    **********/
int main()
{
    srand(time(NULL));
    int n,i;
    printf("Podaj liczbe n:\n");
    scanf("%d", &n);
    int tab1[n],tab2[n],tab3[n],tab4[n],tab5[n];
    printf("Tablica przed sortowaniem:\n");
    for(i=0;i<n;i++)
    {
        tab1[i]=tab2[i]=tab3[i]=tab4[i]=tab5[i]=rand()%100+1;
        printf("%d ", tab1[i]);
    }
    printf("\nTablica po sortowaniu:\n");
    printf("------------------------------\n");
    printf("1.Sortowanie bąbelkowe:\n");
    BubbleSort(tab1,n);
    for(i=0;i<n;i++) printf("%d ", tab1[i]);
    printf("\nLiczba porownan: %d\nLiczba zamian: %d\n", compared, swapped);
    printf("------------------------------\n");
    compared=swapped=0;
    printf("2.Sortowanie przez wstawianie:\n");
    InsertionSort(tab2,0,n);
    for(i=0;i<n;i++) printf("%d ", tab2[i]);
    printf("\nLiczba porownan: %d\nLiczba zamian: %d\n", compared, swapped);
    printf("------------------------------\n");
    compared=swapped=0;
    printf("3.Sortowanie przez wybór:\n");
    SelectionSort(tab3,0,n);
    for(i=0;i<n;i++) printf("%d ", tab3[i]);
    printf("\nLiczba porownan: %d\nLiczba zamian: %d\n", compared, swapped);
    printf("------------------------------\n");
    compared=swapped=0;
    printf("4.Sortowanie przez scalanie:\n");
    MergeSort(tab4,0,n-1);
    for(i=0;i<n;i++) printf("%d ", tab4[i]);
    printf("\nLiczba porownan: %d\n", compared);
    printf("------------------------------\n");
    compared=swapped=0;
    printf("5.Sortowanie szybkie:\n");
    QuickSort(tab5,0,n-1);
    for(i=0;i<n;i++) printf("%d ", tab5[i]);
    printf("\nLiczba porownan: %d\nLiczba zamian: %d\n", compared, swapped);
    printf("------------------------------\n");
    return 0;
}
/********  BUBBLE SORT  ********/
void BubbleSort(int tab[], int n)
{
    int i,temp;
    if(n==0 || n==1) return;
    for(i=0;i<n-1;i++)
    {
        compared++;
        if(tab[i+1]<tab[i])
        {
            temp=tab[i+1];
            tab[i+1]=tab[i];
            tab[i]=temp;
            swapped++;
        }
    }
    BubbleSort(tab,n-1);
}
/******* INSERTION SORT ********/
void InsertionSort(int tab[], int i, int n)
{
    int j,temp;
    if(n==0 || n==1) return;
    if(i==n-1);
    else
    {
        InsertionSort(tab,i+1,n);
        temp=tab[i];
        for(j=i+1;j<n;j++)
        {
            compared++;
            if(tab[j]<temp)
            {
                tab[j-1]=tab[j];
                tab[j]=temp;
                swapped++;
            }
        }
    }
}
/******* SELECTION SORT ********/
void SelectionSort(int tab[], int i, int n)
{
    if(n==0 || n==1) return;
    int min=i,j,temp;
    for(j=i+1;j<n;j++)
    {
        if(tab[min]>tab[j]) min=j;
        compared++;
    }
    if(min!=i)
    {
        compared++;
        temp=tab[i];
        tab[i]=tab[min];
        tab[min]=temp;
        swapped++;
    };
    i++;
    if(i<n-1) SelectionSort(tab,i,n);
}
/********  MERGE SORT  *********/
void Merge(int tab[], int i, int s, int n)
{
    int j,k,l;
    int n1=s-i+1;
    int n2=n-s;
    int L[n1],R[n2];
    for(j=0;j<n1;j++) L[j]=tab[j+i];
    for(k=0;k<n2;k++) R[k]=tab[s+k+1];
    j=0;
    k=0;
    l=i;
    while(j<n1 && k<n2)
    {
        compared++;
        if(L[j]<=R[k])
        {
            tab[l]=L[j];
            j++;
        }
        else
        {
            tab[l]=R[k];
            k++;
        }
        l++;
    }
    while(j<n1)
    {
        tab[l]=L[j];
        j++;
        l++;
    }
    while(k<n2)
    {
        tab[l]=R[k];
        k++;
        l++;
    }
}
void MergeSort(int tab[], int i, int n)
{
    if(i<n)
    {
        int s=i+(n-i)/2;
        MergeSort(tab,i,s);
        MergeSort(tab,s+1,n);
        Merge(tab,i,s,n);
    }
}
/********  QUICK SORT  *********/
void QuickSort(int tab[], int i, int n)
{
    if(n==0) return;
    int j,l,s,temp;
    s=tab[(i+n)/2];
    for(j=i,l=n;j<l;)
    {
        while(tab[j]<s) j++;
        while(tab[l]>s) l--;
        compared++;
        if(j<=l)
        {
            temp=tab[j];
            tab[j]=tab[l];
            tab[l]=temp;
            j++;
            l--;
            swapped++;
        }
    }
    if(i<l) QuickSort(tab,i,l);
    if(n>j) QuickSort(tab,j,n);
    if(n==1)
    {
        compared=swapped=0;
    }
}
