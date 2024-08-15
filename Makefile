CXX = gcc
CXXFLAGS = -g -std=c99 -Wall -Werror -Wextra -pedantic
SRC_DIR = src
OBJ_DIR = objFiles
TARGET = restaurant_maneger

SRC_FILES = 

OBJ_FILES = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

test: $(TARGET)
	./$(TARGET) $(TEST_ARGS)