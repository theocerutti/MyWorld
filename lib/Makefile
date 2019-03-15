##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- LIBMY COMPIL
##

NAME		= 	liball.a

RM 			=	@rm -f

CFLAGS		= 	-pedantic -Wall -Wextra -W

all: compil clean

compil:
	make -C my
	make -C my_printf
	cp my/libmy.a .
	cp my_printf/libprintf.a .
	@ar -x libmy.a
	@ar -x libprintf.a
	@ar rc $(NAME) *.o

clean:
	$(RM) *.o
	$(RM) libprintf.a
	$(RM) libmy.a

fclean: clean
	$(RM) liball.a

re: fclean all
