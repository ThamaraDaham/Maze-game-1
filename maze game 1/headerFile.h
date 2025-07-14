#ifndef HEADERFILE_H
#define HEADERFILE_H

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

void push(LinkedList *list,int RowPosition,int columnPosition,int snakeRowPosition,int snakeColPosition,unsigned char playerCharacter);

Node* pop(LinkedList *list);

void freeLinkedList(LinkedList *list);




void Control(int (**maze),unsigned char *actionPtr,int *rowPositionPtr,int *columnPositionPtr,
int *playerCharacterPtr,int *snakerowPositionPtr,int *snakecolumnPositionPtr,LinkedList* list);

void freeAll(int(**maze),unsigned char *actionPtr,int *rowPositionPtr,int *columnPositionPtr,
    int *playerCharacterPtr,int *snakerowPositionPtr,int *snakecolumnPositionPtr,LinkedList* list,int ***metadataTable,int ** table);
  
void Free(unsigned char *actionPtr,int *rowPositionPtr,int *columnPositionPtr,
    int *playerCharacterPtr,int *snakerowPositionPtr,int *snakecolumnPositionPtr,LinkedList* list);


#endif