SRCS			= client.c	server.c
FLAGS			= -Wall -Werror -Wextra -g
CC				= gcc
RM				= rm -f
OBJ				=	$(SRCS:.c=.o)

PRINTF			= printf
LIB				= ./${PRINTF}/libftprintf.a

all: server client

server:	server.o
		make -C ${PRINTF}
		${CC} ${SFLAGS} -o server server.o ${LIB}

client: client.o 
		make -C ${PRINTF}
		${CC} ${FLAGS} -o client client.o ${LIB}

server.o: server.c
	${CC} -c server.c 

client.o: client.c 
	${CC} -c client.c 

clean:
			make clean -C ${PRINTF}
			$(RM) $(OBJ)

fclean:		clean
			make fclean -C ${PRINTF}
				$(RM) server client

re:			fclean	all

.PHONY:		all re clean fclean bin