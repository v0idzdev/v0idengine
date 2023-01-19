# Compiler flags and warnings
CC          = g++
CXXFLAGS    = -O3 -fPIC -std=c++17 -Wall -Wextra -Wpedantic -Wcast-align \
	-Wcast-qual -Wdisabled-optimization -Wduplicated-branches -Wduplicated-cond \
	-Wformat=2 -Wlogical-op -Wmissing-include-dirs -Wnull-dereference \
	-Woverloaded-virtual -Wpointer-arith -Wshadow -Wswitch-enum -Wvla

# Bash shell commands
MKDIR       = mkdir -p
CP          = cp

# Directory information
TARGET      = libv0idengine.so
INCLUDEDIR  = /usr/include/v0idengine
LIBDIR      = /usr/lib
SRCDIR      = Source
BUILDDIR    = Build
# Manually specify files for clarity
SRCFILES    = $(patsubst %, $(SRCDIR)/%, Bitmask.cpp Input.cpp \
	ResourcePath.cpp SceneStateMachine.cpp Window.cpp)
HEADERFILES = $(SRCFILES:.cpp=.hpp) $(patsubst %, $(SRCDIR)/%, EnumHash.hpp \
	Scene.hpp)
OBJFILES    = $(SRCFILES:.cpp=.o)

.PHONY: clean

all: $(TARGET)
	@echo [*] v0idengine has been compiled.

$(TARGET): $(OBJFILES)
	$(MKDIR) $(BUILDDIR)
	$(CC) $(CXXFLAGS) -shared -o $(BUILDDIR)/$@ $^

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

install: all clean
	$(MKDIR) $(INCLUDEDIR)
	$(CP) -t $(INCLUDEDIR) $(HEADERFILES)
	$(CP) $(BUILDDIR)/$(TARGET) $(LIBDIR)/
	@echo [*] v0idengine has been installed.

uninstall: purge
	$(RM) -rf $(INCLUDEDIR)
	$(RM) $(LIBDIR)/$(TARGET)
	@echo [*] v0idengine has been uninstalled.

clean:
	$(RM) $(SRCDIR)/*.o

purge: clean
	$(RM) -rf $(BUILDDIR)
