CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
OBJDIR = obj

SRC = main.cpp
OBJ = $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))

NAME = brainz

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all