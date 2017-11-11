////////////////////////////////////////////
//                                        //
//      DFA Double Recognizer Project     //
//      CS311 (M/W)                       //
//                                        //
//      Written by:                       //
//      Ben Portis and Alexander Mason    //
//                                        //
//      File:                             //
//      machine.h                         //
//                                        //
////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Edge Edge;
typedef struct State State;

//Represents the connections between states
typedef struct Edge
{
    int index;
    char * cond;
    //= new char[10];
    //strcpy(cond,newcond);
    Edge * next;// = NULL;
}Edge;

//Represents the states
typedef struct State
{
    char name;
    bool accepting;
    Edge * head;// = NULL;

}State;



//Creates the state machine 
//Input: A State array by reference
//Output: N/A
 void CreateMachine(State * machine);
