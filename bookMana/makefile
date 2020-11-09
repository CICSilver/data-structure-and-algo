CC = gcc
CFLAGS = -w `pkg-config --cflags --libs gtk+-2.0`

all:test.out

OBJ_BOOK = book_manager.o test.o file_opera.o gui.o

test.out:$(OBJ_BOOK)
	@$(CC) $(CFLAGS) $(OBJ_BOOK) -o test $(CFLAGS)

test.o:test.c book_manager.h file_opera.h
	@$(CC) $(CFLAGS) -c test.c

gui.o:gui.c gui.h book_manager.h
	@$(CC) -c gui.c $(CFLAGS)

book_manager.o:book_manager.c book_manager.h
	@$(CC) $(CFLAGS) -c book_manager.c

file_opera.o:file_opera.c file_opera.h book_manager.h
	@$(CC) $(CFLAGS) -c file_opera.c

.PHONY:clean

clean:
	rm -f *.o *.gch
