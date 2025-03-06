##
# CPP00 ex02
#
# @file
# @version 0.1

CXX := c++
CXX_FLAGS := -std=c++98 -Wall -Wextra -Werror

SRC_FILES := Account.cpp tests.cpp

NAME := test

all: $(NAME)

$(NAME): $(SRC_FILES)
	$(CXX) $(CXX_FLAGS) $(SRC_FILES) -o $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all

# end
