CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_putx.c
OBJS = ${SRCS:.c=.o}
LIBC = ar rcs
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
#c.o:: Questo è l'obiettivo della regola. Specifica che la
#		regola serve a creare un file con estensione .o da un file sorgente con estensione .c.

#-c $<: Questa parte del comando dice al compilatore di generare un file oggetto (-c flag)
# 	   dal file sorgente specificato da $<.

#-o ${<:.c=.o}: Questa parte specifica il nome del file di output. ${<:.c=.o} è un'espressione
#				nel makefile che prende il nome del file sorgente ($<), sostituisce l'estensione .c con .o e 
#				lo imposta come nome del file di output.

${NAME}: ${OBJS}
	${LIBC}	${NAME}	${OBJS}

all:	${NAME}

clean:
	${RM}	${OBJS}

fclean:	clean
	${RM}	${NAME}

re:	fclean	all

.PHONY:	all	clean	fclean	re
