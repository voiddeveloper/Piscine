CFLAGS = -Wall -Wextra -Werror
TARGET = ft_cat
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -c $<

all: $(TARGET)

$(TARGET): $(OBJECTS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
