CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude
LDFLAGS = -Llib
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system  

SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
LIB_DIR = lib

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)
STATIC_LIB = $(LIB_DIR)/libboard.a
DYNAMIC_LIB = $(LIB_DIR)/libboard.so
EXECUTABLE = $(BIN_DIR)/game

all: $(EXECUTABLE)

$(EXECUTABLE): $(STATIC_LIB) $(DYNAMIC_LIB) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS) -lboard

$(STATIC_LIB): $(BIN_DIR)/Board.o
	ar rcs $@ $^

$(DYNAMIC_LIB): $(BIN_DIR)/Board.o
	$(CXX) -shared -fPIC -o $@ $^

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@

clean:
	rm -rf $(BIN_DIR) $(LIB_DIR)

test: all
	./$(EXECUTABLE)
