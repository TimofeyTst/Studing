TARGET = STL.exe
CONFIG += c++17

.PHONY: all clean run

all: $(TARGET)

clean:
	rm -rf *.o

clean_all:
	rm -rf $(TARGET) *.o *.exe

main.o: main.cpp
	g++ -c -o main.o main.cpp

classes.o: classes.cpp
	g++ -c -o classes.o classes.cpp

$(TARGET): main.o classes.o
	g++ -o $(TARGET) main.o classes.o -lpthread

run:
	./$(TARGET)