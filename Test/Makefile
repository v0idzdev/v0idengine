# Compiler flags and warnings
CC          = g++
CXXFLAGS    = -O3 -std=c++17 -Wall -Wextra -Wpedantic -Wcast-align \
	-Wcast-qual -Wdisabled-optimization -Wduplicated-branches -Wduplicated-cond \
	-Wformat=2 -Wlogical-op -Wmissing-include-dirs -Wnull-dereference \
	-Woverloaded-virtual -Wpointer-arith -Wshadow -Wswitch-enum -Wvla
TARGET      = Main
SRCDIR      = Source
LIBS        = -lv0idengine -lsfml-graphics -lsfml-window -lsfml-system

# Add source and header files here
SRCFILES    = Main.cpp $(patsubst %, $(SRCDIR)/%, Game.cpp SceneLevel.cpp \
	SceneSplashScreen.cpp)
OBJFILES    = $(SRCFILES:.cpp=.o)

all: $(TARGET) clean
 
# Link your game files
$(TARGET): $(OBJFILES)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(SRCDIR)/*.o *.o

reset: clean
	$(RM) $(TARGET)