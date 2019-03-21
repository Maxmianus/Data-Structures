OBJS = menu.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
CXXFLAGS += -std=c++11

main : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o list

clean:
	\rm *.o *~ list
