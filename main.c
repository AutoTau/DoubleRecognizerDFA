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

/*
 * Adj List ([TARGET], [PARAMETERS FOR TARGET])
 * 0 [A]: [B, 0-9] -> [C, +/-] -> [D, .] -> [DEAD, e/E]
 * 1 [B]: [B, 0-9] -> [F, e/E] -> [I, .] -> [DEAD, +/-]
 * 2 [C]: [B, 0-9] -> [D, .] -> [DEAD, e/E/+/-]
 * 3 [D]: [E, 0-9] -> [DEAD, ./+/-/e/E]
 * 4 [E]: [E, 0-9] -> [F, e/E] -> [DEAD, ./+/-]
 * 5 [F]: [F, 0-9] -> [G, 0-9] -> [H, +/-] -> [DEAD, ./e/E]
 * 6 [G]: [G, 0-9] -> [DEAD, ./+/-/e/E]
 * 7 [H]: [G, 0-9] -> [DEAD, ./+/-/e/E]
 * 8 [I]: [I, 0-9] -> [F, e/E] -> [DEAD, ./+/-]
 * 9 [DEAD]
 */

struct State
{
    char name = NULL;
    bool accepting = false;
    edge * head = NULL;
}

struct Edge
{
    int index = 0;
    String cond = NULL;
    edge * next = NULL;
}

int main(int argc,  char * argv[])
{
    State machine = new state
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

void CreateMachine(State * &machine){
    //State A
    machine[0].name = 'A'; 
    machine[0].accepting = false;
    machine[0].head = new edge;
    machine[0].head->index = 1; 
    machine[0].head->target = ;

    //State B
    machine[1].name = 'B';
    machine[1].accepting = true;

    //State C
    machine[2].name = 'C';
    machine[2].accepting = false;

    //State D
    machine[3].name = 'D';
    machine[3].accepting = false;

    //State E
    machine[4].name = 'E';
    machine[4].accepting = true;

    //State F
    machine[5].name = 'F';
    machine[5].accepting = false;

    //State G
    machine[6].name = 'G';
    machine[6].accepting = true;

    //State H
    machine[7].name = 'H';
    machine[7].accepting = false;

    //State I
    machine[8].name = 'I';
    machine[0].accepting = true;

    //Dead State
    machine[9].name = 'X';
    machine[9].accepting = false;
    machine[9].head = NULL;
}
