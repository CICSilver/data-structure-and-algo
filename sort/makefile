CINCLUDES = -I ../heap/ ../heap/max_binary_heap_with_array.c ../heap/max_binary_heap_with_array.h

all:heap_sort.out

heap_sort.out:heap_sort.c ../heap/max_binary_heap_with_array.c ../heap/max_binary_heap_with_array.h
	@gcc heap_sort.c $(CINCLUDES) -o heap_sort.out



.PHONY:clean

clean:
	rm -rf *.o *.out