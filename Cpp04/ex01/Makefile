# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 13:03:25 by mtoia             #+#    #+#              #
#    Updated: 2023/10/16 14:31:42 by mtoia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = maggots

SRCS = main.cpp Bureaucrat.cpp Form.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(Name)

$(Name): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(Name)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(Name)

re: fclean all

.PHONY: all clean fclean re