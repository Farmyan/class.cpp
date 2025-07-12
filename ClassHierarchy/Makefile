CXX = clang++
CXXFLAGS = -Wall -Wextra -g -std=c++17

SRC_DIR = cpp
TEST_DIR = test
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

SRC_FILES = $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp))
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))


TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(TEST_FILES))
TEST_EXEC = $(BUILD_DIR)/runTests

INCLUDES = -Iheader -Iheader/categories -Iheader/types
LIBS = -lgtest -lgtest_main -pthread

all: $(MAIN_EXEC)

$(OBJ_DIR) $(BUILD_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(MAIN_OBJ): $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(MAIN_EXEC): $(OBJ_FILES)  | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST_EXEC): $(OBJ_FILES) $(TEST_OBJ_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean test
