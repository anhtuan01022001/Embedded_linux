.PHONY: all clean

CC = gcc
CFLAGS = -Wall -pthread
TARGET = multithread_example

all: $(TARGET)

$(TARGET): main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o $(TARGET)
