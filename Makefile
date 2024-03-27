SRCS			= client.c	server.c
FLAGS			= -Wall -Werror -Wextra -g
CC				= gcc
RM				= rm -f
OBJ				=	$(SRCS:.c=.o)

PRINTF			= ft_printf
LIB				= ./${PRINTF}/libftprintf.a

all: server client

server.o: server.c
	${CC} -c server.c 

client.o: client.c 
	${CC} -c client.c 

clean:
			$(RM) $(OBJ)

fclean:		clean
				$(RM) server client

re:			fclean	all

.PHONY:		all re clean fclean bin