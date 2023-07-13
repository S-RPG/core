CC = g++
CFLAGS = -std=c++17 -Wall
LFLAGS =

TARGET = war-gd

SRCDIR = src
BINDIR = build/bin



SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(SOURCES))

$(BINDIR)/$(TARGET): $(OBJECTS)
		$(CC) $(LFLAGS) -o $@ $^

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
		$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
		rm -f $(BINDIR)/*.o $(BINDIR)/$(TARGET)
