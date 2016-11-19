/********************************
*       TOMASZ ADAMCZYK    	*
*       Nr albumu: 243217       *
*       Informatyka I ROK       *
*       Projekt5.c              *
********************************/
#include <stdio.h>
#include <stdbool.h>
#include "game.h"
/*********   MAIN   ***********/
int main()
{
    ReadMeTXT();
    StartGry();
    for(;;)
    {
	RysujPlansze();
	if(StanGry==MOVE)
	{
	    int NrPola;
	    scanf("%d", &NrPola);
	    Ruch(NrPola);
	}
	else if(StanGry==WON || StanGry==DRAW) break;
    }
    Zwyciezca();
    return 0;
}
