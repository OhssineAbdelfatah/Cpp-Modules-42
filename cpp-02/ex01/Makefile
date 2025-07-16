CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address -g

CPPFILES = main.cpp  Fixed.cpp

HEADERS = Fixed.hpp

OBJ = $(CPPFILES:.cpp=.o)

NC=\033[0m
RED=\033[0;31m
LGREY=\033[0;32m



NAME =  OrthodoxCanonicalForm

all : ASCII_ART $(NAME)

%.o : %.cpp $(HEADERS) Makefile
	$(CC)  $(CPPFLAGS) -c  $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) -o $@ $^

ASCII_ART :
	@echo "${LGREY}"
	@echo '_____________  ______________'
	@echo '___  ____/_  |/ /_  __ \_<  /'
	@echo '__  __/  __    /_  / / /_  / '
	@echo '_  /___  _    | / /_/ /_  /  '
	@echo '/_____/  /_/|_| \____/ /_/   '
	@echo ""
	@echo '░█▀▀░▀█▀░█░█░█▀▀░█▀▄░░░░░█▀█░█▀█░▀█▀░█▀█░▀█▀'
	@echo '░█▀▀░░█░░▄▀▄░█▀▀░█░█░▄▄▄░█▀▀░█░█░░█░░█░█░░█░'
	@echo '░▀░░░▀▀▀░▀░▀░▀▀▀░▀▀░░░░░░▀░░░▀▀▀░▀▀▀░▀░▀░░▀░'
	@echo "\t\tBy Aohssine"
	@echo "${NC}"

clean :
	rm -rf  $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re