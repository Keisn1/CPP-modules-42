##
# cpp01/ex05
#
# @file
# @version 0.1

CXX := c++
CXX_FLAGS := -std=c++98 -Wall -Werror -Wextra

SRC_DIR := src
BUILD_DIR := build
INCLUDES := -Iincludes
SRC_FILES := 	$(SRC_DIR)/Harl.cpp \
				$(SRC_DIR)/main.cpp

NAME := harlFilter

all: $(NAME)

$(NAME): $(SRC_FILES)
	$(CXX) $(CXX_FLAGS) $(SRC_FILES) -o $(NAME) $(INCLUDES)

clean:
	rm -rf .cache
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) $(NAME)

unittest:
	cmake -S . -B build && \
	cmake --build build && \
	./build/run_unittests

compile_commands:
	cmake -S . -B build -DBUILD_TEST=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON && \
	mv build/compile_commands.json ./compile_commands.json

# end
