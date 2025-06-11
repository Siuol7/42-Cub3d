# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 22:10:11 by tripham           #+#    #+#              #
#    Updated: 2025/06/11 10:15:28 by caonguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC         = cc
CFLAGS     = -Wall -Wextra -Werror

INCLUDES   = -I includes 								\
             -I Library/libft 							\
             -I Library/ft_printf_fd 					\
             -I libs/MLX42/include/MLX42

# --- DIRECTORIES ---
SRC_DIR		= Srcs
MAIN		= Main
PARSE_DIR	= Srcs/parsing
EXEC_DIR	= Srcs/Execution
INIT_DIR	= $(EXEC_DIR)/Init
HANDLER_DIR = $(EXEC_DIR)/Handler
ERROR_DIR	= $(EXEC_DIR)/Error
LIB_DIR		= Library
GNL_DIR		= $(LIB_DIR)/get_next_line
LIBFT_DIR	= $(LIB_DIR)/libft
PRINTF_DIR	= $(LIB_DIR)/ft_printf_fd
MLX42_DIR	= libs/MLX42

PARSE_SRCS 	= $(PARSE_DIR)/map/map_validation.c 				\
			  $(PARSE_DIR)/map/is_closed.c						\
			  $(PARSE_DIR)/map/grid_validate.c					\
			  $(PARSE_DIR)/map/png_validate.c					\
			  $(PARSE_DIR)/map/read_grid.c						\
              $(PARSE_DIR)/map/map_utils.c						\
			  $(PARSE_DIR)/map/read_ele.c						\
			  $(PARSE_DIR)/map/read_map.c						\
			  $(PARSE_DIR)/utils_parsing/ft_error.c				\
			  $(PARSE_DIR)/utils_parsing/ft_space.c				\
			  $(PARSE_DIR)/utils_parsing/ft_2d_len.c			\
			  $(PARSE_DIR)/utils_parsing/ft_clean_2d.c			\
			  $(PARSE_DIR)/utils_parsing/ft_readline.c			\
			  $(PARSE_DIR)/utils_parsing/ft_get_color.c			\
			  $(PARSE_DIR)/utils_parsing/ft_free_utils.c

EXEC_SRCS	= $(INIT_DIR)/system_init.c							\
			  $(INIT_DIR)/Assets/assets_color.c					\
			  $(INIT_DIR)/Assets/assets_graphic.c				\
			  $(INIT_DIR)/Assets/assets_init.c					\
			  $(INIT_DIR)/Assets/assets_sprite.c				\
			  $(INIT_DIR)/Assets/assets_utility.c				\
			  $(INIT_DIR)/Ray/ray_init.c						\
			  $(HANDLER_DIR)/Input/handler_input.c				\
			  $(HANDLER_DIR)/Input/input_keyboard.c				\
			  $(HANDLER_DIR)/Input/input_mouse.c				\
			  $(HANDLER_DIR)/Input/input_move.c					\
			  $(HANDLER_DIR)/Position/handler_position.c		\
			  $(HANDLER_DIR)/Position/position_back.c			\
			  $(HANDLER_DIR)/Position/position_validate.c		\
			  $(HANDLER_DIR)/Ray_casting/handler_raycasting.c	\
			  $(HANDLER_DIR)/Ray_casting/rc_hit_point.c			\
			  $(HANDLER_DIR)/Ray_casting/rc_process.c			\
			  $(HANDLER_DIR)/Render/handler_render.c			\
			  $(HANDLER_DIR)/Render/render_minimap.c			\
			  $(HANDLER_DIR)/Render/render_miniplayer.c			\
			  $(HANDLER_DIR)/Render/render_player.c				\
			  $(HANDLER_DIR)/Render/render_scene.c				\
			  $(HANDLER_DIR)/Render/render_utility.c			\
			  $(HANDLER_DIR)/Render/render_sprite.c				\
			  $(HANDLER_DIR)/Render/render_canvas.c				\
			  $(HANDLER_DIR)/handler_loop.c						\
			  $(HANDLER_DIR)/handler_close.c					\
			  $(ERROR_DIR)/clean_assets.c						\
			  $(ERROR_DIR)/error.c								\
			  $(EXEC_DIR)/Display/display.c

MAIN_SRCS 	= $(MAIN)/main.c									\
			  $(MAIN)/end.c										\

SRCS       = $(MAIN_SRCS) $(PARSE_SRCS) $(EXEC_SRCS) $(GNL_SRCS)
OBJS       = $(SRCS:.c=.o)

# --- LIBRARIES ---
LIBFT      = $(LIBFT_DIR)/libft.a
PRINTF     = $(PRINTF_DIR)/libftprintf.a

NAME       = cub3D

MLX_LINK   = -Llibs/MLX42/build -lmlx42 -lglfw -ldl -pthread -lm

all: .mlx42 $(LIBFT) $(PRINTF) $(NAME)

.mlx42:
	@printf "\033[1;33mMLX\033[1;32m 💻Setting up…\n"
	@rm -rf $(MLX42_DIR)
	@{ \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR) > /dev/null 2>&1 && \
		cd $(MLX42_DIR) && \
		mkdir -p build && cd build && \
		cmake .. > /dev/null 2>&1 && \
		cmake --build . -j4 > /dev/null 2>&1; \
	} || { echo "\033[0;31m❌ MLX42 build failed\033[0m"; exit 1; }
	@rm -rf $(MLX42_DIR)/.git
	@touch .mlx42
	@echo "\033[\033[1;33mMLX\033[1;32m ✅Done"

$(LIBFT):
	@$(MAKE)  -s -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE)  -s -C $(PRINTF_DIR)

$(NAME): .mlx42 $(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_LINK) -o $@
	@printf "\033[1;33m42VN-Pasila \033[1;32m 💻Launching"
	@for i in 1 2 3; do \
		printf "\033[0;32m."; sleep 0.15; \
	done; \
	for i in 1 2 3; do \
		printf "\b \b"; sleep 0.15; \
	done; \
	for i in 1 2 3; do \
		printf "\033[0;32m."; sleep 0.15; \
	done; \
	for i in 1 2 3; do \
		printf "\b \b"; sleep 0.15; \
	done; \
	printf "\033[0m\n"

$(OBJS): %.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) clean -s -C $(LIBFT_DIR)
	@$(MAKE) clean -s -C $(PRINTF_DIR)
	@rm -f $(OBJS)
	@rm -f .mlx42

fclean: clean
		@printf "\033[1;33m42VN-Pasila\033[1;32m 💻Cleaning"
		@for i in 1 2 3; do \
			printf "\033[0;32m."; sleep 0.15; \
		done; \
		for i in 1 2 3; do \
			printf "\b \b"; sleep 0.15; \
		done; \
		for i in 1 2 3; do \
			printf "\033[0;32m."; sleep 0.15; \
		done; \
		for i in 1 2 3; do \
			printf "\b \b"; sleep 0.15; \
		done; \
		printf "\033[0m\n"
		@echo "\033[1;33m42VN-Pasila\033[1;32m ✅Done"
	@$(MAKE) fclean -s -C $(LIBFT_DIR)
	@$(MAKE) fclean -s -C $(PRINTF_DIR)
	@rm -f $(NAME)
	@rm -rf libs
	@rm -f .mlx42

re: fclean all

.PHONY: all clean fclean re mlx42