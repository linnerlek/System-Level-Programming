CC = gcc
CFLAGS = -Wall

all: main1

main1: main1.o reverse.o
	$(CC) $(CFLAGS) -o main1 main1.o reverse.o

main1.o: main1.c reverse.h
	$(CC) $(CFLAGS) -c main1.c

reverse.o: reverse.c reverse.h
	$(CC) $(CFLAGS) -c reverse.c
