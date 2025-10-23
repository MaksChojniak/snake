# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Source files
SRC = main.cpp \
      Vector2Int.cpp \
      Move.cpp \
      GameObject.cpp \
      Component.cpp \
      Input.cpp \
      Map.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable
TARGET = main.exe

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each cpp file to object
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
