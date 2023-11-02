NAME = serialize

SRCS = main.cpp Serial.cpp

OBJS = $(SRCS:.cpp=.o)

CC = g++

RM = rm -f

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re