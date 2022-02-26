#ifndef USERS_H
#define USERS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Userinfo{
        char name[9];
        int maxScore;
        int totalGames;
        int totalScore;
        struct Userinfo* next;
}User;

User* newUser(char* name){
        if(strlen(name)>8){
                printf("Username can be 8 characters at most.\n");
                return NULL;
        }
        User* newUser = malloc(sizeof(User));
        strcpy(newUser->name, name);
        newUser->maxScore = 0;
        newUser->totalGames = 0;
        newUser->totalScore = 0;
        newUser->next = NULL;
        return newUser;
}

void addUser(User* head, User* node){
        User* temp = head;
        while(temp->next != NULL){
                temp = temp->next;
        }
        temp->next = node;
        return;
}
int findUser(User* head){
        char userName[9];
        int nodeIndex = 0;
        User* temp = head;
        scanf("%s", userName);
        if(strlen(userName)>8){
                printf("Please enter something less than 8 characters.\n");
                return -1;
        }
        if(strcmp(temp->name,userName) == 0){
                printf("Let's start BOGGLING!\n");
                return nodeIndex;
        }
        while(temp->next != NULL){
                nodeIndex++;
                temp = temp->next;
                if(strcmp(temp->name, userName) == 0){
                        printf("Let's start BOGGLING!\n");
                        return nodeIndex;
                }
        }
        return -1;
}

void updateUserInfo(User** head, int nodeIndex, int maxScore, int totalGames, int totalScore){
        User* current = *head;
        for(int i=0; i<nodeIndex; i++){
                current = current->next;
        }
        if(maxScore > current->maxScore)
                current->maxScore = maxScore;
        current->totalGames = totalGames;
        current->totalScore = totalScore;
        return;
}
int loginPrompt(User** head){
        char userNameInput[9];
        int result = 0;
        if(*head == NULL){
                while(1){
                        printf("Please enter a new username to start the fun!\n");
                        scanf("%s", userNameInput);
                        if(newUser(userNameInput)!=NULL){
                               *head = newUser(userNameInput);
                                printf("Thank you! Let's start boggling!\n");
                                sleep(1);
                                return 0;
                        }
                }
        }

        if(*head != NULL){
                printf("Enter your username to start Boggling!\n");
                while(1){
                        result = findUser(*head);
                        if(result != -1)
                                return result;
                        break;
                }
                printf("User not found.\n");
                printf("Would you like to create a new user? yes/no\n");
                scanf("%s",userNameInput);
                for(int i=0;i<strlen(userNameInput);i++){
                        userNameInput[i] = toupper(userNameInput[i]);
                }
                if(strcmp(userNameInput, "YES") == 0){
                        printf("Please reenter your username to create new user.\n");
                        scanf("%s",userNameInput);
                        User* temp = *head;
                        while(temp->next != NULL){
                                temp = temp->next;
                                result++;
                        }
                        User* newAcc = newUser(userNameInput);
                        addUser(*head,newAcc);
                        printf("User added. Let's start BOGGLING!\n");
                        return (result+1);
                }else if(strcmp(userNameInput, "NO") ==0){
                        printf("Redirecting to login screen ...\n");
                        loginPrompt(head);
                }else{
                        printf("Invalid input. Redirecting to login prompt...\n");
                        loginPrompt(head);
                }
        }
        return -1;
}

void freeUsers(User* head){
        User* temp;
        temp = head;
        while(temp->next != NULL){
                temp = temp->next;
        }
        free(temp);
}

#endif
