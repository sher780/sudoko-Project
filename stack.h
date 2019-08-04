
#ifndef SUDOKOPROJECT_STACK_H
#define SUDOKOPROJECT_STACK_H

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

void Push(int row , int column , int direction , cell** board);
Iteration* Top();
void Pop();
#endif //SUDOKOPROJECT_STACK_H
