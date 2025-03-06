##
# CPP00/ex00
#
# @file
# @version 0.1

CXX := c++
CXX_FLAGS := -std=c++98 -Wall -Wextra -Werror
NAME := megaphone

all: $(NAME)

$(NAME): megaphone.cpp
	$(CXX) $(CXX_FLAGS) megaphone.cpp -o $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re all

# end
