OBJS = ticTacToe.o board.o
CC = g++
OGL= -lGL -lGLU -lglut -lSOIL

ticTacToe: $(OBJS)
	$(CC) ticTacToe.o board.o -o ticTacToe $(OGL)

ticTacToe.o: ticTacToe.cpp ticTacToe.h board.h
	$(CC) -c ticTacToe.cpp $(OGL)

board.o: board.cpp board.h
	$(CC) -c board.cpp $(OGL)

clean:
	\rm *.o *~ ticTacToe



