
EXECUTABLE := assignment5

# the source files to be built
SOURCES := *.cpp

# extra things
INCLUDES := -I ../include
EXT := exe
CC := g++

all:
	# basically building the g++ command
	$(CC) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE).$(EXT)

realclean:
	find . -type f -name "*.o" -exec rm '{}' \;
	find . -type f -name "*.out" -exec rm '{}' \;
	find . -type f -name "*.exe" -exec rm '{}' \;

# this line required by make - don't delete
