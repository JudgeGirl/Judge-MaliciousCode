all: main

main: main.c part.c
	gcc -std=c99 -O2 main.c -c
	gcc -std=c99 -O2 part.c -c
	objcopy --weaken part.o
	gcc -std=c99 -O2 main.o part.o -o main

peak:
	nm -gC part.o
	nm -gC main.o

clean:
	rm main 
	rm *.o

