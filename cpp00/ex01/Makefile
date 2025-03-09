CC = c++ 

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address -g

CPPFILES = main.cpp Contacts.cpp PhoneBook.cpp

HEADERS = Contacts.hpp PhoneBook.hpp

OBJ = $(CPPFILES:.cpp=.o)

NC=\033[0m
RED=\033[0;31m
LGREY=\033[0;37m

AMLOU = "${LGREY}"\
"\n"\
" ▄▄▄       ███▄ ▄███▓ ██▓     ▒█████   █    ██ \n"\
"▒████▄    ▓██▒▀█▀ ██▒▓██▒    ▒██▒  ██▒ ██  ▓██▒\n"\
"▒██  ▀█▄  ▓██    ▓██░▒██░    ▒██░  ██▒▓██  ▒██░\n"\
"░██▄▄▄▄██ ▒██    ▒██ ▒██░    ▒██   ██░▓▓█  ░██░\n"\
" ▓█   ▓██▒▒██▒   ░██▒░██████▒░ ████▓▒░▒▒█████▓ \n"\
" ▒▒   ▓▒█░░ ▒░   ░  ░░ ▒░▓  ░░ ▒░▒░▒░ ░▒▓▒ ▒ ▒ \n"\
"  ▒   ▒▒ ░░  ░      ░░ ░ ▒  ░  ░ ▒ ▒░ ░░▒░ ░ ░ \n"\
"  ░   ▒   ░      ░     ░ ░   ░ ░ ░ ▒   ░░░ ░ ░ \n"\
"      ░  ░       ░       ░  ░    ░ ░     ░     \n"\
"${NC}"


NAME =  phonebook

all : ASCII_ART $(NAME)

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
