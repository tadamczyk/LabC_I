#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "game.h"
/*********  PLANSZA  **********/
ZNAK Plansza[3][3]=
{ {EMPTY, EMPTY, EMPTY},
{EMPTY, EMPTY, EMPTY},
{EMPTY, EMPTY, EMPTY} };
/*********  STAN GRY  *********/
STATUS_GRY StanGry=NOTSTARTED;
/*********  KOGO RUCH  ********/
KOGO_RUCH AktualnyGracz;
/********  PLIK README  *******/
void ReadMeTXT()
{
    FILE *ReadMe;
    if((ReadMe=fopen("ReadMe.txt","w"))==NULL) ;
    fprintf(ReadMe,"                                 -----    KÓŁKO I KRZYŻYK    -----\n\
    ------------------------------------------------------------------------------------------------\n\
    Jest to gra strategiczna rozgrywana przez dwóch graczy.\n\
    Gracze obejmują pola na przemian dążąc do objęcia trzech pól w jednej linii,\n\
    przy jednoczesnym uniemożliwieniu tego samego przeciwnikowi.\n\
    Pole może być objęte przez jednego gracza i nie zmienia swego właściciela przez cały przebieg gry.\n\
    Gra odbywa się na polu o wymiarach 3x3. Pola oznaczone są cyframi od 1 do 9.\n\
    Aby postawić kółko lub krzyżyk na polu oznaczonym daną cyfrą należy ją nacisnąć na klawiaturze.\n\
    ------------------------------------------------------------------------------------------------\n");
    fclose(ReadMe);
}
/*********  START GRY  ********/
bool StartGry()
{
    if(StanGry!=NOTSTARTED) return false;
    srand(time(0));
    AktualnyGracz=(rand()%2==0 ? CIRCLE : CROSS);
    StanGry=MOVE;
    return true;
}
/*******   RUCH GRACZY  *******/
bool Ruch(int NrPola)
{
    if(StanGry!=MOVE) return false;
    if(NrPola<1 || NrPola>9) return false;
    int Y=(NrPola-1)/3;
    int X=(NrPola-1)%3;
    if(Plansza[Y][X]==EMPTY) Plansza[Y][X]=(ZNAK)AktualnyGracz;
    else return false;
    const int LINIE[8][3][2]=   //8 mozliwych zwyciestw
    {
        {{0,0},{0,1},{0,2}},	//gorna pozioma
        {{1,0},{1,1},{1,2}},	//srodkowa pozioma
        {{2,0},{2,1},{2,2}},	//dolna pozioma
        {{0,0},{1,0},{2,0}},	//lewa pionowa
        {{0,1},{1,1},{2,1}},	//srodkowa pionowa
        {{0,2},{1,2},{2,2}},	//prawa pionowa
        {{0,0},{1,1},{2,2}},	//przekatna od lewej
        {{2,0},{1,1},{0,2}}     //przekatna od prawej
    };
    ZNAK Pole,ZgodnePole;
    int LiczbaZgodnych,LiczbaZajetych=0;
    int i,j;
    for(i=0;i<8;i++)
    {
	Pole=ZgodnePole=EMPTY;
	LiczbaZgodnych=0;
	for(j=0;j<3;j++)
	{
            Pole=Plansza[LINIE[i][j][0]][LINIE[i][j][1]];
	    if(Pole!=ZgodnePole)
	    {
	        ZgodnePole=Pole;
		LiczbaZgodnych=1;
	    }
            else LiczbaZgodnych++;
	}
	if(LiczbaZgodnych==3 && ZgodnePole!=EMPTY)
	{
	    StanGry=WON;
       	    return true;
	}
    }
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
	    if(Plansza[i][j]!=EMPTY) LiczbaZajetych++;
    if(LiczbaZajetych==3*3)
    {
        StanGry=DRAW;
	return true;
    }
    AktualnyGracz=AktualnyGracz==SM_CIRCLE ? SM_CROSS : SM_CIRCLE;
    return true;
}
/*******  RYSUJ PLANSZE  ******/
bool RysujPlansze()
{
    if(StanGry==NOTSTARTED) return false;
    system("clear");
    printf("     KOLKO I KRZYZYK   \t\t(instrukcje w pliku ReadMe.txt)\n");
    printf("  ---------------------\n\n");
    printf("\t---------\n");
    int i,j;
    for(i=0;i<3;i++)
    {
	printf("\t| ");
	for(j=0;j<3;j++)
	{
      	    if(Plansza[i][j]==EMPTY) printf("%d ", i*3+j+1);
	    else printf("%c ",(char)Plansza[i][j]);
	}
	printf("|\n");
    }
    printf("\t---------\n\n");
    switch(StanGry)
    {
        case NOTSTARTED:
        break;
	case MOVE:
	    printf("Podaj numer pola, w ktorym chcesz postawic ");
	    printf(AktualnyGracz==SM_CIRCLE ? "KOLKO: " : "KRZYZYK: ");
        break;
	case WON:
	    printf("Wygral gracz stawiajacy ");
	    printf(AktualnyGracz==SM_CIRCLE ? "KOLKA :)" : "KRZYZYKI :)");
        break;
	case DRAW:
            printf("Remis!");
        break;
    }
    return true;
}
/*********  ZWYCIEZCA  ********/
void Zwyciezca()
{
    FILE *Winner;
    if((Winner=fopen("Winner.txt","w"))==NULL) ;
    fprintf(Winner,"    W ostatniej grze ");
    if(StanGry==DRAW) fprintf(Winner,"padł remis!");
    else fprintf(Winner, AktualnyGracz==SM_CIRCLE ? "wygrał gracz stawiający kółka!" : "wygrał gracz stawiający krzyżyki!");
    fclose(Winner);
}
