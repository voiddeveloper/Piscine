TARGET = do-op
SOURCES = $(wildcard *.c)

all: $(TARGET)

$(TARGET): $(SOURCES)
	gcc -o $@ $^

clean:
	rm -f $(TARGET)
