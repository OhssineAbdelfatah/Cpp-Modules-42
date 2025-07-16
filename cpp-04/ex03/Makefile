CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address -g

CPPFILES = main.cpp AMateria.cpp MateriaSource.cpp Cure.cpp Ice.cpp Character.cpp

HEADERS = IMateriaSource.hpp AMateria.hpp MateriaSource.hpp Cure.hpp Ice.hpp Character.hpp

OBJ = $(CPPFILES:.cpp=.o)

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