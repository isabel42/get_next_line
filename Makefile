SRCS	= get_next_line.c \
		  get_next_line_utils.c 
		  					  
OBJS 	= ${SRCS:.c=.o}

NAME 	= get_next_line.a

CC		= gcc

RM		= rm -f

AR		= ar rc

CFLAGS	= -Wextra -Wall -Werror -D BUFFER_SIZE=42

.c.o:	
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${AR} ${NAME} ${OBJS}
				ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

test:		all
			${CC} ${CFLAGS} print_test.c -L. -lftprintf
			./a.out
			rm a.out

.PHONY:		all clean fclean re
