# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 17:21:15 by ltrinchi          #+#    #+#              #
#    Updated: 2022/12/28 18:41:31 by ltrinchi         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = test
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = main.cpp

HEADERS = 	./enable_if.hpp \
			./is_integral.hpp \
			./iterator_traits.hpp \
			./iterator_tree.hpp \
			./iterator_vector.hpp \
			./lexicographical_compare.hpp \
			./make_pair.hpp \
			./map.hpp \
			./Node.hpp \
			./pair.hpp \
			./reverse_iterator.hpp \
			./stack.hpp \
			./Utility.hpp \
			./vector.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
