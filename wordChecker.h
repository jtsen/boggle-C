#ifndef WORDCHECKER_H
#define WORDCHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordChecker(char* boardValues,char* inputArray, int rootIndex, int wordIndex, int* usedCells){

        if(inputArray[wordIndex] == 0){
                return 1;
        }

        int checkIndex[8] = {0};

        checkIndex[1] = -4;
        checkIndex[6] = 4;

        switch(rootIndex % 4){
                case 0:
                        checkIndex[2] = -3;
                        checkIndex[4] = 1;
                        checkIndex[7] = 5;

                        break;
                case 2:
                case 1:
                        checkIndex[0] = -5 ;
                        checkIndex[2] = -3;
                        checkIndex[3] = -1;
                        checkIndex[4] = 1;
                        checkIndex[5] = 3;
                        checkIndex[7] = 5;
                        break;
                case 3:
                        checkIndex[0] = -5;
                        checkIndex[3] = -1;
                        checkIndex[5] = 3;
                        break;
        }

        for(int i = 0;i < 8; i++){
                if(checkIndex[i] == 0){
                        continue;
        }
        if(rootIndex + checkIndex[i] < 16 && rootIndex + checkIndex[i] > -1 && usedCells[rootIndex+checkIndex[i]] == 0 && boardValues[rootIndex+checkIndex[i]] == inputArray[wordIndex] ){
            usedCells[rootIndex+checkIndex[i]] = 1;
            if(wordChecker(boardValues,inputArray,rootIndex+checkIndex[i],wordIndex+1,usedCells)){
                return 1;
            }

            usedCells[rootIndex+checkIndex[i]] = 0;
        }

    }

    return 0;

}

#endif
