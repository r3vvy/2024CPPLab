CXX = g++
CXXFLAGS = -Wall -std=c++17 -I$(INCLUDE_DIR)
LDFLAGS = -L$(LIB_DIR)
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR = src
TEST_DIR = tests
INCLUDE_DIR = include
BIN_DIR = bin
LIB_DIR = lib

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)


TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.cpp=$(BIN_DIR)/%.o)

STATIC_LIB = $(LIB_DIR)/libboard.a
DYNAMIC_LIB = $(LIB_DIR)/libboard.so
EXECUTABLE = $(BIN_DIR)/game
TEST_EXECUTABLE = $(BIN_DIR)/test_gamedata

.PHONY: all clean run test

all: $(EXECUTABLE) $(TEST_EXECUTABLE)

$(EXECUTABLE): $(STATIC_LIB) $(DYNAMIC_LIB) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS) -lboard $(LDLIBS)

$(TEST_EXECUTABLE): $(STATIC_LIB) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJECTS) -o $@ $(LDFLAGS) -lboard $(LDLIBS)

$(STATIC_LIB): $(BIN_DIR)/Board.o
	ar rcs $@ $^

$(DYNAMIC_LIB): $(BIN_DIR)/Board.o
	$(CXX) $(CXXFLAGS) -shared -fPIC -o $@ $^

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@

$(BIN_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@

clean:
	rm -rf $(BIN_DIR) $(LIB_DIR)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)
