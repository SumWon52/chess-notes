CC=gcc
CFLAGS=-O2 -Wall -march=native $(shell sdl2-config --cflags --libs)
LDFLAGS=$(shell sdl2-config --cflags --libs)

SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
BIN=CNotes

BIN: $(OBJS) $(OBJ)
	$(CC) $(LDFLAGS) $< -o $(BIN)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $(OBJ)

.PHONY: clean

clean:
	rm $(OBJS)
	rm $(BIN)
