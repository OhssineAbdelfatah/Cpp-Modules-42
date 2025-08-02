CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address -g

CPPFILES = Span.cpp main.cpp 
HEADERS = Span.hpp

OBJ = $(CPPFILES:.cpp=.o)

NAME = span

all : $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC)  $(CPPFLAGS) -c  $< -o $@

$(NAME) : $(OBJ) $(HEADERS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
