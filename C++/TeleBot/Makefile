TARGET = telegram_bot

.PHONY: all clean clean_all run al

all: $(TARGET)
	rm -rf *.o
	./$(TARGET)

al: $(TARGET)
	./$(TARGET)

clean:
	rm -rf *.o

clean_all:
	rm -rf $(TARGET) *.o *.exe

main.o: main.cpp
	g++ -c -o main.o main.cpp


$(TARGET): main.o
	g++ -o $(TARGET) main.o -lpthread --std=c++14 -I/usr/local/include -lTgBot -lboost_system -lssl -lcrypto

run:
	./$(TARGET)

debug: $(TARGET)
	./$(TARGET)
