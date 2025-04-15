CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = main.cpp PasswordEntry.cpp Bank.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = pwmanager

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f *.o $(TARGET)
