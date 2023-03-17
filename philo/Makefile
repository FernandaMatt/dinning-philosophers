NAME = philo

SRCS = src/main.c \
	   src/error.c \
	   src/ft_atoi.c \
	   src/life.c \
	   src/init.c \
	   src/utils.c \
	   src/utils2.c \
	   src/free.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -pthread -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o  $(NAME)

clean:
	rm -rf src/*.o

fclean:
	rm -rf src/*.o philo

re: fclean all

.PHONY:		all clean fclean re
