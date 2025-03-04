##
# CPP00 ex01
#
# @file
# @version 0.1

CXX := c++
CXX_FLAGS := -std=c++98 -Wall -Werror -Wextra
INCLUDES := -Iincludes

SRC_FILES := src/Contact.cpp src/PhoneBook.cpp src/main.cpp
OBJ_FILES := $(SRC_FILES:%.cpp=%.o)

NAME := phonebook_app

$(NAME): $(SRC_FILES)
	$(CXX) $(CXX_FLAGS) $(SRC_FILES) -o $(NAME) $(INCLUDES)

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

unittest:
	cmake -S . -B build && \
	cmake --build build && \
	./build/run_unittests

compile_commands:
	cmake -S . -B build -DBUILD_TEST=ON -DBUILD_PHONEBOOK=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON && \
	mv build/compile_commands.json ./compile_commands.json

# end
