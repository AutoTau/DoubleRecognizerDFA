////////////////////////////////////////////
//                                        //
//      DFA Double Recognizer Project     //
//      CS311 (M/W)                       //
//                                        //
//      Written by:                       //
//      Ben Portis and Alexander Mason    //
//                                        //
//                                        //
//////////////////////////////////////////

#include <stdio.h>



int main(void)
{

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

    return 0;
}
