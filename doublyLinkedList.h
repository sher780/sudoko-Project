#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef SUDOKOPROJECT_DOUBLYLINKEDLIST_H
#define SUDOKOPROJECT_DOUBLYLINKEDLIST_H
typedef enum {solve ,  edit , mark_errors , print_board , set , validate, guess , generate , undo, redo, save , hint , guess_hint , num_solutions , autofill , reset }ACTION;
void InsertAction (int oldValue , int newValue, int row , int column , ACTION action);              /*Insert Action after current action, delete all actions we've undo and free memory */
void listUndo(sudokoBoard* board);                                                                  /*moves current action pointer to previous action , return data of current action, prints error if no action to undo */
void listRedo(sudokoBoard* board);                                                                  /*moves current action pointer to next action , return data of current action , prints error if no action to redo*/
void printLastToFirst(int whatToPrint);                                                             /*prints the data from the last action to the first action*/
void printFirstToCurrentAction(int whatToPrint);                                                    /*print the data from the first action made to current action (action history)*/
#endif //SUDOKOPROJECT_DOUBLYLINKEDLIST_H
