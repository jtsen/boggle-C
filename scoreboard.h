#include <stdlib.h>
#include <string.h>
#include "users.h"

int printScores(User** head){
        char userInput[5];
        User* temp;
        temp = *head;
        while(temp->next != NULL){
                for(int i=0;i<strlen(temp->name);i++){
                        if(i == (strlen(temp->name)-1)){
                                printf("%c\t", temp->name[i]);
                        }else{
                                printf("%c",temp->name[i]);
                        }
                }
                printf("Highscore: %d\t", temp->maxScore);
                printf("Games Played: %d\t", temp->totalGames);
                printf("Total Score: %d\n", temp->totalScore);
                temp = temp->next;
        }
        for(int i=0;i<strlen(temp->name);i++){
                if(i == (strlen(temp->name)-1)){
                        printf("%c\t", temp->name[i]);
                }else{
                        printf("%c",temp->name[i]);
                }
        }
        printf("Highscore: %d\t", temp->maxScore);
        printf("Games Played: %d\t\t", temp->totalGames);
        printf("Total Score: %d\t", temp->totalScore);
        printf("\n\nAre you sure you want to quit?\n");
        printf("Quit (q), Logout (u), new game (n)\n");
        scanf("%s",userInput);
        for(int i=0; i<strlen(userInput);i++){userInput[i]=toupper(userInput[i]);}
        if(strcmp(userInput,"Q") == 0)
                return 0;
        if(strcmp(userInput,"N") == 0)
                return 1;
        if(strcmp(userInput,"U") == 0)
                return 2;
        return 3;
}

void printCurrentTotal(User** head, int userIndex){
        User* temp;
        temp = *head;
        for(int i=0;i<userIndex;i++){
                temp = temp->next;
        }
        printf("Current Total Score: %d\n", temp->totalScore);
}

#endif
