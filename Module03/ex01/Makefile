CC			=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
DFLAGS	=	-g
NAME		=	claptrap

SRC			=	main.cpp \
					ClapTrap.cpp \
					ScavTrap.cpp

OBJ			=	$(patsubst %.cpp, %.o, $(SRC))

.PHONY: all
all: $(NAME) Makefile

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: gclean
gclean:
	git clean -Xdf

.PHONY: debug
debug: CFLAGS += $(DFLAGS)
debug: all
