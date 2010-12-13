

main : Main.o SList.o Test.o
	g++ Main.o SList.o Test.o -o main

Main.o : Main.h Main.cpp 
	g++ -c Main.cpp

SList.o : SList.h SList.cpp
	g++ -c SList.cpp

Test.o : Test.cpp
	g++ -c Test.cpp
clean:
	\rm *.o *~ p1