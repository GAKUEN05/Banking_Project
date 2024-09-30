# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++11

# List of source files
SOURCES = system.cpp customer.cpp account.cpp transaction.cpp

# List of object files (replace .cpp with .o)
OBJECTS = $(SOURCES:.cpp=.o)

# Target executable
TARGET = bank_system

# Default target: Build the program
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)
