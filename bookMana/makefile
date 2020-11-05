CC = gcc
CFLAGS = -W

all:test.out

OBJ_BOOK = book_manager.o test.o

test.out:$(OBJ_BOOK)
	@$(CC) $(CFLAGS) $(OBJ_BOOK) -o test

test.o:test.c book_manager.h
	@$(CC) $(CFLAGS) -c test.c

book_manager.o:book_manager.c book_manager.h
	@$(CC) $(CFLAGS) -c book_manager.c
