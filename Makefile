CC = g++
CFLAGS = -std=c++11 -Wall
SRC = src/main.cpp
OBJ = main.o
EXEC = todo

$(EXEC): $(OBJ)
    $(CC) $(OBJ) -o $(EXEC)

main.o: $(SRC)
    $(CC) $(CFLAGS) -c $(SRC)

clean:
    rm -f $(OBJ) $(EXEC)