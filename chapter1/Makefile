# Makefile 
# Created by Lee 13/12/2019

PROG = program
CC = g++
CPPFLAGS = -std=c++14 -O2
LDFLAGS = 
OBJS = main.o

$(PROG) : $(OBJS)
	$(CC) $(LDFLAGS)-o $(PROG) $(OBJS)
main.o : 
	$(CC) $(CPPFLAGS) -c main.cpp
clean:
	rm -f core $(PROG) $(OBJS)
