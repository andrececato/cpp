.DEFAULT_GOAL = all

myexe = programa1
oDir = obj

files := arquivo.cpp soma.cpp
source := $(foreach fname,$(files),./$(fname))
oFiles := $(patsubst ./%.cpp, $(oDir)/%.o, $(source))

.PHONY: all
all: $(myexe)

$(myexe): $(oDir) $(oFiles)
	g++ $(oFiles) -o $@

$(oDir)/%.o: ./%.cpp
	g++ -Wall -c -o $@ $<

$(oDir):
	mkdir -p $(oDir)

.PHONY: clean
clean:
	rm -r $(oDir)
	rm $(myexe)
