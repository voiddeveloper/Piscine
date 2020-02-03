CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes
OBJDIR = srcs

TARGET = libft.a
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INCDIR)
	
$(TARGET): $(OBJECTS)
	ar cr $@ $(OBJECTS)

clean:
	rm $(OBJECTS)

fclean: clean
	rm $(TARGET)

re: fclean all
