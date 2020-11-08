all:binary_tree.out

binary_tree.out:binary_tree.o
	@gcc -w binary_tree.o -o binary_tree.out

binary_tree.o:binary_tree.c binary_tree.h
	@gcc -c -w binary_tree.c binary_tree.h

.PHONY:clean

clean:
	rm -rf *.o *.out *.gch