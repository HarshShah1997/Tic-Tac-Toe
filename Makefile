OBJS = ticTacToe.o board.o
CC = g++
OGL= -lGL -lGLU -lglut

ticTacToe: $(OBJS)
	$(CC) ticTacToe.o board.o -o ticTacToe

ticTacToe.o: ticTacToe.cpp ticTacToe.h board.h
	$(CC) -c ticTacToe.cpp $(OGL)

board.o: board.cpp board.h
	$(CC) -c board.cpp $(OGL)

clean:
	\rm *.o *~ ticTacToe



