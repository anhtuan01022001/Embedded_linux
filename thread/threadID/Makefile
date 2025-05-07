.PHONY: all clean

CC = gcc
CFLAGS = -Wall -pthread
TARGET = threadID

all: $(TARGET)

$(TARGET): threadID.o
	$(CC) $(CFLAGS) -o $(TARGET) threadID.o

main.o: main.c
	$(CC) $(CFLAGS) -c threadID.c

clean:
	rm -f *.o $(TARGET)
