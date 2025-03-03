CC = c++ 

CFLAGS = -Wall -Werror -Wextra  -std=c++98

CFILES = main.cpp Contacts.cpp PhoneBook.cpp

HEADERS = Contacts.hpp PhoneBook.hpp

OBJ = $(CFILES:.cpp=.o)

NAME = phonebook

all : $(NAME)

%.o : %.c $(HEADERS) Makefile
	$(CC)  $(CFLAGS) -c  $< -o $@

$(NAME) : $(OBJ) 
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -rf  $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
