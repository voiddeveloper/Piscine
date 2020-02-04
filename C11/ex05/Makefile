CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes

TARGET = do-op
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
