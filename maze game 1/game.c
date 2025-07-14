

#include <stdio.h>
#include <stdlib.h>
#include "headerFile.h"
#include <termios.h>
#include "terminal.h"

/* ##########################################################################################################################*/
/*             File Name: game.c                                                                                              */
/*             Author: Thamara Daham                                                                                          */
/*             purpose: to store Player Positions and snake(enemy) Positions to implement a undo feature                      */
/*             date:2021/9/28                                                                                                 */
/*             import: player-rowPositionPtr(integer pointer)                                                                 */
/*                     player-columnPositionPtr(integer pointer)                                                              */                             
/*                     player-playerCharacterPtr(Unsigned Character pointer)                                                  */
/*                     player-actionPtr(Unsigned Character pointer)                                                           */
/*                     snake -rowPositionPtr(integer)                                                                         */
/*                     snake -columnPositionPtr(integer)                                                                      */                  
/*                     mazetable(integer 2d array double pointer)                                                             */
/*                     list(inkedList/stack)                                                                                  */                   
/*             Export: None                                                                                                   */                 
/*                                                                                                                            */

/* ##########################################################################################################################*/


void Control(int (**maze),unsigned char *actionPtr,int *rowPositionPtr,int *columnPositionPtr,
    int *playerCharacterPtr,int *snakerowPositionPtr,int *snakecolumnPositionPtr,LinkedList* list){
    
/*

I have used ASCII values sometimes insted of char values

	 94 => ^
   	 88 => x
 	 79 => o
  	 124 => |
	
	60 => <
	62 => >
	118 => v
	
	

 */
    

   


    
    

    printf("\nAction;");
    scanf("%c",actionPtr);
    system("clear");
    int prevRowPosition = *rowPositionPtr;
    int prevColumnPosition= *columnPositionPtr;
    int space =32;
    int RowgonnaBePostition;
    int columngonnaBePosition;
   
    int snakeprevRowPosition = *snakerowPositionPtr;
    int snakeprevColumnPosition= *snakecolumnPositionPtr;
    int snakeRowgonnaBePostition;
    int snakecolumngonnaBePosition;

    

    Node* node2;

    if(*actionPtr != 'q') {
        
            switch (*actionPtr){
                case 'a':
                    columngonnaBePosition=(*columnPositionPtr)-1;
                    snakecolumngonnaBePosition=(*snakecolumnPositionPtr)-1;
                    if (maze[*rowPositionPtr][columngonnaBePosition] != 124 && maze[*rowPositionPtr][columngonnaBePosition] != 79 && maze[*rowPositionPtr][columngonnaBePosition] != 45){
                        (*columnPositionPtr)--;
                        
                        maze[prevRowPosition][prevColumnPosition] = space;
                        *playerCharacterPtr=60;
                        if(maze[*rowPositionPtr][*columnPositionPtr]==88){
                            printf("you won\n");
                            *actionPtr ='q';
                            Free(actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr,snakerowPositionPtr,snakecolumnPositionPtr,list);
                        }
                        if(maze[*rowPositionPtr][*columnPositionPtr]==126){
                            printf("you lose\n");
                            *actionPtr ='q';
                            Free(actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr,snakerowPositionPtr,snakecolumnPositionPtr,list);    
                        }


                    
                    }
                    if (maze[*snakerowPositionPtr][snakecolumngonnaBePosition] != 124 && maze[*snakerowPositionPtr][snakecolumngonnaBePosition] != 79 && maze[*snakerowPositionPtr][snakecolumngonnaBePosition] != 88 && maze[*snakerowPositionPtr][snakecolumngonnaBePosition] != 45){
                        (*snakecolumnPositionPtr)--;
                        
                        maze[snakeprevRowPosition][snakeprevColumnPosition] = space;
                        
                        
                        if(maze[*snakerowPositionPtr][*snakecolumnPositionPtr]==126){
                            printf("you lose\n");
                            *actionPtr ='q'; 
                            Free(actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr,snakerowPositionPtr,snakecolumnPositionPtr,list);   
                        }
                    
                    }
                    push(list,(*rowPositionPtr),(*columnPositionPtr),(*snakerowPositionPtr),(*snakecolumnPositionPtr),*(playerCharacterPtr));
            
                    
                    break;
            
                case 'd':
                    columngonnaBePosition=(*columnPositionPtr)+1;
                    snakecolumngonnaBePosition=(*snakecolumnPositionPtr)+1;
                    if (maze[*rowPositionPtr][columngonnaBePosition] != 124 && maze[*rowPositionPtr][columngonnaBePosition] != 79 && maze[*rowPositionPtr][columngonnaBePosition] != 45){
                        (*columnPositionPtr)++;
                        
                        maze[prevRowPosition][prevColumnPosition] = space;
                        *playerCharacterPtr=62;
                        if(maze[*rowPositionPtr][*columnPositionPtr]==88){
                            printf("you won\n");
                            *actionPtr ='q';
                            Free(actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr,snakerowPositionPtr,snakecolumnPositionPtr,list);
                        }
                        if(maze[*rowPositionPtr][*columnPositionPtr]==126){
                            printf("you lose");
                            *actionPtr ='q';
                            Free(actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr,snakerowPositionPtr,snakecolumnPositionPtr,list);
                        }
                    }
                    if (maze[*snakerowPositionPtr][snakecolumngonnaBePosition] != 124 && maze[*snakerowPositionPtr][snakecolumngonnaBePosition] != 79 && maze[*snakerowPositionPtr][snakecolumngonnaBePosition] != 88 && maze[*snakerowPositionPtr][snakecolumngonnaBePosition] != 45){
                        (*snakecolumnPositionPtr)++;
                        
                        maze[snakeprevRowPosition][snakeprevColumnPosition] = space;
                       
                        
                        if(maze[*snakerowPositionPtr][*snakecolumnPositionPtr]==126){
                            printf("you lose\n");
                            *actionPtr ='q';
                            Free(actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr,snakerowPositionPtr,snakecolumnPositionPtr,list);
                        }
                    }

                    push(list,(*rowPositionPtr),(*columnPositionPtr),(*snakerowPositionPtr),(*snakecolumnPositionPtr),*(playerCharacterPtr));
            
                    break;

                case 's':
                    RowgonnaBePostition=(*rowPositionPtr)+1;
                    snakeRowgonnaBePostition=(*snakerowPositionPtr)+1;
                    if (maze[RowgonnaBePostition][*columnPositionPtr] != 124 && maze[RowgonnaBePostition][*columnPositionPtr] != 79 && maze[RowgonnaBePostition][*columnPositionPtr] != 45){
                        (*rowPositionPtr)++;
                        
                        maze[prevRowPosition][prevColumnPosition] = space;
                         *playerCharacterPtr=118;
                         if(maze[*rowPositionPtr][*columnPositionPtr]==88){
                            printf("you won\n");
                            *actionPtr ='q';
                            Free(actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr,snakerowPositionPtr,snakecolumnPositionPtr,list);
                        }
                         if(maze[*rowPositionPtr][*columnPositionPtr]==126){
                            printf("you lose\n");
                            *actionPtr ='q';
                            Free(actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr,snakerowPositionPtr,snakecolumnPositionPtr,list);
                        }
                    }
                    if (maze[snakeRowgonnaBePostition][*snakecolumnPositionPtr] != 124 && maze[snakeRowgonnaBePostition][*snakecolumnPositionPtr] != 79 && maze[snakeRowgonnaBePostition][*snakecolumnPositionPtr] != 88 && maze[snakeRowgonnaBePostition][*snakecolumnPositionPtr] != 45){
                        (*snakerowPositionPtr)++;
                        
                        maze[snakeprevRowPosition][snakeprevColumnPosition] = space;
                         
                         
                         if(maze[*snakerowPositionPtr][*snakecolumnPositionPtr]==126){
                            printf("you lose\n");
                            *actionPtr ='q';
                            Free(actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr,snakerowPositionPtr,snakecolumnPositionPtr,list);
                        }
                    }

                    push(list,(*rowPositionPtr),(*columnPositionPtr),(*snakerowPositionPtr),(*snakecolumnPositionPtr),*(playerCharacterPtr));
            
                    break;
                
                case 'w':
                
                    RowgonnaBePostition=(*rowPositionPtr)-1;
                    snakeRowgonnaBePostition=(*snakerowPositionPtr)-1;

                    if (maze[RowgonnaBePostition][*columnPositionPtr] != 124 && maze[RowgonnaBePostition][*columnPositionPtr] != 79 && maze[RowgonnaBePostition][*columnPositionPtr] != 45 ){
                        (*rowPositionPtr)--;
                        
                        maze[prevRowPosition][prevColumnPosition] = space;
                        *playerCharacterPtr=94;
                        if(maze[*rowPositionPtr][*columnPositionPtr]==88){
                            printf("you won\n");
                            *actionPtr ='q';
                            Free(actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr,snakerowPositionPtr,snakecolumnPositionPtr,list);
                        }
                        if(maze[*rowPositionPtr][*columnPositionPtr]==126){
                            printf("you lose\n");
                            *actionPtr ='q';
                            Free(actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr,snakerowPositionPtr,snakecolumnPositionPtr,list);
                        }
                    }
                    if (maze[snakeRowgonnaBePostition][*snakecolumnPositionPtr] != 124 && maze[snakeRowgonnaBePostition][*snakecolumnPositionPtr] != 79 && maze[snakeRowgonnaBePostition][*snakecolumnPositionPtr] != 88 && maze[snakeRowgonnaBePostition][*snakecolumnPositionPtr] != 45 ){
                        (*snakerowPositionPtr)--;
                        
                        maze[snakeprevRowPosition][snakeprevColumnPosition] = space;
                        
                        
                        if(maze[*snakerowPositionPtr][*snakecolumnPositionPtr]==126){
                            printf("you lose\n");
                            *actionPtr ='q';
                            Free(actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr,snakerowPositionPtr,snakecolumnPositionPtr,list);
                        }
                    }
                    push(list,(*rowPositionPtr),(*columnPositionPtr),(*snakerowPositionPtr),(*snakecolumnPositionPtr),*(playerCharacterPtr));
            
                    break;

                case 'u':
                         
                        node2 = pop(list);
                        
                        
                        *rowPositionPtr=((*node2).RowPosition);
                        *columnPositionPtr=((*node2).columnPosition);
                        *snakerowPositionPtr=(*node2).snakeRowPosition;
                        *snakecolumnPositionPtr =(*node2).snakeColPosition;
                        *playerCharacterPtr =(*node2).playerCharacter;
                        
                        maze[snakeprevRowPosition][snakeprevColumnPosition] = space;
                        maze[prevRowPosition][prevColumnPosition] = space;
                        

                    break;
                    
        
            }
    }
}


    

