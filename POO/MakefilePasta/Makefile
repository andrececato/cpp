#   $ make --version
# GNU Make 4.3

all:	myexe

myexe:	codigo.o auxiliar.o
	g++ codigo.o auxiliar.o -o myexe

clean:
	rm -f *.o
	rm -f myexe