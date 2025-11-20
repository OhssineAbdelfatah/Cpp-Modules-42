CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
# SRC = main.cpp PmergeMe.cpp
SRC = main.cpp PmergeMe.cpp
HDR =  PmergeMe.hpp
OBJ = $(SRC:.cpp=.o)

NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HDR)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re