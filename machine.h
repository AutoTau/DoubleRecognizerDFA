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
#include <string.h>

//Represents the states
struct State
{
    char name = NULL;
    bool accepting = false;
    Edge * head = NULL;
}

//Represents the connections between states
struct Edge
{
    int index = 0;
    String cond = NULL;
    Edge * next = NULL;
}


//Creates the state machine 
//Input: A State array by reference
//Output: N/A
 void CreateMachine(State * &machine);
