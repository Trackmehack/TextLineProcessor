CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = stringfun

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

clean:
	rm -f $(TARGET)


