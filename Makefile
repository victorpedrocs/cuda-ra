all: main

OBJS = util.o readers.o relation.o catalog.o main.o projection.o
READER = util.o readers.o main.o 
CC = g++
DEBUG = -g
LFLAGS = -Wall $(DEBUG)
CFLAGS = -Wall -c $(DEBUG)

#############################

util.o : base/util.h base/util.cpp
	$(CC) $(CFLAGS)  base/util.cpp

readers.o : base/readers.h base/readers.cpp
	$(CC) $(CFLAGS) base/readers.cpp

relation.o : base/relation.h base/relation.cpp
	$(CC) $(CFLAGS) base/relation.cpp

catalog.o : base/catalog.h base/catalog.cpp
	$(CC) $(CFLAGS) base/catalog.cpp

projection.o : operators/projection.h operators/projection.cpp
	$(CC) $(CFLAGS) operators/projection.cpp

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

#############################

clean:
	\rm -rf main

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main