CC = c++ 

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

CPPFILES = main.cpp Contacts.cpp Phonebook.cpp

HEADERS = Contacts.hpp Phonebook.hpp

OBJ = $(CPPFILES:.cpp=.o)

NAME = phonebook

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
