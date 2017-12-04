INC_DIR = include
SRC = src
TARGET = iterator

all: $(TARGET)

$(TARGET): main.o component.o leaf.o composite.o iterator.o nullIterator.o listIterator.o CompositeIterator.o
ifeq (${OS}, Windows_NT) 
	g++ -o $(TARGET) main.o component.o leaf.o composite.o iterator.o nullIterator.o listIterator.o CompositeIterator.o -lgtest
else
	g++ -o $(TARGET) main.o component.o leaf.o composite.o iterator.o nullIterator.o listIterator.o CompositeIterator.o -lgtest -lpthread
endif

main.o: main.cpp 
	g++ -std=gnu++0x -c main.cpp

component.o: $(INC_DIR)/component.h $(SRC)/component.cpp
	g++ -std=gnu++0x -c $(SRC)/component.cpp

leaf.o: $(INC_DIR)/leaf.h $(SRC)/leaf.cpp
	g++ -std=gnu++0x -c $(SRC)/leaf.cpp

composite.o: $(INC_DIR)/composite.h $(SRC)/composite.cpp
	g++ -std=gnu++0x -c $(SRC)/composite.cpp

iterator.o: $(INC_DIR)/iterator.h $(SRC)/iterator.cpp
	g++ -std=gnu++0x -c $(SRC)/iterator.cpp

nullIterator.o: $(INC_DIR)/nullIterator.h $(SRC)/nullIterator.cpp
	g++ -std=gnu++0x -c $(SRC)/nullIterator.cpp

listIterator.o: $(INC_DIR)/listIterator.h $(SRC)/listIterator.cpp
	g++ -std=gnu++0x -c $(SRC)/listIterator.cpp

CompositeIterator.o: $(INC_DIR)/CompositeIterator.h $(SRC)/CompositeIterator.cpp
	g++ -std=gnu++0x -c $(SRC)/CompositeIterator.cpp

clean:	
ifeq (${OS}, Windows_NT) 
	del *.o *.exe
else
	rm -f *.o $(TARGET)
endif