////////////////////////////////////////////
//                                        //
//      DFA Double Recognizer Project     //
//      CS311 (M/W)                       //
//                                        //
//      Written by:                       //
//      Ben Portis and Alexander Mason    //
//                                        //
////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include "machine.h";

/*
 * Adj List ([TARGET], [PARAMETERS FOR TARGET])
 * 0 [A]: [B, 0-9] -> [C, +/-] -> [D, .] -> NULL
 * 1 [B]: [B, 0-9] -> [F, e/E] -> [I, .] -> NULL
 * 2 [C]: [B, 0-9] -> [D, .] -> NULL
 * 3 [D]: [E, 0-9] -> NULL
 * 4 [E]: [E, 0-9] -> [F, e/E] -> NULL
 * 5 [F]: [F, 0-9] -> [G, 0-9] -> [H, +/-] -> NULL
 * 6 [G]: [G, 0-9] -> NULL
 * 7 [H]: [G, 0-9] -> NULL
 * 8 [I]: [I, 0-9] -> [F, e/E] -> NULL
 */

int main(int argc,  char * argv[])
{
    State * machine = malloc(State[9]);
    CreateMachine(machine);
    //If there is a file to open as an argument
    if(c == 2){ 
        //Grab the file name from argv[1]
        char * tempName = char[100];
        strcpy(tempName, argv[1]);

        //Cut off extra
        char * fileName = new char[strlen(tempName + 1)];
        FILE *file = fopen (fileName,"r");

        if(file != NULL)
        {
            char linez[256];

            //read line by line 
            while(fgets(linez, sizeof linez, file) != NULL) 
            {
                //Index number indicating current state
                int currState = 0;
                //Create temp edge pointer
                edge * current = NULL;
                //Go to array index that matches the current state.
                while(currState != 9){
                    //Check if first node contain the grabbed char from string
                    while(
                            if(strstr(
                                    //Go to the new array index, repeat
                                    else
                                    current = state.next;
                                    if(state.accept)
                                    printf("Accept");
                                    if(!state.accept)
                                    printf("Reject");
                }
                fputs(linez, stdout); //write out line by line
            }
            fclose(file);
        }
        else
        {
            perror(fileName);//if file didn't open
        }
    }else{
        printf("No file specified. Exiting...");
    }

    return 0;
}

