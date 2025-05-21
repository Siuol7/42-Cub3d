# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 22:10:11 by tripham           #+#    #+#              #
#    Updated: 2025/05/19 19:28:51 by tripham          ###   ########.fr        #
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

# --- LINK FLAGS ---
MLX_LINK   = -Llibs/MLX42/build -lmlx42 -lglfw -ldl -pthread -lm

# --- DIRECTORIES ---
SRC_DIR    = Srcs
LIB_DIR    = Library
GNL_DIR    = $(LIB_DIR)/get_next_line
LIBFT_DIR  = $(LIB_DIR)/libft
PRINTF_DIR = $(LIB_DIR)/ft_printf_fd
MLX42_DIR  = libs/MLX42

# --- SOURCE FILES ---
GNL_SRCS   = $(GNL_DIR)/get_next_line.c \
             $(GNL_DIR)/get_next_line_utils.c

PARSE_SRCS = $(SRC_DIR)/parsing/map/map_validation.c \
             $(SRC_DIR)/parsing/map/map_utils.c			\
			 $(SRC_DIR)/parsing/utils_parsing/ft_error.c	\
			 $(SRC_DIR)/parsing/utils_parsing/ft_space.c	
#$(SRC_DIR)/parsing/read_map.c 

MAIN_SRCS  = $(SRC_DIR)/main.c

# add other .c files here...
OTHER_SRCS = #$(SRC_DIR)/ray_casting/ray_casting.c \
             $(SRC_DIR)/event/key_inputs.c \

SRCS       = $(MAIN_SRCS) $(PARSE_SRCS) $(GNL_SRCS) $(OTHER_SRCS)
OBJS       = $(SRCS:.c=.o)

# --- LIBRARIES ---
LIBFT      = $(LIBFT_DIR)/libft.a
PRINTF     = $(PRINTF_DIR)/libftprintf.a

# --- EXECUTABLE ---
NAME       = cub3D

all: mlx42 $(LIBFT) $(PRINTF) $(NAME)

# clone & build MLX42 if necessary
mlx42:
	@if [ ! -d "$(MLX42_DIR)" ]; then \
	  git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR); \
	  mkdir -p $(MLX42_DIR)/build; \
	  cd $(MLX42_DIR)/build && cmake .. && cmake --build . -j4; \
	  rm -rf $(MLX42_DIR)/.git; \
	fi

# build libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# build ft_printf
$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

# link final binary
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_LINK) -o $@

# generic rule to compile .c -> .o
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

# --- PHONY ---
.PHONY: all clean fclean re mlx42