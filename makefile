# Programmer: Georgina Hutchins							Course: CSC112 A
# Assignment: 8									Date: 03/25/14

CC = g++
CFLAGS = -g -pg -Wall

lab8: main.o database.o
	$(CC) $(CFLAGS) -o lab8 main.o database.o
main.o: main.cpp database.h
	$(CC) $(CFLAGS) -c main.cpp
database.o: database.h database.cpp
	$(CC) $(CFLAGS) -c database.cpp
clean:
	/rm -f *.o lab8






