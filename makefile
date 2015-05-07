CC=gcc
CFLAG= -Wall -I.
EXE_NAME= POEMS
FILES= main.o poems.o

all: $(FILES)
	$(CC) -o $(EXE_NAME) $(FILES) $(CFLAGS)
