##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- project
##

SRC 	= 	main.c \
			src/create_map.c \
			src/display.c \
			src/display2.c \
			src/brush.c \
			src/event.c \
			src/event_map.c \
			src/event_map2.c \
			src/utils.c \
			src/brush_modify.c \
			src/button.c \
			src/init_data.c \
			src/init_obj.c \
			src/init_obj2.c \
			src/vertex.c \
			src/vertex2.c \
			src/menu.c \
			src/init_menu.c \
			src/read_write.c \
			src/read_write2.c \
			src/init_ui.c \
			src/destroy.c \
			src/destroy_obj.c \
			src/button_event.c \
			src/create_save.c \
			src/vertex_color.c \
			src/button_click.c \
			src/calc_brush_form.c \
			src/create_save_next.c

OBJ		=	$(SRC:.c=.o)

NAME 	=	my_world

RM 		=	rm -f

RM_TRASH=	*.o *~ *.gcno *.gcda libmy.a *.gch

CFLAGS	= 	-pedantic -Wall -Wextra -W -g -lm

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib && gcc $(OBJ) -o $(NAME) -L lib -lall $(CFLAGS) $(CSFML)

clean:
	$(RM) $(RM_TRASH)
	make fclean -C lib/
	make fclean -C lib/my/
	make fclean -C lib/my_printf/
	cd include && $(RM) $(RM_TRASH)
	cd src && $(RM) $(RM_TRASH)

fclean: clean
	$(RM) $(NAME)

re: fclean all
