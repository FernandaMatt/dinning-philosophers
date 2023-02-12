NAME = philo

SRCS = main.c error.c ft_atoi.c life.c init.c utils.c utils2.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -pthread -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o  $(NAME)

clean:
	rm -rf *.o

fclean:
	rm -rf *.o philo

re: fclean all

.PHONY:		all clean fclean re
