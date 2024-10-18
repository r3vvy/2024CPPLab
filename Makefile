CXX = g++
CXXFLAGS = -Wall -std=c++17

TARGET = Lab3

SRCS = Board.cpp Input.cpp C++Lab3.cpp


OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)