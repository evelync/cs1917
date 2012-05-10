/*
 *  Game.c
 *  1917 v2.0
 *  Add to and change this file as you wish to implement the
 *  interface functions in Game.h
 *
 *  Created by Richard Buckland on 20/04/11.
 *  Copyright 2011 Licensed under Creative Commons SA-BY-NC 3.0.  
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "Game.h"
#include <time.h>
#define NUM_VERTICES 27
int powerTo(int base, int exponent);
typedef struct _player{
    int kpi;
    int publications;
    int patents;
    int arcGrants;
    int arcGrantsLoc[NUM_VERTICES];
    int regCampuses;
    int regCampusLoc[NUM_VERTICES];
    int g08Campuses;
    int g08CampuseLoc[NUM_VERTICES];
   /* int thd; //Blue
    int bps; //Red
    int bqn; //Cyan
    int mj; //Yellow
    int mtv; //Green
    int mmoney; //Purple */
    int student[6];
    int direction;
    int path;
} *Player;
int dicies;
// your team designs this type not us
// store in this struct all the things you might want to know about
// the game so you can write the interface functions in this header
// eg you might want to store the current turn number (so i've put
// it in for you as an example but take it out if you don;t want it)
typedef struct _game {
   // **you** need to put here the details of the data
   // you want to store in the _game struct
    int currentTurn;
    int currentPlayer;
    Player p[4];
    //vertex[54];
    int Hexagon[19][6];
    int edge[72];
} game;
int hexNumToColumn(int hexnum){
    return ((powerTo(hexnum,4)+4*powerTo(hexnum,3)-704*powerTo(hexnum,2)+18429*hexnum+49140)/49140);
}
int powerTo(int base, int exponent){
    int result = 1;
    int i = 0;
    for (i = 0; i < exponent; i++){
        result *= base;
    }
    return result;
}
void makeBoard(){
    int i;
    int j;
    for(i = 0; i < 19; i++){
    //Put resource in hexagon number
        for(j = 0; j < 6; j++){
            //Hexagon[i][j] = i%6; 
        }
    }
}
int main(int argc, char* argv[]){
    srand((unsigned)time(NULL));
   /* int hexNum;
    int columnNum;
    scanf("%d", &hexNum);
    columnNum = hexNumToColumn(hexNum);
    printf("\nColumn number is: %d\n", columnNum);*/
    int discipline[] = {0};
    int dice[] = {0};
    Game g = newGame(discipline, dice);
    /*int regionID;
    scanf("%d", &regionID);
    printf("\nResource at that spot is: %d\n", getDiscipline(g,regionID));*/
    throwDice(g, dicies);
    printf("%d\n", dicies);
    return 0;
}

Game newGame (int discipline[], int dice[]) {
    Game g;   
    g = malloc(sizeof(game));
    int i;
    for (i = 1; i <= 3; i++){
        g->p[i] = malloc(sizeof(Player));
    }
    g->currentTurn = -1;
    return g;
}

void disposeGame (Game g) {
    assert (g != NULL);
    int i;
    for (i = 0; i <= 3; i++){
        assert (g->p[i] != NULL);
        free (g->p[i]);
    }
    free (g);
}
void makeAction(Game g, action a){
    if (a.actionCode == BUILD_CAMPUS){
    } else if (a.actionCode == BUILD_GO8) {
    } else if (a.actionCode == OBTAIN_ARC) {
    } else if (a.actionCode == START_SPINOFF) {
    } else if (a.actionCode == OBTAIN_PUBLICATION) {
    } else if (a.actionCode == OBTAIN_IP_PATENT) {
    } else if (a.actionCode == RETRAIN_STUDENTS) {
    }
}
void throwDice(Game g, int diceScore){
    int d1;
    int d2;
   // d1 = (random() % (6)) + 1;
   // d2 = (random() % (6)) + 1;
    d1 = rand() % 6 + 1;
    d2 = rand() % 6 + 1;
    diceScore = d1+d2;
    dicies = diceScore;
    g->currentTurn++;
}
int getDiscipline(Game g, int regionID){
    int HexagonNum = regionID/100;
    int resourceNum = HexagonNum % 6;
//    g->player[g->currentPlayer]->student[resourceNum]++
    
    return resourceNum;
}
int getDiceValue(Game g, int regionID){
    return 0;
}
int getMostARCs(Game g){
    int i;
    int highestARCs = -1;
    for(i = 0; i <= NUM_UNIS; i++){
        if (g->p[i]->arcGrants > highestARCs){
            highestARCs = g->p[i]->arcGrants;
        }
    }
    return highestARCs;
}
int getMostPublication(Game g){
    int i;
    int highestPublication = -1;
    for(i = 0; i <= NUM_UNIS; i++){
        if (g->p[i]->publications > highestPublication){
            highestPublication = g->p[i]->publications;
        }
    }
    return highestPublication;
}
int getWhoseTurn(Game g){

    return 0;
}
int getCampus(Game g, path pathToVertex){

    return 0;
}
int getARC(Game g, path pathToEdge){

    return 0;
}
int isLegalAction(Game g, action a){

    return 0;
}
int getKPIpoints(Game g, int player){
    return g->p[player]->kpi;
}
int getARCs(Game g, int player){
    return g->p[player]->arcGrants;
}
int getGO8s(Game g, int player){
    return g->p[player]->g08Campuses;
}

int getCampuses(Game g, int player){
    return g->p[player]->regCampuses;
}
int getIPs(Game g, int player){
    return g->p[player]->patents;
}
int getPublications(Game g, int player){
    return g->p[player]->publications;
}
int getTurnNumber (Game g) {
    return g->currentTurn;
}
int getStudents(Game g, int player, int discipline){
    return g->p[player]->student[discipline];
}
int getExchangeRate (Game g, int player, int disciplineFrom, int disciplineTo){
    int rate;
    if (disciplineFrom == STUDENT_THD){
        rate = 0;
    } else {
        rate = 4;
    }
    return rate;
}
