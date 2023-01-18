CC       = g++
CXXFLAGS = -g -std=c++17 -pedantic -Wall -Wextra
LIBS     = -lsfml-graphics -lsfml-window -lsfml-system
SRC      = Source
OBJ      = Build
BIN      = Main
SRCS     = $(wildcard $(SRC)/*.cpp)

define OBJS
	$(wildcard $(OBJ)/*.o)
endef

all: $(BIN) clean

%.o: %.cpp
	$(CC) -c -o $(subst $(SRC), $(OBJ), $@) $<

$(BIN).o: $(BIN).cpp
	$(CC) -c -o $@ $<

$(BIN): $(BIN).o $(SRCS:.cpp=.o)
	$(CC) $(CXXFLAGS) -o $@ $< $(call OBJS) $(LIBS)

.PHONY: clean purge

clean:
	$(RM) $(OBJ)/*
	$(RM) *.o

purge: clean
	$(RM) $(BIN)
