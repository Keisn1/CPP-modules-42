
##
# cpp03/ex02
#
# @file
# @version 0.1

# = ... lazy assignment
# variable is not calculated at the time of assignment
# evaluated every time the variable is used
# := (Simple or Immediate Assignment)
# variable is calculated and fixed at the time of assignment
# variable's value will not change even if the variables it depends on change later

CXX := c++
CXXFLAGS := -std=c++98 -Wall -Werror -Wextra

SRC_DIR := src
BUILD_DIR := build
INCLUDES := -Iincludes
SRC_FILES := $(SRC_DIR)/ClapTrap.cpp $(SRC_DIR)/FragTrap.cpp $(SRC_DIR)/ScavTrap.cpp $(SRC_DIR)/main.cpp

NAME := scavtrap

all: $(NAME)

$(NAME): $(SRC_FILES)
	$(CXX) $(CXX_FLAGS) $(SRC_FILES) -o $(NAME) $(INCLUDES)

clean:
	rm -rf .cache
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean
	make $(NAME)

unittest:
	cmake -S . -B build && \
	cmake --build build && \
	./build/run_unittests

compile_commands:
	cmake -S . -B build -DBUILD_TEST=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON && \
	mv build/compile_commands.json ./compile_commands.json

# end
