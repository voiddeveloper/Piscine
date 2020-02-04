TARGET = do-op
SOURCES = $(wildcard *.c)

all: $(TARGET)

$(TARGET): $(SOURCES)
	gcc -Wall -Wextra -Werror -o $@ $^

clean:
	rm -f $(TARGET)
