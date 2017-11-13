////////////////////////////////////////////
//                                        //
//      DFA Double Recognizer Project     //
//      CS311 (M/W)                       //
//                                        //
//      Written by:                       //
//      Ben Portis and Alexander Mason    //
//                                        //
//      File:                             //
//      main.c                            //
//                                        //
////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Adj List ([TARGET], [PARAMETERS FOR TARGET])
  * 0 [A]: [B, 0-9] -> [C, +/-] -> [D, .] -> NULL
 A* 1 [B]: [B, 0-9] -> [F, e/E] -> [I, .] -> NULL        
  * 2 [C]: [B, 0-9] -> [D, .] -> NULL
  * 3 [D]: [E, 0-9] -> NULL
 A* 4 [E]: [E, 0-9] -> [F, e/E] -> NULL
  * 5 [F]: [F, 0-9] -> [G, 0-9] -> [H, +/-] -> NULL
 A* 6 [G]: [G, 0-9] -> NULL
  * 7 [H]: [G, 0-9] -> NULL
 A* 8 [I]: [I, 0-9] -> [F, e/E] -> NULL
 */

typedef struct Edge Edge;
typedef struct State State;

//Represents the connections between states
typedef struct Edge
{
    int index;
    char * cond;
    Edge * next;
}Edge;

//Represents the states
typedef struct State
{
    char name;
    bool accepting;
    Edge * head;

}State;


