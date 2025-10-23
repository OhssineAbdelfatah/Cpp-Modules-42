CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp BitcoinExchange.cpp
HDR =  BitcoinExchange.hpp
OBJ = $(SRC:.cpp=.o)

NAME = btc

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HDR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re