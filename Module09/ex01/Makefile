CC				=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++11
DFLAGS		=	-g3 -DDEBUG
SANFLG		=	-fsanitize=address,undefined
NAME			=	RPN

SRC				=	main.cpp \
						RPN.cpp


INC			=		RPN.hpp

OBJ			=		$(patsubst %.cpp, %.o, $(SRC))

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

.PHONY: re
re: fclean all

.PHONY: debug
debug: CFLAGS += $(DFLAGS)
debug: fclean all

.PHONY: sanitize
sanitize: CFLAGS += $(DFLAGS)
sanitize: CFLAGS += $(SANFLG)
sanitize: fclean all

.PHONY: leaks
leaks: CFLAGS += $(DFLAGS)
leaks: fclean all
	leaks -atExit -- ./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

.PHONY: run
run: $(NAME)
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
