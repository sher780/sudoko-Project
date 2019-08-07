

#include "doublyLinkedList.h"


struct Node {                                  /*action represented by node */
    sudokoBoard *board;
    struct Node* next;
    struct Node* prev;

};

struct Node* head;                              /*maintaining 3 pointers - last action , first action and current action*/
struct Node* tail;
struct Node* currentAction;


struct Node* createNode(sudokoBoard *board){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->board = board;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void InsertAction (sudokoBoard *board){
    struct Node* newNode = createNode(board);
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

sudokoBoard* listUndo(){
    if(currentAction == head){
        printf("Error : You've reached the first action, can't undo\n");
        return 0;
    }
    currentAction = currentAction->prev;
    return currentAction->board;
}

sudokoBoard* listRedo(){
    if(currentAction == tail){
        printf("Error : You've reached the last action, can't redo\n");
        return 0;
    }
    currentAction = currentAction->next;
    return  currentAction->board;
}

void printLastToFirst(int whatToPrint){
    struct Node* temp = tail;
    if(head == NULL){
        printf("Error : Nothing to print, list is empty\n");
    }
    while(temp != head){
        printBoard(whatToPrint , temp->board);
    }
}
void printFirstToCurrentAction(int whatToPrint){
    struct Node* temp = head;
    if(head == NULL){
        printf("Error : Nothing to print, list is empty\n");
    }
    while(temp != currentAction){
        printBoard(whatToPrint , temp->board);
    }
}
