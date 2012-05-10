#include <stdio.h>
#include <stdlib.h>

//Syed Omair Ali, David Loyzaga, Evelyn Chensen, Aaron Balsara
//Project - COMP1917
//26th April, 2012

#include <stdio.h>
#include <stdlib.h>
#include "Game.c"
#define DEFAULT_DISCIPLINES {CYAN,PURP,YELL,PURP,YELL,RED ,GREE,GREE, RED,GREE,CYAN,YELL,CYAN,BLUE,YELL,PURP,GREE,CYAN,RED }
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,9,9,2,8,10,5}

int main(int argc, char* argv[]){
    int player;
    int discipline[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    action a;
    Game g = newGame(discipline, dice);
    while(getKPIpoints(g,1) < 150 && getKPIpoints(g,2) < 150 && getKPIpoints(g,3) < 150){
        g = throwDice(g);
        do {
            scanf("%d", &a->actionCode);
            printf("\n");
            g = makeAction(g, a);
        } while(!isLegalAction(g,a))

    }
    disposeGame(g);
    return EXIT_SUCCESS;
}
