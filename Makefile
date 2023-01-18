# Compiler flags and warnings
CC          = g++
CXXFLAGS    = -O3 -fPIC -std=c++17 -Wall -Wextra -Wpedantic -Wcast-align \
	-Wcast-qual -Wdisabled-optimization -Wduplicated-branches -Wduplicated-cond \
	-Wformat=2 -Wlogical-op -Wmissing-include-dirs -Wnull-dereference \
	-Woverloaded-virtual -Wpointer-arith -Wshadow -Wswitch-enum -Wvla

# Bash shell commands
MKDIR       = mkdir -p
CP          = cp

# Release and version information
VERSION     = 0.1.0-a.1
RELEASEDIR  = Release/v0idengine-$(VERSION)/
INCLUDEDIR  = $(RELEASEDIR)/include
LIBDIR      = $(RELEASEDIR)/lib
TARGET      = libv0idengine-$(VERSION).so

# Source and object file information
SRCDIR      = Source
SRCFILES    = $(wildcard $(SRCDIR)/*.cpp)
HEADERFILES = $(wildcard $(SRCDIR)/*.hpp)
OBJFILES    = $(SRCFILES:.cpp=.o)

.PHONY: clean purge

all: $(TARGET) headers clean
	@echo Successfully compiled v0idengine!

# Create .so using compiled .o files
$(TARGET): $(OBJFILES)
	$(MKDIR) $(LIBDIR) $(INCLUDEDIR)
	$(CC) $(CXXFLAGS) -shared -o $(LIBDIR)/$@ $<

# Copy .hpp files into release folder
headers:
	$(CP) -t $(INCLUDEDIR) $(wildcard $(SRCDIR)/*.hpp)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(SRCDIR)/*.o

purge:
	$(RM) -rf $(RELEASEDIR)
