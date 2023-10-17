CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror
DFLAGS	=	-g -std=c++98
NAME	=	phonebook

SRC		=	main.cpp \
			PhoneBook.cpp \
			Contact.cpp

.PHONY: all
all: $(NAME) Makefile

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

.PHONY: clean
clean:
	$(RM) $(NAME)

.PHONY: debug
debug: CFLAGS += $(DFLAGS)
debug: all