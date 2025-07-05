CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

CPPFILES = main.cpp Base.cpp 
HEADERS = Base.hpp A.hpp B.hpp C.hpp

OBJ = $(CPPFILES:.cpp=.o)

NAME = base

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