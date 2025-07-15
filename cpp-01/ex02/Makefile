CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address -g

CPPFILES = main.cpp 

HEADERS = 

OBJ = $(CPPFILES:.cpp=.o)

NC=\033[0m
RED=\033[0;31m
LGREY=\033[0;37m

# speed
AMLOU = "${RED}"\
"\n"\
"_____________  ______________ \n"\
"___  ____/_  |/ /_  __ \_|__ \\n"\
"__  __/  __    /_  / / /___/ /\n"\
"_  /___  _    | / /_/ /_  __/ \n"\
"/_____/  /_/|_| \____/ /____/ \n"\
"\n"\
" ╦ ╦╦  ╔╦╗╦ ╦╦╔═╗  ╦╔═╗  ╔╗ ╦═╗╔═╗╦╔╗╔\n"\
" ╠═╣║   ║ ╠═╣║╚═╗  ║╚═╗  ╠╩╗╠╦╝╠═╣║║║║\n"\
" ╩ ╩╩   ╩ ╩ ╩╩╚═╝  ╩╚═╝  ╚═╝╩╚═╩ ╩╩╝╚╝\n"\
"\n" \
"\t\tBy Aohssine"\
"\n" \
"\n" \
"${NC}"


NAME =  zombie

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
