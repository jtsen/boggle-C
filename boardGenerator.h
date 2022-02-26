#ifndef BOARDGENERATOR_H
#define BOARDGENERATOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

char* boardGenerator(){
        char* diceList[] = {
                "RIFOBX","IFEHEY","DENOWS","UTOKND",
                "HMSRAO","LUPETS","ACITOA","YLGKUE",
                "QBMJOA","EHISPN","VETIGN","BALIYT",
                "EZAVND","RALESC","UWILRG","PACEMD"
        };

        char* boardValues;
        boardValues = malloc(16);

        int dieSelected[16];
        for(int i = 0; i < 15; i++){
                dieSelected[i] = 0;
        }

        srand(time(0));
        int dieChoice;
        int dieSide;
        int boardValueCounter = 0;
        while(boardValueCounter < 16){
                dieChoice = rand() % 16;
                if(dieSelected[dieChoice]){
                         continue;
                 }
         dieSide = rand() % 6;
         dieSelected[dieChoice] = 1;
         boardValues[boardValueCounter] = diceList[dieChoice][dieSide];
         boardValueCounter++;
        }
        return boardValues;
}

void boardCreator(char* boardValues){
        printf("---------\n");
        printf("|%c|%c|%c|%c|\n",boardValues[0],boardValues[1],boardValues[2],boardValues[3]);
        printf("|-------|\n");
        printf("|%c|%c|%c|%c|\n",boardValues[4],boardValues[5],boardValues[6],boardValues[7]);
        printf("|-------|\n");
        printf("|%c|%c|%c|%c|\n",boardValues[8],boardValues[9],boardValues[10],boardValues[11]);
        printf("|-------|\n");
        printf("|%c|%c|%c|%c|\n",boardValues[12],boardValues[13],boardValues[14],boardValues[15]);
        printf("---------\n");
}

#endif
