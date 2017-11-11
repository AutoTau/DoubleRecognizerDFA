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


//Creates the state machine
//Input: A State array by reference
//Output: N/A
void CreateMachine(State * machine){

 ////////// State A /////////////////////
 
 //A temp pointer to initialize each Edge
    Edge * temp = NULL;

    machine[0].name = 'A'; 
    machine[0].accepting = false;
    temp = machine[0].head;
    //3 because A only has 3 non-dead edges
    for(int i = 0; i < 3; ++i)
    {
        //Create new edge
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
   

///////// State B /////////////////////////
    Edge * temp2 = NULL;

    machine[1].name = 'B';
    machine[1].accepting = true;
    temp2 = machine[1].head;
    
    //Only 3 non-dead edges
    for(int i = 0; i < 3; ++i)
    {
        temp2 = malloc(Edge);
        
        temp2 = temp2->next;
    
    }

    temp2->next = NULL;
    temp2 = machine[1].head;

    //Edge going to B
    temp2->index = 1;
    temp2->cond = "0123456789";
    temp2 = temp2->next;
    //Edge going to I
    temp2->index = 8;
    temp2->cond = ".";
    temp2 = temp2->next;
    //Edge going to F
    temp2->index = 5;
    temp2->cond = "Ee"; //fix this
    temp2->next = NULL;



//////// State C /////////////////////
    Edge * temp3 = NULL;

    machine[2].name = 'C';
    machine[2].accepting = false;
    temp3 = machine[2].head;
    
    //Only 2 non-dead edges
    for(int i = 0; i < 2; ++i)
    {
        temp3 = malloc(Edge);
        
        temp3 = temp3->next;
    
    }

    temp3->next = NULL;

    temp3 = machine[2].head;

    //Edge going to B
    temp3->index = 1;
    temp3->cond = "0123456789";
    temp3 = temp3->next;
    //Edge going to D
    temp3->index = 3;
    temp3->cond = ".";
    temp3->next = NULL; 
    

////////// State D //////////////////////
    Edge * temp4 = NULL;

    machine[3].name = 'D';
    machine[3].accepting = false;
    temp4 = machine[3].head;

    //D has only 1 non-dead edge
    temp4 = malloc(Edge);
    temp4 = temp4->next;

    temp4->next = NULL;

    temp4 = machine[3].head;

    //Edge going to E
    temp4->index = 4;
    temp4->cond = "0123456789";
    temp4->next = NULL;


////////// State E ////////////////////
    Edge * temp5;
    machine[4].name = 'E';
    machine[4].accepting = true;

    //State E has 2 non-dead edges
    for(int i = 0; i < 2; ++i)
    {
        temp5 = malloc(Edge);

        temp5 = temp5->next;
    }

    temp5->next = NULL;

    temp5 = machine[4].head;


    //Edge going back to E
    temp5->index = 4;
    temp5->cond = "0123456789";
    temp5 = temp5->next;

    //Edge going to F
    temp5->index = 5;
    temp5->cond = "Ee"; //fix this!
    temp5->next = NULL;


/////////// State F ///////////////////
    Edge * temp6 = NULL;
    machine[5].name = 'F';
    machine[5].accepting = false;
    temp6 = machine[5].head;

    //State F has 2 non-dead edges
    for(int i = 0; i < 2; ++i)
    {
        temp6 = malloc(Edge);

        temp6 = temp6->next;
    }

    temp6->next = NULL;

    temp6 = machine[5].head;

    //Edge going to G
    temp6->index = 6;
    temp6->cond = "0123456789";
    temp6 = temp6->next;
    
    //Edge going to H
    temp6->index = 7;
    temp6->cond  = "+-";
    temp6->next = NULL;


////////// State G ////////////////////
    Edge * temp7 = NULL;

    machine[6].name = 'G';
    machine[6].accepting = true;
    temp7 = machine[6].head;


    //State G has 1 non-dead edge
    temp7 = malloc(Edge);

    temp7->next = NULL;
    
    temp7 = machine[6].head;

    //Edge going back to g
    temp7->index = 6;
    temp7->cond = "0123456789";
    temp7->next = NULL;



//////// State H //////////////////////
    Edge * temp8 = NULL;
    machine[7].name = 'H';
    machine[7].accepting = false;
    temp8 = machine[7].head;

    //State H has 1 non-dead edge
    temp8 = malloc(Edge);

    temp8->next = NULL;

    temp8 = machine[7].head;

    temp8->index = 7;
    temp8->cond = "0123456789";
    temp8->next = NULL;


//////// State I /////////////////////
    Edge * temp9 = NULL;
    machine[8].name = 'I';
    machine[8].accepting = true;
    temp9 = machine[8].head;

    //State I has 2 non-dead edges
    for(int i = 0; i < 2; ++i)
    {
        temp9 = malloc(edge);

        temp = temp->next;
    }
    
    temp9->next = NULL;
    temp9 = machine[8].head;

    //Edge going back to I
    temp9->index = 8;
    temp9->cond = "0123456789";
    temp9 = temp9->next;

    //Edge going to F
    temp9->index = 5;
    temp9->cond = "eE";
    temp9->next = NULL;


}
