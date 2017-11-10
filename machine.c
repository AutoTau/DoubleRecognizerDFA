////////////////////////////////////////////
//                                        //
//      DFA Double Recognizer Project     //
//      CS311 (M/W)                       //
//                                        //
//      Written by:                       //
//      Ben Portis and Alexander Mason    //
//                                        //
//      File:                             //
//      machine.c                         //
//                                        //
////////////////////////////////////////////

#include "machine.h"

//Creates the state machine 
//Input: A State array by reference
//Output: N/A
void CreateMachine(State * &machine){
    //State A
    machine[0].name = 'A'; 
    machine[0].accepting = false;
    machine[0].head = new Edge;
    machine[0].head->index = 1; 

    //State B
    machine[1].name = 'B';
    machine[1].accepting = true;
    machine[1].head = new Edge;

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
    machine[8].accepting = true;

    //Dead State
    machine[9].name = 'X';
    machine[9].accepting = false;
    machine[9].head = NULL;
}
