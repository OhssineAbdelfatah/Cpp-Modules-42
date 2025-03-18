NC=\033[0m
RED=\033[0;31m
LGREY=\033[0;37m

# speed
AMLOU = "${RED}"\
"_____________  _______________ \n"\
"___  ____/_  |/ /_  __ \_  __ \\n"\
"__  __/  __    /_  / / /  / / /\n"\
"_  /___  _    | / /_/ // /_/ / \n"\
"/_____/  /_/|_| \____/ \____/  \n"\
"\n" \
"╔╦╗┌─┐┌─┐┌─┐┌─┐┬ ┬┌─┐┌┐┌┌─┐\n"\
"║║║├┤ │ ┬├─┤├─┘├─┤│ ││││├┤ \n"\
"╩ ╩└─┘└─┘┴ ┴┴  ┴ ┴└─┘┘└┘└─┘\n"\
"\t\tBy Aohssine"\
"\n" \
"${NC}"\
"\n" 

CC = c++ 

CPPFLAGS = -Wall -Werror -Wextra 

CPPFILES = megaphone.cpp
OBJ = $(CPPFILES:.cpp=.o)

NAME = megaphone

all : ASCII_ART $(NAME)

%.o : %.c  Makefile
	$(CC)  $(CPPFLAGS) -c  $< -o $@

$(NAME) : $(OBJ) 
	$(CC) $^ $(CPPFLAGS) -o $@

ASCII_ART :
	@echo ${AMLOU}

clean :
	rm -rf  $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re