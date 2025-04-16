CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g

CPPFILES = main.cpp  ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

HEADERS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

OBJ = $(CPPFILES:.cpp=.o)

NC=\033[0m
RED=\033[0;31m
LGREY=\033[0;32m



NAME =  ScavTrap

# all : ASCII_ART $(NAME)
all : $(NAME)

%.o : %.cpp $(HEADERS) Makefile
	$(CC)  $(CPPFLAGS) -c  $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) -o $@ $^

ASCII_ART :
	@echo -e "${LGREY}"
	@echo -e '_____________  _______________ '
	@echo -e '___  ____/_  |/ /_  __ \_  __ \'
	@echo -e '__  __/  __    /_  / / /  / / /'
	@echo -e '_  /___  _    | / /_/ // /_/ / '
	@echo -e '/_____/  /_/|_| \____/ \____/  '
	@echo -e ""
	@echo -e '█▀█░█▀▄░▀█▀░█░█░█▀█░█▀▄░█▀█░█░█░░░░█▀▀░█▀█░█▀█░█▀█░█▀█░▀█▀░█▀▀░█▀█░█░░░░░█▀▀░█▀█░█▀▄░█▄█'
	@echo -e '█░█░█▀▄░░█░░█▀█░█░█░█░█░█░█░▄▀▄░░░░█░░░█▀█░█░█░█░█░█░█░░█░░█░░░█▀█░█░░░░░█▀▀░█░█░█▀▄░█░█'
	@echo -e '▀▀▀░▀░▀░░▀░░▀░▀░▀▀▀░▀▀░░▀▀▀░▀░▀░░░░▀▀▀░▀░▀░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░░░▀░░░▀▀▀░▀░▀░▀░▀'
	@echo -e "\t\tBy Aohssine"
	@echo -e "${NC}"

clean :
	rm -rf  $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re