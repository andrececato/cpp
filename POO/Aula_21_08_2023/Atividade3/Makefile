#   $ make --version
# GNU Make 4.3

all:	programa

programa:	principal.o adicionar.o
	g++ principal.o adicionar.o -o programa
	./programa

clean:
	rm -f *.o
	rm -f programa