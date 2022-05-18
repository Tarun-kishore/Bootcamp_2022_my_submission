CC=g++
CFLAGS=-I.
DEPS = functions.h
OBJ = factorial.o hello.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
