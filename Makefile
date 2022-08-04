NAME	=	philo

SRCS	=	src/*.c main.c

OBJCT	=	${SRCS:.c=.o}

RM		=	rm -f

CC		=	gcc -Wall -Wextra -Werror #-fsanitize=address

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(SRCS) -o $(NAME)

clean :
	${RM} ${OBJCT}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY:		all clean fclean re bonus