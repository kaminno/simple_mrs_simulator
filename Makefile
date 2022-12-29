# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target 
TARGET = test

FILES := test_environment.cpp robot.cpp vector_t.cpp robot_simulator.cpp equation.h update.h

all: $(TARGET)

$(TARGET): $(FILES) #test_environment.cpp robot.cpp vector.cpp
	$(CC) $(CFLAGS) $(FILES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(TARGET)