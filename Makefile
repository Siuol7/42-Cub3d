# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 22:10:11 by tripham           #+#    #+#              #
#    Updated: 2025/05/21 21:05:10 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- COMPILER & FLAGS ---
CC         = cc
CFLAGS     = -Wall -Wextra -Werror

# --- INCLUDE PATHS ---
INCLUDES   = -I includes \
             -I Library/libft \
             -I Library/ft_printf_fd \
             -I libs/MLX42/include/MLX42

# --- DIRECTORIES ---
SRC_DIR		= Srcs
PARSE_DIR	= Srcs/parsing
LIB_DIR		= Library
GNL_DIR		= $(LIB_DIR)/get_next_line
LIBFT_DIR	= $(LIB_DIR)/libft
PRINTF_DIR	= $(LIB_DIR)/ft_printf_fd
MLX42_DIR	= libs/MLX42

# --- SOURCE FILES ---
GNL_SRCS   = $(GNL_DIR)/get_next_line.c \
             $(GNL_DIR)/get_next_line_utils.c

PARSE_SRCS = $(PARSE_DIR)/map/map_validation.c \
             $(PARSE_DIR)/map/map_utils.c			\
			 $(PARSE_DIR)/map/read_ele.c			\
			 $(PARSE_DIR)/map/read_map.c				\
			 $(PARSE_DIR)/utils_parsing/ft_error.c	\
			 $(PARSE_DIR)/utils_parsing/ft_space.c	\
			 $(PARSE_DIR)/utils_parsing/ft_2d_len.c	\
			 $(PARSE_DIR)/utils_parsing/ft_clean_2d.c	\
			 $(PARSE_DIR)/utils_parsing/ft_readline.c

MAIN_SRCS  = $(SRC_DIR)/main.c

SRCS       = $(MAIN_SRCS) $(PARSE_SRCS) $(GNL_SRCS)
OBJS       = $(SRCS:.c=.o)

# --- LIBRARIES ---
LIBFT      = $(LIBFT_DIR)/libft.a
PRINTF     = $(PRINTF_DIR)/libftprintf.a

NAME       = cub3D

MLX_LINK   = -Llibs/MLX42/build -lmlx42 -lglfw -ldl -pthread -lm

all: mlx42 $(LIBFT) $(PRINTF) $(NAME)

mlx42:
	@if [ ! -d "$(MLX42_DIR)" ]; then \
	  git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR); \
	  mkdir -p $(MLX42_DIR)/build; \
	  cd $(MLX42_DIR)/build && cmake .. && cmake --build . -j4; \
	  rm -rf $(MLX42_DIR)/.git; \
	fi

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_LINK) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME)
	rm -rf libs

re: fclean all

.PHONY: all clean fclean re mlx42