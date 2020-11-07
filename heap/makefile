CC = gcc

all:main.out

OBJ_MAIN = max_binary_heap_with_array.o main.o

main.out:$(OBJ_MAIN)
	@$(CC) $(OBJ_MAIN) -o main.out

main.o:main.c max_binary_heap_with_array.h
	@$(CC) -c main.c


max_binary_heap_with_array.o:max_binary_heap_with_array.c max_binary_heap_with_array.h
	@$(CC) -c max_binary_heap_with_array.c

.PHONY:clean

clean:
	@rm -rf *.o *.out *.gch

