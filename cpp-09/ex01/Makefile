CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g

CPPFILES = main.cpp RPN.cpp goCrazy.cpp
HEADERS = MutantStack.hpp RPN.hpp
TEMPLATE = MutantStack.tpp

OBJ = $(CPPFILES:.cpp=.o)

NAME = RPN

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) -o $@ $^

%.o:%.cpp $(TEMPLATE) $(HEADERS)
	$(CC)  $(CPPFLAGS) -c  $< -o $@

clean :
	rm -rf  $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
