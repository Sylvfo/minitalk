SRCS			= client.c	server.c client_bonus.c server_bonus.c
FLAGS			= -Wall -Werror -Wextra -g
CC				= gcc
RM				= rm -f
OBJ				=	$(SRCS:.c=.o)

PRINTF_DIR		= librairies/printf
PRINTF			= ./${PRINTF_DIR}/libftprintf.a
LIBFT_DIR		= librairies/libft
LIBFT 			= ./${LIBFT_DIR}/libft.a

all: server client

server:	server.o
		make -C ${PRINTF_DIR}
		make -C ${LIBFT_DIR}
		${CC} ${SFLAGS} -o server server.o ${PRINTF} ${LIBFT}

client: client.o 
		make -C ${PRINTF_DIR}
		make -C ${LIBFT_DIR}
		${CC} ${FLAGS} -o client client.o ${PRINTF} ${LIBFT}

server.o: server.c
	${CC} -c server.c 

client.o: client.c 
	${CC} -c client.c 

bonus:	server_bonus client_bonus

server_bonus:	server_bonus.o
		make -C ${PRINTF_DIR}
		make -C ${LIBFT_DIR}
		${CC} ${SFLAGS} -o server_bonus server_bonus.o ${PRINTF} ${LIBFT}

client_bonus: client_bonus.o 
		make -C ${PRINTF_DIR}
		make -C ${LIBFT_DIR}
		${CC} ${FLAGS} -o client_bonus client_bonus.o ${PRINTF} ${LIBFT}

server_bonus.o: server_bonus.c
	${CC} -c server_bonus.c

client_bonus.o: client_bonus.c 
	${CC} -c client_bonus.c 

clean:
			make clean -C ${PRINTF_DIR}
			make clean -C ${LIBFT_DIR}
			$(RM) $(OBJ)

fclean:		clean
			make fclean -C ${PRINTF_DIR}
			make fclean -C ${LIBFT_DIR}
				$(RM) server client server_bonus client_bonus

re:			fclean	all

.PHONY:		all re clean fclean bin