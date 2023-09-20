#   $ make --version
# GNU Make 4.3

all:	programa

programa:	principal.o bissexto.o
	g++ principal.o bissexto.o -o programa
	./programa

clean:
	rm -f *.o
	rm -f programa