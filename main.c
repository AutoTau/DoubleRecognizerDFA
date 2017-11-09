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

/*
 * Adj List
 * [A]: [B, 0-9] -> [C, +/-] -> [D, .] -> [DEAD, e/E]
 * [B]: [B, 0-9] -> [F, e/E] -> [I, .] -> [DEAD, +/-]
 * [C]: [B, 0-9] -> [D, .] -> [DEAD, e/E/+/-]
 * [D]: 
 * [E]
 * [F]
 * [G]
 * [H]
 * [I]:
 * [DEAD]
 */

int main(arg c, arg[v])
{

    if(c){
        static const char fileName[] = "input.txt";
        FILE *file = fopen (fileName,"r");
        if(file != NULL)
        {
            char linez[256];

            //read line by line 
            while(fgets(linez, sizeof linez, file) != NULL) 
            {
                //do all the things
                
                fputs(linez, stdout); //write out line by line
            }
            fclose(file);
        }
        else
        {
            perror(fileName);//if file didn't open
        }
    }else
    {
        printf("No file specified. Exiting...");
    }

    return 0;
}
