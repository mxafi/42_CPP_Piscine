CC				=	c++
CFLAGS		=	-Wall -Wextra -Werror
DFLAGS		=	-g3 -DDEBUG -DDATABASE_FILE=\"testdb.csv\"
SANFLG		=	-fsanitize=address,undefined
NAME			=	btc

SRC				=	main.cpp \
						BitcoinExchange.cpp


INC			=		BitcoinExchange.hpp

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
	leaks -atExit -- ./$(NAME) input.txt

.PHONY: run
run: all
	./$(NAME) input.txt
