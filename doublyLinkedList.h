
#ifndef SUDOKOPROJECT_DOUBLYLINKEDLIST_H
#define SUDOKOPROJECT_DOUBLYLINKEDLIST_H
void InsertAction (int data);               /*Insert Action after current action, delete all actions we've undo and free memory */
int listUndo();                             /*moves current action pointer to previous action , return data of current action, prints error if no action to undo */
int listRedo();                             /*moves current action pointer to next action , return data of current action , prints error if no action to redo*/
void printLastToFirst();                    /*prints the data from the last action to the first action*/
void printFirstToCurrentAction();           /*print the data from the first action made to current action (action history)*/
#endif //SUDOKOPROJECT_DOUBLYLINKEDLIST_H
