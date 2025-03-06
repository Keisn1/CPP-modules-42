##
# cpp01/ex02
#
# @file
# @version 0.1

CXX := c++
CXX_FLAGS := -std=c++98 -Wall -Werror -Wextra

SRC_FILES := main.cpp

NAME := ex02

all: $(NAME)

$(NAME): $(SRC_FILES)
	$(CXX) $(CXX_FLAGS) $(SRC_FILES) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

# end
