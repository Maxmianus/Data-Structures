OBJS = menu.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
CXXFLAGS += -std=c++11

main : $(OBJS)
	    $(CC) $(CFLAGS) $(OBJS) -o list

clean:
		\rm *.o *~ list
