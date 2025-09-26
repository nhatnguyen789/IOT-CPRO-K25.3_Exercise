# C++ compiler name
CXX = g++

# Compiler Flags
# -std=c++11: Use C++11 standard (or newer like c++14, c++17)
# -Wall: Turn on all warnings, great for debugging
# -I<directory>: Tells the compiler where to find header files (.h)
CXXFLAGS = -std=c++11 -Wall -IMy_App -IStudent -IStudent_List

# Name of the final executable file
TARGET = student_manager

# List all .cpp source code files
SOURCES = My_App/main.cpp Student/student.cpp Student_List/student_list.cpp

# Automatically create a list of object files (.o) from a list of source files
# Example: main.cpp -> main.o
OBJECTS = $(SOURCES:.cpp=.o)

# --- Makefile Rules ---

# Default rule: executed when you type 'make'
# 'all' depends on the TARGET executable.
all: $(TARGET)

# Linking rule: create executable file from object files
# $@: Name of target (here is $(TARGET))
# $^: Name of all dependent files (here is $(OBJECTS))
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ 
	@echo "Build successful! Run with ./"$(TARGET)

# Compilation rule: create object file (.o) from source file (.cpp)
# $<: Name of the first dependent file (here is the corresponding .cpp file)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleanup rule: delete files that have been created
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Cleanup complete."