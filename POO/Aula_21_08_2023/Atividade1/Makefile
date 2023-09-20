#   $ make --version
# GNU Make 4.3

all:	programa

programa:	app.o func.o
	g++ app.o func.o -o programa
	./programa

clean:
	rm -f *.o
	rm -f programa