CC = c++ 

CFLAGS = -Wall -Werror -Wextra 

CFILES = megaphone.cpp
OBJ = $(CFILES:.cpp=.o)

NAME = megaphone

all : $(NAME)

%.o : %.c  Makefile
	$(CC)  $(CFLAGS) -c  $< -o $@

$(NAME) : $(OBJ) 
	$(CC) $^ $(CFLAGS) -o $@

clean :
	rm -rf  $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re