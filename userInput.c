#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "wordChecker.h"
#include "functions.h"

int userInput(char* boardValues, char* inputArray){

        int* usedCells;
        usedCells = malloc(16*sizeof(int));

        for(int i = 0;i<16;i++){

                if(boardValues[i] == inputArray[0]){

                        for(int j = 0; j < 16; j++){
                                usedCells[j] = 0;
                        }

                        usedCells[i] = 1;
                        if(wordChecker(boardValues, inputArray, i, 1, usedCells) == 1){
                                if(strlen(inputArray) == 3 || strlen(inputArray) == 4)
                                        return 1;
                                if(strlen(inputArray) == 5)
                                        return 2;
                                if(strlen(inputArray) == 6)
                                        return 3;
                                if(strlen(inputArray) == 7)
                                        return 5;
                                if(strlen(inputArray) > 7)
                                        return 11;
                        }
                }
        }
        free(usedCells);
        return 0;

}