int main(int argc,  char * argv[])
{

    State * machine = malloc(sizeof(State[9]));
    for(int i = 0; i < 9; ++i)
    {
        machine[i].name = 'a';
        machine[i].accepting = false;
        machine[i].head = NULL;

    }

////////// State A ////////////////////////
 
 //A temp pointer to initialize each Edge
    Edge * temp = NULL;
    
    machine[0].name = 'A'; 
    machine[0].accepting = false;
    machine[0].head = (Edge *)malloc(sizeof(Edge));
    temp = machine[0].head;
    //3 because A only has 3 non-dead edges
    for(int i = 1; i < 3; ++i)
    {
        //Create new edge
        
        temp->next = (Edge *)malloc(sizeof(Edge));
        //Move the temp pointer to the next spot
        temp->index = 0;
        temp->cond = NULL;

        temp = temp->next;
    }
    //Cap off the list
    temp = NULL;
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
   
///////// State B ////////////////////////////
    Edge * temp2 = NULL;

    machine[1].name = 'B';
    machine[1].accepting = true;
    machine[1].head = (Edge *)malloc(sizeof(Edge));
    temp2 = machine[1].head;
    
    //Only 3 non-dead edges
    for(int i = 1; i < 3; ++i){
        temp2->next = (Edge *)malloc(sizeof(Edge));
        temp2->index = 0;
        temp2->cond = NULL;
        temp2 = temp2->next;
    }
    temp2 = NULL;
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
    temp2->cond = "Ee"; 
    temp2->next = NULL;


//////// State C ////////////////////////////
    Edge * temp3 = NULL;

    machine[2].name = 'C';
    machine[2].accepting = false;
    machine[2].head = (Edge *)malloc(sizeof(Edge));
    temp3 = machine[2].head;
    
    //Only 2 non-dead edges
    for(int i = 1; i < 2; ++i)
    {
        
        temp3->next = (Edge *)malloc(sizeof(Edge));
        temp3->index = 0;
        temp3->cond = NULL;
        temp3 = temp3->next;
    
    }

    temp3 = NULL;

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
  //  Edge * temp4 = NULL;

    machine[3].name = 'D';
    machine[3].accepting = false;
    machine[3].head = (Edge *)malloc(sizeof(Edge));

    //Edge going to E
    machine[3].head->index = 4;
    machine[3].head->cond = "0123456789";
    machine[3].head->next = NULL;

////////// State E ////////////////////
    Edge * temp5;
    machine[4].name = 'E';
    machine[4].accepting = true;
    machine[4].head = (Edge *)malloc(sizeof(Edge));

    temp5 = machine[4].head;

    //State E has 2 non-dead edges
    for(int i = 1; i < 2; ++i)
    {
        temp5->next = (Edge *)malloc(sizeof(Edge));
        temp5->index = 0;
        temp5->cond = NULL;
        temp5 = temp5->next;
    }

    temp5 = NULL;

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
    machine[5].head = (Edge *)malloc(sizeof(Edge));

    temp6 = machine[5].head;

    //State F has 2 non-dead edges
    for(int i = 1; i < 2; ++i)
    {
        temp6->next = (Edge *)malloc(sizeof(Edge));
        temp6->index = 0;
        temp6->cond = NULL;
        temp6 = temp6->next;
    }

    temp6 = NULL;

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
    machine[6].head = (Edge *)malloc(sizeof(Edge));

    //Edge going back to g
    machine[6].head->index = 6;
    machine[6].head->cond = "0123456789";
    machine[6].head->next = NULL;


//////// State H //////////////////////
    machine[7].name = 'H';
    machine[7].accepting = false;
    machine[7].head = (Edge *)malloc(sizeof(Edge));

    machine[7].head->index = 6;
    machine[7].head->cond = "0123456789";
    machine[7].head->next = NULL;


//////// State I /////////////////////
    Edge * temp9 = NULL;
    machine[8].name = 'I';
    machine[8].accepting = true;
    machine[8].head = (Edge *)malloc(sizeof(Edge));
    temp9 = machine[8].head;

    //State I has 2 non-dead edges
    for(int i = 1; i < 2; ++i)
    {
        temp9->next = (Edge *)malloc(sizeof(Edge));
        temp9->index = 0;
        temp9->cond = NULL;
        temp9 = temp->next;
    }
    
    temp9 = NULL;
    temp9 = machine[8].head;

    //Edge going back to I
    temp9->index = 8;
    temp9->cond = "0123456789";
    temp9 = temp9->next;

    //Edge going to F
    temp9->index = 5;
    temp9->cond = "eE";
    temp9->next = NULL;

/*
    printf("--STATE DIAGRAM--");
//Printing out the machine
for(int i = 0; i < 9; ++i){

    printf("\n\nState: %c\n", machine[i].name);
    Edge * checkTemp = machine[i].head;
    while(checkTemp != NULL)
    {
        printf("\nEdge Target: %d", checkTemp->index);
        printf("\nEdge Cond: %s", checkTemp->cond);
        checkTemp = checkTemp->next;
    }
}
*/

    //If there is a file to open as an argument
    if(argc == 2){ 
        //Grab the file name from argv[1]
        char tempName[100];
        strcpy(tempName, argv[1]);
        FILE *file = fopen(tempName,"r");


        if(file != NULL){
            char line[256];
            //read line by line 
            while(fgets(line, sizeof line, file) != NULL) {
                //Index number indicating current state
                int currState = 0;
                //Make sure we aren't dead
                bool dead = false;
                int i = 0;
                printf("\n%s", line);
                Edge * holdState = machine[currState].head;
                //While we haven't hit the dead state an there are more chars
                while(!dead && line[i] != '\n'){
                    //Go to the beginning of the list of edges for current state
                    //If we haven't reached the end of the edges in an edge list
                    if(holdState != NULL){
                        //If I should follow this edge
                        if(strchr((*holdState).cond, line[i])){
                            //Move to the new state after consuming
                            currState = (*holdState).index; 
                            ++i;
                            holdState = machine[currState].head;
                        }
                        else{
                            //Shouldn't follow edge, go to next edge
                            holdState = (*holdState).next;
                        }
                    }
                    else
                        //End of an edge list, hit dead state
                        dead = true;
                }

                //If the current state is accepting and we aren't dead
                if(machine[currState].accepting && !dead)
                    printf("Accept\n");
                else 
                    printf("Reject\n");

            }
            fclose(file);
        }
        else{
            perror(tempName);//if file didn't open
        }
    }else{
        printf("No file specified. Exiting...");
    }

    return 0;
}

