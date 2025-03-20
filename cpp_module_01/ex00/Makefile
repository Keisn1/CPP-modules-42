##
# cpp01/ex00
#
# @file
# @version 0.1

CXX := c++
CXX_FLAGS := -std=c++98 -Wall -Werror -Wextra

SRC_DIR := src
BUILD_DIR := build
INCLUDES := -Iincludes
SRC_FILES := 	$(SRC_DIR)/Zombie.cpp \
				$(SRC_DIR)/newZombie.cpp \
				$(SRC_DIR)/randomChump.cpp \
				$(SRC_DIR)/main.cpp

NAME := zombie00

all: $(NAME)

$(NAME): $(SRC_FILES)
	$(CXX) $(CXX_FLAGS) $(SRC_FILES) -o $(NAME) $(INCLUDES)

clean:
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean
	# invoking `make` utility to build or process the target specified by the variable `$(NAME)`
	# 1. *Portability*: =$(MAKE)= automatically uses the same version of =make= that was invoked, which is important in environments where multiple versions of =make= might be installed.
	# 2. *Correct Behavior with Flags*: =$(MAKE)= carries over any flags or options that were passed to the initial =make= command invocation. This ensures consistent behavior across recursive make calls.
	# 3. *Automatic Variable*: =$(MAKE)= is an automatic variable provided by =make=, which replaces itself with the command name or path used to invoke =make=. This can include additional options or a specific path.
	$(MAKE) $(NAME)


unittest:
	cmake -S . -B build && \
	cmake --build build && \
	./build/run_unittests

compile_commands:
	cmake -S . -B build -DBUILD_TEST=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON && \
	mv build/compile_commands.json ./compile_commands.json

# end
