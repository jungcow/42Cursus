# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 19:12:46 by jungwkim          #+#    #+#              #
#    Updated: 2021/12/23 22:36:01 by jungwkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	:	all clean fclean re

NAME	=	miniRT

CC		=	gcc
CFLAGS	:=	-Wall -Werror -Wextra -Ofast
LIBS	=	-L./lib/libft -lft \
			-L. -lmlx\
			-L./lib/minilibx_opengl_20191021 -lmlx \

INC		=	-I./includes -I./src -I./lib

SRCS_PARSE	=	$(addprefix ./src/parsing/, \
			parsing.c \
			validate/validate.c \
			validate/validate_r.c \
			validate/validate_a.c \
			validate/validate_c.c \
			validate/validate_l.c \
			validate/validate_sp.c \
			validate/validate_pl.c \
			validate/validate_sq.c \
			validate/validate_cy.c \
			validate/validate_tr.c \
			validate/validate_id.c \
			validate/validate_utils.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
)

SRCS_UTILS	=	$(addprefix ./src/utils/, \
			ft_swap.c \
			create_mlx.c \
			deg_to_rad.c \
			ft_min.c \
			get_color.c \
			print_vec.c \
)

SRCS_VEC	=	$(addprefix ./src/vec/, \
			add_vec.c \
			cmp_vec.c \
			cross_vec.c \
			dot_vec.c \
			div_vec.c \
			multi_vec.c \
			new_vec.c \
			normalize_vec.c \
			sub_vec.c \
			vec_multi_vec.c \
)

SRCS_WORLD	=	$(addprefix ./src/world/, \
			world.c \
			create/create.c \
			create/create_r.c \
			create/create_a.c \
			create/create_c.c \
			create/create_l.c \
			create/create_sp.c \
			create/create_sp_utils.c \
			create/create_pl.c \
			create/create_pl_utils.c \
			create/create_sq.c \
			create/create_sq_utils.c \
			create/create_cy.c \
			create/create_cy_utils.c \
			create/create_tr.c \
			create/create_tr_utils.c \
			create/create_hit.c \
			create/create_object.c \
			create/create_rotate.c \
			create/create_utils.c \
)

SRCS_TRACE	=	$(addprefix ./src/trace/, \
			trace.c \
			trace_world.c \
			trace_light.c \
			trace_diffuse.c \
			trace_specular.c \
			bmp.c \
)

SRCS_EVENT	=	$(addprefix ./src/event/, \
			event.c \
			event_key.c \
			event_button.c \
			event_cam.c \
			event_obj.c \
			event_switch.c \
)

SRCS		=	$(SRCS_PARSE) \
				$(SRCS_UTILS) \
				$(SRCS_VEC) \
				$(SRCS_WORLD) \
				$(SRCS_TRACE) \
				$(SRCS_EVENT) \
				main.c

OBJS		=	$(SRCS:.c=.o)

%.o			:	%.c
		$(CC) $(CFLAGS) $(INC) -c $< -o $@


$(NAME)		:	$(OBJS)
#make mms
		make opengl
		make libft
		$(CC) $(LIBS) $(INC) $(CFLAGS) -framework OpenGL -framework AppKit -o $@ $^

mms			:
		make -C lib/minilibx_mms_20200219
		cp -p lib/minilibx_mms_20200219/libmlx.dylib ./

opengl		:
		make -C lib/minilibx_opengl_20191021

libft		:
		make -C lib/libft

clean		:
		make -C lib/minilibx_mms_20200219 clean
		make -C lib/minilibx_opengl_20191021 clean
		make -C lib/libft clean
		rm -rf libmlx.dylib
		rm -rf $(OBJS)

fclean		:	clean
		make -C lib/libft fclean
		rm -rf $(NAME)

re			:	clean all

test		:	all clean
		./$(NAME) test.rt > test

all			:	$(NAME)
