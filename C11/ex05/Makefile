CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = do-op
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
