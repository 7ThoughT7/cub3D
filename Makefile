NAME	= cub3D
#NAME_B	= cub3D_bonus
HEADER	= cub3D.h

LIST		= GNL/get_next_line.c GNL/get_next_line_utils.c \
			cub3D.c lib_func_0.c addit_func_0.c read_map.c	\
			open_map.c ft_split.c read_file.c check_map.c	\
			addit_func_1.c

OBJ			= $(LIST:.c=.o)

FLAGS       = -Wall -Wextra -Werror

%.o:%.c		$(HEADER)
		    gcc $(FLAGS) -Imlx -c $< -o $@

$(NAME) :	$(OBJ) $(HEADER)
			gcc $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all :		$(NAME)

clean :
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re