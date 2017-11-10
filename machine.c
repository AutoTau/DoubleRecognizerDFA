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

//Creates the state machine 
//Input: A State array by reference
//Output: N/A
void CreateMachine(State * &machine){
    //A temp pointer to initialize each Edge
    Edge temp = NULL;

    //State A
    machine[0].name = 'A'; 
    machine[0].accepting = false;
    temp = machine[0].head;
    //3 because A only has 3 non-dead edges
    for(int i = 0; i <= 3; ++i){
        //Create a new Edge here
        temp = malloc(Edge);
        //Move the temp pointer to the next spot
        temp = temp->next;
    }
    //Cap off the list
    temp->next = NULL;
    //Point the temp back at the head
    temp = machine[0].head;
    //Edge going to B
    temp->index = 1;
    temp->cond = "0123456789";
    temp = temp->next;
    //Edge going to C 
    temp->index = 2;
    temp->cond = "+-";
    temp = temp->next;
    //Edge going to D
    temp->index = 3;
    temp->cond = ".";
    temp->next = NULL;

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
