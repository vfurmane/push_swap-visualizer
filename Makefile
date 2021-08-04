# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 13:23:55 by vfurmane          #+#    #+#              #
#    Updated: 2021/08/04 16:48:50 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= visual_ps
SRCS		= $(addprefix srcs/, main.c \
			  $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c))
OBJS		= $(SRCS:.c=.o)
INCL		= $(addprefix -I , includes)
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(INCL) -o $@

# remove fsanitize
all:		CFLAGS+= -fsanitize=address -g3
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $(NAME)

bonus:		all

# remove nosan
nosan:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

# Remove nosan
.PHONY:		all bonus nosan clean fclean re
