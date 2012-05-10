//Syed Omair Ali, David Loyzaga, Evelyn Chensen, Aaron Balsara
//Project - COMP1917
//26th April, 2012


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Game.h"

#define CYAN STUDENT_BQN
#define PURP STUDENT_MMONEY
#define YELL STUDENT_MJ
#define RED STUDENT_BPS
#define GREE STUDENT_MTV 
#define BLUE STUDENT_THD

#define DEFAULT_DISCIPLINES {CYAN,PURP,YELL,PURP,YELL,RED ,GREE,GREE, RED,GREE,CYAN,YELL,CYAN,BLUE,YELL,PURP,GREE,CYAN,RED }
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,9,9,2,8,10,5}

void testNewGameBasic (void);
void testGetTurnNumber (void);

int main (int argc, const char * argv[]) {
   testNewGameBasic ();  
   testGetTurnNumber ();  
   printf ("All tests passed!  you are Awesome\n");
   return EXIT_SUCCESS;
}

void testNewGameBasic (void) {
   printf ("testing new Game (basic tests) ...");
   // check makes a game without crashing 
   int disciplines[NUM_REGIONS];
   int dice [NUM_REGIONS];
   int regionID = 0;
   while (regionID < NUM_REGIONS) {
      disciplines[regionID] = STUDENT_THD;
      dice[regionID] = 12;
      regionID++;
   }

   Game g = newGame (disciplines, dice);
   assert (getTurnNumber(g) == -1);
   disposeGame (g);
   printf ("Passed\n");
}
/*                      
void testGetTurnNumber (void) {
   printf ("testing get turn number...");
   int disciplines[] = DEFAULT_DISCIPLINES;
   int dice[] = DEFAULT_DICE;
   Game g = newGame (disciplines, dice);
   
   assert (getTurnNumber(g) == -1);
   disposeGame (g);
   printf ("Passed\n");
}
*/
void testGetMostArcs (void) {
   printf("testing GetMostArcs");
   int disciplines[] = DEFAULT_DISCIPLINES;
   int dice[] = DEFAULT_DICE;
   Game g = newGame (disciplines, dice);
   
   assert (getMostARCs (g) == 0);
   disposeGame (g);
   printf ("Passed\n");
   
   
}

void testExampleGame (void) {
   printf("testing testExampleGame");
   int disciplines[] = DEFAULT_DISCIPLINES;
   int dice[] = DEFAULT_DICE;
   Game g = newGame (disciplines, dice);
   
   //initial tests at start of game
   assert (getMostPublications (g) == 0);
   assert (getTurnNumber (g) == -1);
   
   disposeGame (g);
   printf ("Passed\n");
}

void testGetMostPublications (void) {
   printf("testing GetMostPublications");
   int disciplines[] = DEFAULT_DISCIPLINES;
   int dice[] = DEFAULT_DICE;
   Game g = newGame (disciplines, dice);
   
   assert (getMostPublications (g) == 0);
   disposeGame (g);
   printf ("Passed\n");



}

void testGetTurnNumber (void) {
   printf("testing GetTurnNumber");
   int disciplines[] = DEFAULT_DISCIPLINES;
   int dice[] = DEFAULT_DICE;
   int i, j;
   Game g = newGame (disciplines, dice);
  
   assert (getTurnNumber (g) == -1);
   for (i = 0; i < 100; i++){
      g = throwDice(g, 5);
      assert(getTurnNumber(g) == i);
      asser(getWhoseTurn(g) == (i % 3) + 1); //Check if it increments the players
   }
   disposeGame (g);
   printf ("Passed\n");



}
