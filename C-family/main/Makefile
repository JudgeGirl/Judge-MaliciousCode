all: main bad

bad: main.c part.c
	gcc -std=c99 -O2 main.c part.c -o bad 

main: main.c part.c
	gcc -std=c99 -O2 main.c -c
	gcc -std=c99 -O2 part.c -c
	gcc -std=c99 -O2 main.o part.o -o main

clean:
	rm bad main
	rm *.o

