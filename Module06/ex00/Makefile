CC			=	c++
CFLAGS	=	-Wall -Wextra -Werror
DFLAGS	=	-g -DDEBUG
NAME		=	convert

SRC			=	main.cpp \
					ScalarConverter.cpp

INC			=	ScalarConverter.hpp

OBJ			=	$(patsubst %.cpp, %.o, $(SRC))

.PHONY: all
all: $(NAME) Makefile

$(NAME): $(OBJ) $(INC)
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

.PHONY: run
run: $(NAME)
	./$(NAME)