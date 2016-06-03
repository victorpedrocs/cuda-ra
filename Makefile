all: main

OBJS = util.o readers.o relation.o catalog.o main.o projection.o
READER = util.o readers.o main.o 
CC = g++
DEBUG = -g
LFLAGS = -Wall $(DEBUG)
CFLAGS = -Wall -c $(DEBUG)

#############################

util.o : util.h util.cpp
	$(CC) $(CFLAGS) util.cpp

readers.o : readers.h readers.cpp
	$(CC) $(CFLAGS) readers.cpp

relation.o : relation.h relation.cpp
	$(CC) $(CFLAGS) relation.cpp

catalog.o : catalog.h catalog.cpp
	$(CC) $(CFLAGS) catalog.cpp

projection.o : operators/projection.h operators/projection.cpp
	$(CC) $(CFLAGS) operators/projection.cpp

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

#############################

clean:
	\rm -rf main

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main