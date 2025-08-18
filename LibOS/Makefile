CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -g -std=c++20
INCLUDES = -Isrc/header

SRC_DIR = src/cpp
TEST_DIR = test

BUILD_DIR = build
TEST_OBJ_DIR = $(BUILD_DIR)/obj/test
SRC_OBJ_DIR = $(BUILD_DIR)/obj/src

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
SRC_OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(SRC_OBJ_DIR)/%.o,$(SRC_FILES))

TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp,$(TEST_OBJ_DIR)/%.o,$(TEST_FILES))

TEST_EXEC = $(BUILD_DIR)/test_libos

all: test

test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(SRC_OBJ_FILES) $(TEST_OBJ_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -lgtest -lgtest_main -lpthread -o $@

$(SRC_OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(SRC_OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(TEST_OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR) $(TEST_OBJ_DIR) $(SRC_OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean test
