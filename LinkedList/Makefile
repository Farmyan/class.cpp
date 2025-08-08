CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -g -std=c++20
INCLUDES = -Isrc

SRC_DIR = src
TEST_DIR = test

BUILD_DIR = build
TEST_OBJ_DIR = $(BUILD_DIR)/obj/test

TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp,$(TEST_OBJ_DIR)/%.o,$(TEST_FILES))

TEST_EXEC = $(BUILD_DIR)/test

all: test

test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJ_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -lgtest -lgtest_main -lpthread -o $@

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(TEST_OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR) $(TEST_OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean test

