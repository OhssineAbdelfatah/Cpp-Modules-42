CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g
SRC = main.cpp RPN.cpp
HDR =  RPN.hpp
OBJ = $(SRC:.cpp=.o)

NAME = RPN

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