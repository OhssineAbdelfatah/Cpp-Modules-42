CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g

CPPFILES = main.cpp Harl.cpp

HEADERS = Harl.hpp

OBJ = $(CPPFILES:.cpp=.o)

NC=\033[0m
RED=\033[0;31m
LGREY=\033[0;32m

# speed
AMLOU = "${LGREY}"\
"\n"\
"_____________  __________________\n"\
"___  ____/_  |/ /_  __ \__  ____/\n"\
"__  __/  __    /_  / / /_____ \  \n"\
"_  /___  _    | / /_/ / ____/ /  \n"\
"/_____/  /_/|_| \____/ /_____/   \n"\
"\n"\
"░█░█░█▀█░█▀▄░█░░░░░░░▀▀▄░░░░▄▀▄\n"\
"░█▀█░█▀█░█▀▄░█░░░░░░░▄▀░░░░░█/█\n"\
"░▀░▀░▀░▀░▀░▀░▀▀▀░░░░░▀▀▀░▀░░░▀░\n"\
"\n" \
"\t\tBy Aohssine"\
"\n" \
"\n" \
"${NC}"


NAME =  harl2.0

all : ASCII_ART $(NAME)
# all : $(NAME)

%.o : %.cpp $(HEADERS) Makefile
	$(CC)  $(CPPFLAGS) -c  $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) -o $@ $^

ASCII_ART :
	@echo $(AMLOU)

clean :
	rm -rf  $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
