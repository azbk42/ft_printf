NAME		= libftprintf.a
SRCS		= ft_printf.c ft_printf_utils.c

OBJS		= ${SRCS:.c=.o}
CC			= cc -Wall -Wextra -Werror

.c.o:
			${CC} -I. -c $< -o ${<:.c=.o}


$(NAME):	${OBJS} ft_printf.h
			ar rcs ${NAME} ${OBJS}
			
all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re