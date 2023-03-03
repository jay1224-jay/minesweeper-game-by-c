C_FILES   = minesweeper.c ai.c tools.c
OBJ_FILES = minesweeper.o ai.o tools.o

a.out: minesweeper.o ai.o tools.o
	gcc $(OBJ_FILES) -o a.out


minesweeper.o: minesweeper.c minesweeper.h common.h tools.c
	gcc minesweeper.c -c

ai.o: ai.c common.h tools.c
	gcc ai.c -c

tools.o: tools.c common.h
	gcc tools.c -c

clean:
	rm $(OBJ_FILES)

force_build:
	gcc tools.c minesweeper.c ai.c -o a.out

