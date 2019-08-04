

#include "doublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {                                  /*action represented by node */
    int data;
    struct Node* next;
    struct Node* prev;

};

struct Node* head;                              /*maintaining 3 pointers - last action , first action and current action*/
struct Node* tail;
struct Node* currentAction;


struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void InsertAction (int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){                               /*check if this is the first action (new list)*/
        head = newNode;
        tail = newNode;
        currentAction = newNode;
    }
    while( currentAction != tail){                  /*if there are actions we need to delete from memory */
        tail = tail->prev;
        free(tail->next);
        tail->next = NULL;
    }
    newNode->prev = currentAction;
    currentAction->next = newNode;
    tail = newNode;
    currentAction = newNode;
}

int listUndo(){
    if(currentAction == head){
        printf("Error : You've reached the first action, can't undo\n");
        return 0;
    }
    currentAction = currentAction->prev;
    return currentAction->data;
}

int listRedo(){
    if(currentAction == tail){
        printf("Error : You've reached the last action, can't redo\n");
        return 0;
    }
    currentAction = currentAction->next;
    return  currentAction->data;
}

void printLastToFirst(){
    struct Node* temp = tail;
    if(head == NULL){
        printf("Error : Nothing to print, list is empty\n");
    }
    while(temp != head){
        printf("%d\n" , temp->data);
    }
}
void printFirstToCurrentAction(){
    struct Node* temp = head;
    if(head == NULL){
        printf("Error : Nothing to print, list is empty\n");
    }
    while(temp != currentAction){
        printf("%d\n" , temp->data);
    }
}
