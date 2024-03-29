CC			=	c++
CFLAGS	=	-Wall -Wextra -Werror
DFLAGS	=	-g
NAME		=	convert

SRC			=	main.cpp \
					ScalarConverter.cpp

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
	$(RM) *_shrubbery

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