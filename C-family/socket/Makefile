all: server client

server: server.c
	gcc -std=c99 -O2 server.c -o server

client: client.c
	gcc -std=c99 -O2 client.c -o client

test-server:
	./server

test-client:
	sudo cp client /sandbox/sandbox/app
	/home/butler/sandbox 10 2147483647 ../app/client <0.in

clean: 
	rm server client


