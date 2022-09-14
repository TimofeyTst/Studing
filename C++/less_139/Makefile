TARGET = func.exe
CONFIG += c++17

.PHONY: all clean run

all: $(TARGET)

clean:
	rm -rf *.o

clean_all:
	rm -rf $(TARGET) *.o *.exe

main.o: main.cpp
	g++ -c -o main.o main.cpp

func.o: func.cpp
	g++ -c -o func.o func.cpp

$(TARGET): main.o func.o
	g++ -o $(TARGET) main.o func.o -lpthread

run:
	./$(TARGET)