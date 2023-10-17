CC		= c++
CFLAGS	= -Wall -Wextra -Werror
TARGET	= megaphone

SRC		= megaphone.cpp

all: $(TARGET) Makefile

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	$(RM) $(TARGET)