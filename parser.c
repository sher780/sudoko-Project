//
// Created by oved on 02/08/2019.
//

//
// Created by oved on 02/08/2019.
//

#include <stddef.h>
#include "parser.h"
#include "board.h"

int order(sudokoBoard board){
    int x, y, value = -1;
    int status = 0;
    float f = -1;

    char text[BUFFERSIZE] = { 0 };

    char *pcommand;
    char *ptoken;
    char *path = NULL;
    char *psolve = "solve";
    char *pedit = "edit";
    char *pmark = "mark_errors";
    char *pprint = "print_board";
    char *pset = "set";
    char *pvalidate = "validate";
    char *pguess = "guess";
    char *pgenerate = "generate";
    char *pundo = "undo";
    char *predo = "redo";
    char *psave = "save";
    char *phint = "hint";
    char *pguess_h = "guess_hint";
    char *pnum = "num_solutions";
    char *pauto = "autofill";
    char *preset = "reset";
    char *pexit = "exit";
    char delimit[] = " \t\r\n\v\f";
    fflush(stdin);
    while (!feof(stdin)) {
        /*each if for command
         * invalid command, to many parameters for this command, less parameters*/

        if (fgets(text, BUFFERSIZE, stdin) != NULL) {
            pcommand = strtok(text, delimit);
            if (pcommand == NULL) {/*no text in stdin*/
                continue;
            }

            if((ptoken = strtok(NULL, delimit))!= NULL)
                status += sscanf(ptoken, "%d", &x);
                status += sscanf(ptoken, "%s", path);
                status += sscanf(ptoken,"%f", &f);

            if((ptoken = strtok(NULL, delimit))!= NULL)
                status += sscanf(ptoken, "%d", &y);

            if((ptoken = strtok(NULL, delimit))!= NULL)
                status += sscanf(ptoken, "%d", &value);

            if (str_compare(pcommand, psolve)) {
                if (status ==2){
                    /*and legal value?*/
                    mod = 3;
                    load(path);
                }
                else{
                    return error_params(pcommand,status-1,1);
                }
                return FALSE;
            }

            if (str_compare(pcommand, pedit)) {
                if (status <=2 ){
                    /*and legal value?*/
                    mod = 2;
                    load(path);/*case when edit with no params load gets NULL and generates 9*9 board*/
                }
                else{/*edit error parameter*/
                    printf("edit command needs path file as a parameter or no parameter.");
                    return FALSE;
                }
                return FALSE;
            }

            if (str_compare(pcommand, pmark)) {
                if (mod!=3){
                    return error_mod(pcommand,&"solve mode");
                }
                if(status !=2){
                    return error_params(pcommand,status-1,1);
                }
                if(x!=1 || x!=0){
                   printf("mark_errors needs to get 1 or 0 as a parameter, 1 to show errors else 0.") ;
                }
                else{
                    board->markErrors = x;
                }
                return FALSE;
            }

            if (str_compare(pcommand, pprint)) {
                if (mod==1){
                    error_mod(pcommand,&"edit and solve modes");
                }
                if(status !=1){
                    return error_params(pcommand,status-1,0);
                }

                }
            print_board(board);
                return FALSE;
            }


            if (str_compare(pcommand, pset) == 0) {/*set command with 3 legal values*/
                if(mod==1){
                   return error_mod(pcommand,&"edit and solve modes");
                }
                if(status!=4){
                    error_params(pcommand,status-1,3);
                }
                if(x>-1 && y>-1 && value>-1){
                 if (set(x - 1, y - 1, value, board) == TRUE)/*legal ints are checked inside the function*/
                    {/*set was done successfully*/
                        if (is_game_over(board) == TRUE) {
                            return TRUE;
                        } else {/*if game is not over*/
                            print_board(board);
                            return FALSE;
                        }
                    }
                    }
                else {
                    printf("set command needs 3 numbers as parameters.");
                    return FALSE;/*if set didn't happen*/
                }
                }

            if (str_compare(pcommand, pvalidate)) {
                if (mod==1){
                    error_mod(pcommand,&"edit and solve modes");
                }
                if(status !=1){
                    return error_params(pcommand,status-1,0);
                }
                validate(board);
                return FALSE;
            }
        if (str_compare(pcommand, pguess)) {
            if (mod!=3){
                error_mod(pcommand,&"solve mode");
            }
            if(status !=2){
                return error_params(pcommand,status-1,1);
            }
            if(f==-1) {
            printf("guess command needs a float between 0 and 1");
            }
            validate(board);
            return FALSE;
        }

    }

                if ((str_compare(pcommand, phint)) == 0 && (status >= 2)) {/*hint command and enough parameters*/
                    hint(x - 1, y - 1, board);
                    return FALSE;
                }


            if (str_compare(pcommand, prestart) == 0) {
                return 2;
            }
            if (str_compare(pcommand, pexit) == 0) {
                return exit_game();
            } else {/*invalid command*/
                printf("Error: invalid command\n");
                return FALSE;
            }

        }
    }


    return exit_game();
}

int str_compare(char *first, char *second) {
    int i;
    for (i = 0; first[i] == second[i]; i++) {
        if (first[i] == '\0') {
            return 0;
        }
    }
    return 1;
}
int error_invalid_command(char * pcommand){
    printf("'%s' is invalid command",pcommand);
    return FALSE;
}
int error_mod(char * pcommand,char * modes){
    printf(The command %s is available at %s only,pcommand,modes);
    return FALSE;
}
int error_params(char * pcommand,int status,int params_num){
    int params_given = status -1;
    printf("The command %s needs %d parameters and you gave %d parameters.",pcommand,params_num,params_given);
    return FALSE;
}


