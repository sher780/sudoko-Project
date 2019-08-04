

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int is_fixed; /*0 if fixed 1 if not fixed */
    int value; /*0 if empty*/
    int solution_value; /*0 if empty*/
    int *potentialValues;
    int numOfPotentialValues;
} cell;

struct stackNode {
    int row;
    int column;
    int direction;
    cell **board;
    struct stackNode* next;
} ;

typedef struct stackNode Iteration;
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


