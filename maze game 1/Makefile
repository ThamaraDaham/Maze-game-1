##
 # File: Makefile
 # File Created: 2021/9/13
 # Author: thamara dham
 # -----
 # Purpose: To run the maze game
##


# Makefile Variables
CC		 = gcc
EXEC	 = maze
 
OBJ 	 = main.o game.o LinkedList.o terminal.o





$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c terminal.h headerFile.h
	$(CC) $(CFLAGS) main.c -c 

game.o : game.c headerFile.h terminal.h
	$(CC) -c game.c

LinkedList.o : LinkedList.c headerFile.h 
	$(CC) -c LinkedList.c 

terminal.o : terminal.c terminal.h 
	$(CC) -c terminal.c

clean:
	rm -f $(EXEC) $(OBJ)
