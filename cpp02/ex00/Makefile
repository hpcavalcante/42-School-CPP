CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
OBJDIR = obj

SRC = main.cpp Fixed.cpp
OBJ = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))
HEADER = Fixed.hpp

NAME = main

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
