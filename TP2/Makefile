all: test

test: test.cpp cell.o skiplist.o
	g++ -Wall -o  test test.cpp cell.o skiplist.o

skiplist.o: skiplist.cpp skiplist.hpp
	g++ -Wall -c skiplist.cpp

cell.o: cell.cpp cell.hpp
	g++ -Wall -c cell.cpp

clean:
	rm *.o test