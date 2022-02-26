#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include "functions.h"
#include "users.h"
#include "scoreboard.h"
#include "dictionary.h"
#include "boardGenerator.h"
#define MAX_LINE 100

int main(){
        int totalGames = 1, totalScore = 0, currentScore = 0, userDecision = -1;
        int score;
        User* temp;
        char* input;
        char* board = boardGenerator();
        FILE* input_FP;
        char line [MAX_LINE];
        char* file_name;
        static DNode* wordDictionary[BIG_HASH_SIZE];
        static DNode* usedDictionary[SMALL_HASH_SIZE];
        DNode* validWord;
        DNode* usedBefore;
        input = malloc(16);
        User* head = malloc(sizeof(User*));
        head = NULL;

        file_name = "wordlists.txt";


        if(!(input_FP = fopen(file_name,"r"))){
                fprintf(stderr, "Could not open file \"%s\" for reading dictionary words\n", file_name);
                return 1;
        }




        while(fgets(line, MAX_LINE, input_FP)!=NULL) {
                line[strcspn(line, "\r\n")] = '\0';
                insert(wordDictionary, BIG_HASH_SIZE, line);
        }
        fclose (input_FP);

        system("clear");
        int currentUserIndex = loginPrompt(&head);
        while(1){
                system("clear");
                boardCreator(board);
                printf("Your current score is: %d\n", currentScore);
                printf("Enter a word. \n");
                scanf("%s", input);
                for(int i=0; i < strlen(input);i++){input[i] = toupper(input[i]);}
                if(strcmp(input,"Q") == 0){
                        system("clear");
                        userDecision = printScores(&head);
                        if(userDecision == 0)
                                break;
                        if(userDecision == 3)
                                break;
                }

                if(strcmp(input,"N") == 0 || userDecision == 1){
                        system("clear");
                        updateUserInfo(&head,currentUserIndex,currentScore,totalGames,totalScore);
                        printCurrentTotal(&head, currentUserIndex);
                        sleep(2);
                        system("clear");
                        currentScore = 0;
                        free(board);
                        board = boardGenerator();
                        totalGames++;
                }
                if(strcmp(input,"U") == 0 || userDecision == 2){
                        system("clear");
                        updateUserInfo(&head,currentUserIndex,currentScore,totalGames,totalScore);
                        currentUserIndex = loginPrompt(&head);
                        temp = head;
                        for(int k=0; k<currentUserIndex; k++){
                                temp = temp->next;
                        }
                        printf("For loop done");
                        currentScore = 0;
                        totalGames = temp->totalGames;
                        totalScore = temp->totalScore;
                        printf("Scores loaded in");
                        free(board);
                        board = boardGenerator();
                        continue;
                }

                validWord = lookup(wordDictionary, BIG_HASH_SIZE, input);
                if(validWord == NULL && strcmp(input,"U")!=0 && strcmp(input,"N")!=0 && strcmp(input,"Q")!=0){
                        printf("This word does not exist.\n");
                        sleep(1);
                }
                usedBefore = lookup(usedDictionary, SMALL_HASH_SIZE, input);
                if(usedBefore != NULL && strcmp(input,"U")!=0 && strcmp(input,"N")!=0 && strcmp(input,"Q")!=0){
                        printf("This word has been used already.\n");
                        sleep(1);
                }
                if(validWord != NULL && usedBefore == NULL){
                        score = userInput(board,input);
                        currentScore = currentScore + score;
                        totalScore = totalScore + score;
                        if(userInput(board,input) > 0){
                                printf("Valid word.\n");
                                updateUserInfo(&head,currentUserIndex,currentScore,totalGames,totalScore);
                                DNode* usedWord = insert(usedDictionary, SMALL_HASH_SIZE,input);
                                free(usedWord);
                        }
                        if(userInput(board,input) == 0)
                                printf("Invalid word.\n");
                        sleep(1);
                }
                userDecision = -1;
        }


        printf("Game end.\n");
        while(head->next != NULL){
                freeUsers(head);
        }
        free(head);
        free(input);
        free(board);
        free_dictionary(wordDictionary, BIG_HASH_SIZE);
        free_dictionary(usedDictionary, SMALL_HASH_SIZE);
        return 0;
}
