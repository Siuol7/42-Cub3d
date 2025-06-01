# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 22:10:11 by tripham           #+#    #+#              #
#    Updated: 2025/06/02 01:41:21 by caonguye         ###   ########.fr        #
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
LIB_DIR		= Library
GNL_DIR		= $(LIB_DIR)/get_next_line
LIBFT_DIR	= $(LIB_DIR)/libft
PRINTF_DIR	= $(LIB_DIR)/ft_printf_fd
MLX42_DIR	= libs/MLX42

PARSE_SRCS = $(PARSE_DIR)/map/map_validation.c 			\
			 $(PARSE_DIR)/map/is_closed.c				\
			 $(PARSE_DIR)/map/grid_validate.c			\
			 $(PARSE_DIR)/map/png_validate.c			\
			 $(PARSE_DIR)/map/read_grid.c				\
             $(PARSE_DIR)/map/map_utils.c				\
			 $(PARSE_DIR)/map/read_ele.c				\
			 $(PARSE_DIR)/map/read_map.c				\
			 $(PARSE_DIR)/utils_parsing/ft_error.c		\
			 $(PARSE_DIR)/utils_parsing/ft_space.c		\
			 $(PARSE_DIR)/utils_parsing/ft_2d_len.c		\
			 $(PARSE_DIR)/utils_parsing/ft_clean_2d.c	\
			 $(PARSE_DIR)/utils_parsing/ft_readline.c	\
			 $(PARSE_DIR)/utils_parsing/ft_get_color.c	\
			 $(PARSE_DIR)/utils_parsing/clean_cub3d.c	\
			 $(PARSE_DIR)/utils_parsing/ft_free_utils.c

MAIN_SRCS  = $(MAIN)/main.c

SRCS       = $(MAIN_SRCS) $(PARSE_SRCS) $(GNL_SRCS)
OBJS       = $(SRCS:.c=.o)

# --- LIBRARIES ---
LIBFT      = $(LIBFT_DIR)/libft.a
PRINTF     = $(PRINTF_DIR)/libftprintf.a

NAME       = cub3D

MLX_LINK   = -Llibs/MLX42/build -lmlx42 -lglfw -ldl -pthread -lm

all: mlx42 $(LIBFT) $(PRINTF) $(NAME)

mlx42:
	@ if [ ! -d "$(MLX42_DIR)" ]; then \
	    printf "Setting up MLX42…\n"; \
	    git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR) > /dev/null 2>&1; \
	    mkdir -p $(MLX42_DIR)/build; \
	    ( \
	      cd $(MLX42_DIR)/build && \
	      cmake .. > /dev/null 2>&1 && \
	      cmake --build . -j4 > /dev/null 2>&1 \
	    ); \
	    rm -rf $(MLX42_DIR)/.git; \
	    printf "Done\n"; \
	fi

$(LIBFT):
	@$(MAKE)  -s -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE)  -s -C $(PRINTF_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_LINK) -o $@

%.o:%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ${NAME}	:	${OBJS} ${LIBFT} ${PRINTF}
# 		@printf "\033[1;32m💻Launching Cub3D-42VN-Pasila"
# 		@for i in 1 2 3; do \
# 			printf "\033[0;32m."; sleep 0.3; \
# 		done; \
# 		for i in 1 2 3; do \
# 			printf "\b \b"; sleep 0.3; \
# 		done; \
# 		for i in 1 2 3; do \
# 			printf "\033[0;32m."; sleep 0.3; \
# 		done; \
# 		for i in 1 2 3; do \
# 			printf "\b \b"; sleep 0.3; \
# 		done; \
# 		printf "\033[0m\n"

clean:
	@$(MAKE) clean -s -C $(LIBFT_DIR)
	@$(MAKE) clean -s -C $(PRINTF_DIR)
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -s -C $(LIBFT_DIR)
	@$(MAKE) fclean -s -C $(PRINTF_DIR)
	@rm -f $(NAME)
	@rm -rf libs

re: fclean all

.PHONY: all clean fclean re mlx42