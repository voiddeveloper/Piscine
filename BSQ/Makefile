CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes
TARGET = BSQ
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(TARGET): $(OBJS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
