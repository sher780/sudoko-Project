

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


Iteration* top;

Iteration *createSolveItaration(int row , int column , int direction , cell **board){
    Iteration* newSolveItaration = (Iteration*)malloc(sizeof(Iteration));
    newSolveItaration->row = row;
    newSolveItaration->column = column;
    newSolveItaration->direction = direction;
    newSolveItaration->board = board;
    newSolveItaration->next = NULL;
    return newSolveItaration;
}

void Push(int row , int column , int direction , cell** board){
    Iteration* newSolveItaration = createSolveItaration(row , column , direction , board);
    if(top == NULL){
        top = newSolveItaration;
        return;
    }
    else{
        newSolveItaration->next = top;
        top = newSolveItaration;
    }
}

Iteration* Top(){
    Iteration* temp = top;
    if(top == NULL){
        printf("Error : stack is empty.\n");
        return NULL;
    }
    else{
        top = top->next;
    }
    return temp;
}

void Pop(){
    Iteration* temp = top;
    if(top == NULL){
        printf("Error : stack is empty , can't Pop.\n");
    }
    else{
        top = top->next;
        free(temp);
    }
}


