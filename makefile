all: main

main: list.o main.o
	gcc -g list.o main.o -o main
list.o:  list.h list.c
	gcc -c -g list.c -o list.o
main.o: list.h main.c
	gcc -c -g main.c -o main.o
run: all
	./main
checkmem: all
	valgrind -v ./main
clean:
	rm -f list.o main.o main
