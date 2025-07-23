CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address -g

CPPFILES = main.cpp 
HEADERS = Easyfind.hpp

OBJ = $(CPPFILES:.cpp=.o)

NAME = easyfind

all : $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC)  $(CPPFLAGS) -c  $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) -o $@ $^

clean :
	rm -rf  $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
