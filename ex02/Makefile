CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address -g

CPPFILES = main.cpp WrongAnimal.cpp Animal.cpp Cat.cpp Dog.cpp WrongCat.cpp

HEADERS = Animal.hpp Cat.hpp Dog.hpp WrongCat.hpp WrongAnimal.hpp

OBJ = $(CPPFILES:.cpp=.o)

NC=\033[0m
RED=\033[0;31m
LGREY=\033[0;32m



NAME =  Polymorphism

all : $(NAME)

%.o : %.cpp $(HEADERS) Makefile
	$(CC)  $(CPPFLAGS) -c  $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) -o $@ $^

clean :
	rm -rf  $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re