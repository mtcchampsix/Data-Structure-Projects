#
# N.B. If you're using files with .cc extensions, then you need to search
# and replace cpp with cc.
#

CC = g++
CFLAGS = -Wall -g
#CFLAGS = -std=c++11 -Wall -g
# For this project, you'll have only main.cpp, since we're using
# template classes.
SRCS = main.cpp
#SRCS = ${wildcard *.cpp}
OBJS = ${SRCS:.cpp=.o}
INCLS = ${SRCS:.cpp=.h} Hash.h AVLtree.h main.h Node.h

p3: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o p3

$(OBJS):
	$(CC) $(CFLAGS) -c $*.cpp

depend: Makefile.dep
	$(CC) -MM $(SRCS) > Makefile.dep

Makefile.dep:
	touch Makefile.dep

.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip $(SRCS) $(INCLS) Makefile Makefile.dep 

clean:
	rm -f *.o p1 core

include Makefile.dep

