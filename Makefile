FLAGS			= -Wall -Werror -Wextra
CC				= GCC
RM				= rm -f

LIBFT_DIR		= ./librairies/lift
LIBFT			= ./librairies/libft/libft.a
PRINTF_DIR		= ./librairies/printf
PRINTF			= ./librairies/printf/printf.a

$ (NAME):		$ (OBJ) $ (PRINTF) $ (LIBFT)

//voir message Allan

all: server client

server: server.o

