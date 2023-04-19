CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
OBJDIR = obj

SRC = Bureaucrat.cpp main.cpp Form.cpp
OBJ = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))
HEADER = Bureaucrat.hpp Form.hpp

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
