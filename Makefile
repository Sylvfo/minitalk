NAME			= minitalk
SRCS			= client.c	server.c
FLAGS			= -Wall -Werror -Wextra -g
CC				= gcc
RM				= rm -f
OBJ				=	$(SRCS:.c=.o)

all: server client

server: server.o 

client: client.o

server.o: server.c
	${CC} -c server.c 

client.o: client.c 
	${CC} -c client.c 

clean:
			$(RM) $(OBJ)

fclean:		clean
				$(RM) $(NAME)

.PHONY:		all re clean fclean bin