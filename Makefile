all: add-nbo

add-nbo: main.o
	g++ -o add-nbo main.cpp

clean:
	rm -f *.o

