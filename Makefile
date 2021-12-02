LDFLAGS = -lSDL2 -lSDL2_image -g
CFLAGS = -g
CC = g++

.PHONY: all
all: clean game run 

game: main.o game.o
	$(CC) $^ -o game $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $^ -o $@ $(CFLAGS)

.PHONY: run
run:
	./game

.PHONY: clean
clean:
	rm -f game && rm -f *.o
