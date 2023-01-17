CC       = g++
CXXFLAGS = -g -std=c++11 -pedantic -Wall -Wextra
LIBS     = -lsfml-graphics -lsfml-window -lsfml-system
SRC      = Source
BIN      = Main
SRCS     = $(wildcard **/*.cpp)
OBJS     = $(subst %.cpp, %.o, $(SRCS))

all: $(BIN) clean

$(OBJS): $(SRCS)
	$(CC) -c $^ $(CXXFLAGS) -I $(SRC)

$(BIN): $(OBJS)
	$(CC) $@.cpp -o $@ $^ $(LIBS)

.PHONY: clean purge

clean:
	$(RM) *.o

purge: clean
	$(RM) $(BIN)
