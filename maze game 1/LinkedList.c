#include <stdio.h>
#include <stdlib.h>


/* ##########################################################################################################################*/
/*             File Name: LinkedList.c (Stack)                                                                                                              */
/*             Author: Thamara Daham                                                                                          */
/*             purpose: to store Player Positions and snake(enemy) Positions to implement a undo feature                      */
/*             date:2021/10/5                                                                                                 */
/*             import: player-rowPosition(integer)                                                                            */
/*                     player-columnPosition(integer)                                                                         */                             
/*                     player-character(Unsigned Character)                                                                                                       */
/*                     snake -rowPosition(integer)                                                                            */
/*                     snake -columnPosition(integer)                                                                         */                  
/*                                                                                                                            */
/*             Export: header Node of the stack in pop() function                                                                                                            */                   
/*                                                                                                                            */                 
/*                                                                                                                            */

/* ##########################################################################################################################*/

typedef struct Node{
  int RowPosition;
  int columnPosition;

  int snakeRowPosition;
  int snakeColPosition;
  unsigned char playerCharacter;
  struct Node* next;
}Node;


 typedef struct {
  Node* head;
}LinkedList;



/*Insert at the Front*/
void push(LinkedList *list,int RowPosition,int columnPosition,int snakeRowPosition,int snakeColPosition,unsigned char playerCharacter)
{
   Node* newNode;
   newNode =(Node*)malloc(sizeof(Node));
   (*newNode).RowPosition=RowPosition;
   (*newNode).columnPosition=columnPosition;
   (*newNode).snakeRowPosition=snakeRowPosition;
   (*newNode).snakeColPosition=snakeColPosition;
   (*newNode).playerCharacter=playerCharacter;
   (*newNode).next =  (*list).head;;
     (*list).head = newNode;

}
/*return the last in Node and delete it */
Node* pop(LinkedList *list){
  Node* node;
  
  if((*list).head ==NULL){
    printf("stack is null");
  }
  else{
    
    node = (*list).head;
    (*list).head = (*list).head->next;
    
    
    
  }
  return node;
}
void freeLinkedList(LinkedList *list)
{
  Node *current, *nextNode;
  current = (*list).head;
  

  while( current != NULL)
  {
    nextNode = (*current).next;
    printf("Deleting Node : %i \n", (*current));
    free(current);
    current = nextNode; 
  }

  printf("Deleteing LinkedList \n");
  
}

