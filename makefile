CC=cc
CFLAGS=-I -std=c99 -pedantic -Wall
OBJ = sorting.o source.o

sorting: $(OBJ)
	clear
	$(CC) -o sorting $(OBJ)
	chmod 755 sorting
	./sorting

clean:
	rm -f *.o sorting