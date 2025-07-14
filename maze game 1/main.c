#include <stdio.h>
#include <stdlib.h>
#include "headerFile.h"
#include <string.h>
#include <termios.h>
#include "terminal.h"







int main(int argc, char *argv[]){

    if(argc<2){
        printf("you didnt enter the map file");
    }
    else if(argc>2){
        printf("too many argumnets");
    }
    else{
    
    disableBuffer();

	LinkedList* list;
    list = (LinkedList*)malloc(sizeof(LinkedList));
    (*list).head = NULL;

    int ** table;
    int ***metadataTable;

    int metadataAmot;   
    int mapRw;            
    int mapCl;
    

    int *metadataAmount = &metadataAmot;   
    int *mapRow = &mapRw;            
    int *mapCol = &mapCl;  
    
    int  row;
    int col;
    int object;



/* ##########################################################################################################################*/
/*                                                                                                                          */
/*             Author: Thamara Daham                                                                                          */
/*             purpose: to read meta Data from the unput File                                                                 */
/*             date:2021/9/28                                                                                                 */
/*             import: meta Data                                                                                              */
/*             Export: none                                                                                                    */                             
/*                                                                                                                            */
/*                                                                                                                            */


    
    FILE *Filepointer;
    Filepointer = fopen(argv[1],"r");
    if(Filepointer == NULL){
        perror("file didnt found");
    }
    
        fscanf(Filepointer,"%i %i %i",&metadataAmot,&mapRw,&mapCl);
        
        table = (int **) malloc(sizeof(int *) * (*metadataAmount));
        metadataTable=(int ***)malloc(sizeof(int*)*(*metadataAmount));
        
        int i;
         for(i = 0 ; i < (*metadataAmount) ; i++){
         table[i] = (int *) malloc(sizeof(int) * 3);
        }
        do{
               
           
            int jj;
            for(jj =0; jj<*metadataAmount;jj++){
                
                fscanf(Filepointer,"%i %i %i",&row,&col,&object);
                
                table[jj][0]=row;
                table[jj][1]=col;
                table[jj][2]=object;
               
            }
            
            
        }
        while(feof(Filepointer));
        *metadataTable= table;   
        fclose(Filepointer);
    
 
   

/* ##########################################################################################################################*/
    
    
    
    
    
    

    int z;                                                         
    int j;
    int ** mazeTable = (int **) malloc (sizeof(int*)*(*mapRow));  /* creating a custon marix table that use for printing the maze*/
        for(z=0 ; z< *mapRow ; z++){
            mazeTable[z]= (int*)malloc(sizeof(int*)*(*mapCol));
        }
    int c;
    int d;
    for(c=0; c<*mapRow; c++){
        for(d=0; d<*mapCol; d++){
            mazeTable[c][d]=32; /* 32 => SPACE */
        }
    }
    
    
    
    int m;
    int n;
    for(m=0; m < *mapRow; m++){
        mazeTable[m][0]= 124;           /* Creating the column Edges '|' */
        mazeTable[m][(*mapCol)-1]=124; 
    }
    for(n=0; n < *mapCol; n++){
        mazeTable[0][n] = 45;             /* Creating the row Edges '-' */
        mazeTable[(*mapRow)-1][n] =45;
    }

    mazeTable[0][0]=35;
    mazeTable[0][(*mapCol)-1]=35;      /* make L Joints a '#' */
    mazeTable[(*mapRow)-1][0]=35;
    mazeTable[(*mapRow)-1][(*mapCol)-1] =35;  



    unsigned char *actionPtr=(unsigned char *) malloc(sizeof(unsigned char));
    int *rowPositionPtr = (int*)malloc(sizeof(int));
    
    int *columnPositionPtr= (int*)malloc(sizeof(int));
    

    int *playerCharacterPtr=(int *) malloc(sizeof(int));          /*these pointers are the variables that use among all the files*/
    *playerCharacterPtr=94;

    int *snakerowPositionPtr = (int*)malloc(sizeof(int));
    
    int *snakecolumnPositionPtr= (int*)malloc(sizeof(int));
   
     
      
      
      
      
      
      
      
      
      /*Change meta data vlaues to real ASCII values*/
      
        for(j=0 ; j < *metadataAmount ; j++){
             
            if((*metadataTable)[j][2] ==0){
                mazeTable[ (*metadataTable)[j][0] ] [ (*metadataTable)[j][1] ]  = 94;/* '^' */
                *rowPositionPtr = (*metadataTable)[j][0];
                *columnPositionPtr = (*metadataTable)[j][1];
            }
            if((*metadataTable)[j][2] ==1){
                mazeTable[ (*metadataTable)[j][0] ] [ (*metadataTable)[j][1] ]  =126;/* '~' */
                *snakerowPositionPtr=(*metadataTable)[j][0];
                *snakecolumnPositionPtr =(*metadataTable)[j][1];
            }
            if((*metadataTable)[j][2] ==2){
                mazeTable[ (*metadataTable)[j][0] ] [ (*metadataTable)[j][1] ]  = 88;/* 'X' */
            }
            if((*metadataTable)[j][2] ==3){
                mazeTable[ (*metadataTable)[j][0] ] [ (*metadataTable)[j][1] ]  = 79;/* 'O' */
            }
            
        }
    
        /*Store current variables in the stack*/
        push(list,(*rowPositionPtr),(*columnPositionPtr),(*snakerowPositionPtr),(*snakecolumnPositionPtr),*(playerCharacterPtr));


        /*printing the Maze */    
        while (*actionPtr !='q'){
        
        
            printf("\ncontrol your playr using W A S D U\n");
            

            mazeTable[*rowPositionPtr][*columnPositionPtr] =*playerCharacterPtr;
            mazeTable[*snakerowPositionPtr][*snakecolumnPositionPtr] =126;
            int y;
            int x;
            for(y = 0 ; y < *mapRow; y++){
                printf("\n");
                for(x = 0 ; x < *mapCol ; x++ ){
                    printf("%c",mazeTable[y][x]);
                    }
            }
                    
            Control(mazeTable,actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr,snakerowPositionPtr,snakecolumnPositionPtr,list);
            
            }
       
	
 
    
            
           
            
       
    freeAll(mazeTable,actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr,snakerowPositionPtr,snakecolumnPositionPtr,list,metadataTable,table);
    enableBuffer();
    return 0;
}
}
void freeAll(int(**maze),unsigned char *actionPtr,int *rowPositionPtr,int *columnPositionPtr,
    int *playerCharacterPtr,int *snakerowPositionPtr,int *snakecolumnPositionPtr,LinkedList* list,int ***metadataTable,int ** table){

    freeLinkedList(list);
    free(maze);
    free(table);
    free(metadataTable);
    free(actionPtr);
    free(rowPositionPtr);
    free(columnPositionPtr);
    free(playerCharacterPtr);
    free(snakecolumnPositionPtr); 
    free(snakerowPositionPtr);
    }

void Free(unsigned char *actionPtr,int *rowPositionPtr,int *columnPositionPtr,
    int *playerCharacterPtr,int *snakerowPositionPtr,int *snakecolumnPositionPtr,LinkedList* list){

    freeLinkedList(list);
    free(actionPtr);
    free(rowPositionPtr);
    free(columnPositionPtr);
    free(playerCharacterPtr);
    free(snakecolumnPositionPtr); 
    free(snakerowPositionPtr);
    }
