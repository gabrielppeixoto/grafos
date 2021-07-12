#nome do projeto
PROJ_NAME=graf1

#.cpp files
CPP_SOURCE=$(wildcard *.cpp)

#.h files
H_SOURCE=$(wildcard *.h)

#object files
OBJ=$(CPP_SOURCE:.cpp=.o)

#compiler
CC=g++

#flags
CC_FLAGS=-c

#compilation and linking
all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)

main.o: main.cpp $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -rf *.o $(PROJ_NAME)