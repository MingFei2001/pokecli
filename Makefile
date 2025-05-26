CC = gcc
CFLASG = -Wall -O2
TARGET = pokecli

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLASG) -o $(TARGET) main.c

clean:
	rm -f $(TARGET)
