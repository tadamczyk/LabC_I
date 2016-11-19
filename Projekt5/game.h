#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <stdbool.h>
/*********   TYPY   ***********/
typedef enum GAMESTATE {NOTSTARTED, MOVE, WON, DRAW} STATUS_GRY;
typedef enum SIGN_MOVE {SM_CIRCLE='O', SM_CROSS='X'} KOGO_RUCH;
typedef enum FIELD {EMPTY=0, CIRCLE=SM_CIRCLE, CROSS=SM_CROSS} ZNAK;
/*********  STAN GRY  *********/
extern STATUS_GRY StanGry;
/*********  PROTOTYPY  ********/
void ReadMeTXT();
bool StartGry();
bool Ruch(int);
bool RysujPlansze();
void Zwyciezca();
#endif
