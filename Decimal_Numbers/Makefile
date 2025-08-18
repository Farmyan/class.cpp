CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -g -std=c++20
INCLUDES = -Isrc/header

SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
SRC_OBJ_DIR = $(OBJ_DIR)/src/cpp
TEST_OBJ_DIR = $(OBJ_DIR)/test

SRC_FILES = $(wildcard $(SRC_DIR)/cpp/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)

SRC_OBJ_FILES = $(patsubst $(SRC_DIR)/cpp/%.cpp,$(SRC_OBJ_DIR)/%.o,$(SRC_FILES))
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp,$(TEST_OBJ_DIR)/%.o,$(TEST_FILES))

TEST_EXEC = $(BUILD_DIR)/test

all: test

test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(SRC_OBJ_FILES) $(TEST_OBJ_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -lgtest -lgtest_main -lpthread -o $@

$(SRC_OBJ_DIR)/%.o: $(SRC_DIR)/cpp/%.cpp | $(SRC_OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(TEST_OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

$(SRC_OBJ_DIR):
	mkdir -p $@

$(TEST_OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean test
