OBJS = Main.o SList.o Test.o 
CC = c++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

p1 : $(OBJ)
	$(CC) $(LFLAGS) $(OBJS) -o p1

Main.o : Main.h 
	$(CC) $(CFLAGS) Main.cpp

SList.o : SList.h 
	$(CC) $(CFLAGS) SList.cpp

Test.o : Test.h 
	$(CC) $(CFLAGS) Test.cpp
clean:
	\rm *.o *~ p1