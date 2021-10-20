GRN = \033[1;32m
YEL = \033[0;33m
RED = \033[1;31m
WHITE = \033[0m

NAME = cub3D
FLAGS = -Wall -Wextra -Werror
CC = gcc

OBJ_DIR 	= obj_dir
LIBFT		= libft/libft.a
FT_PRINTF	= ft_printf/libftprintf.a

BONNUS 		= 0

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX = -L ./mlx_linux -l mlx -l Xext -l X11 -lm -lz
	RESOLUTION = resol_linux.c
endif
ifeq ($(UNAME_S), Darwin)
	MLX = -L./mlx_mac -lmlx -framework OpenGL -framework AppKit
	RESOLUTION = resol_mac.c
endif


ifeq ($(BONNUS),0)
	C_MAIN = main/main.c main/render.c
else
	C_MAIN = bonus/main_bonus.c bonus/render_bonus.c
endif

C_BONUS			=	bonus/print_sky_bonus.c \
					bonus/print_hits_minimap.c \
					bonus/minimap_grid_bonus.c \
					bonus/minimap_rays_bonus.c 
					
C_COMMON		= 	main/calc_dist_and_height.c \
 					main/cub3d_utils.c \
					main/print_floor_and_sky.c \
					main_utils/$(RESOLUTION) \
					main_utils/keys.c \
					main_utils/my_pixel_put.c \
					get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c \
					check_map_file/check_map_file.c \
					check_map_file/check_chars_in_line.c \
					check_map_file/check_map_file_utils.c \
					read_texture/get_texture_from_image.c \
					read_map_data/read_map_data.c \
					read_map_data/get_paths_and_colors.c \
					read_map_data/get_resol.c \
					read_map_data/read_map_colors.c \
					read_map_data/read_map_colors_utils.c \
					read_map_data/read_map_data_utils.c \
					read_map_data/check_floor_plan.c \
					read_map_data/check_floor_each_field.c \
					read_map_data/make_floor_arr.c \
					read_map_data/insert_walls.c \
					get_hits/quad_1.c get_hits/quad_2.c \
					get_hits/quad_3.c get_hits/quad_4.c \
					get_new_position/get_new_position_w.c \
					get_new_position/get_new_position_s.c \
					get_new_position/get_new_position_a.c \
					get_new_position/get_new_position_d.c \
					print_map_info.c

O_MAIN		= $(patsubst %, $(OBJ_DIR)/%, $(C_MAIN:.c=.o))
O_COMMON 	= $(patsubst %, $(OBJ_DIR)/%, $(C_COMMON:.c=.o))
O_BONUS		= $(patsubst %, $(OBJ_DIR)/%, $(C_BONUS:.c=.o))


ifeq ($(BONNUS),0)
	OBJ_FILES = $(O_MAIN) $(O_COMMON)
else
	OBJ_FILES = $(O_MAIN) $(O_COMMON) $(O_BONUS)
endif


all:	makedir $(NAME)
		@echo "$(GRN)\n--- MAKEFILE DONE ------------ \n$(WHITE)"
		
makedir:
		@echo "$(GRN)\n --- START MAKEFILE ------------ \n$(WHITE)"
		@echo "$(GRN) Making obj_dir Directory $(WHITE)"
		mkdir -p $(OBJ_DIR)/main $(OBJ_DIR)/main_utils  $(OBJ_DIR)/check_map_file
		mkdir -p $(OBJ_DIR)/get_hits  $(OBJ_DIR)/get_new_position $(OBJ_DIR)/get_next_line 
		mkdir -p $(OBJ_DIR)/read_map_data $(OBJ_DIR)/read_texture $(OBJ_DIR)/bonus

		@echo "$(GRN)\n Making libft.a and libftprintf.a $(WHITE)"
		make -C ./libft
		make -C ./ft_printf


$(OBJ_DIR)/%.o: 	%.c
#		@echo "$(YEL) --- making %.o file --- $(WHITE)"
		gcc -g $(FLAGS) -I./mlx -c $< -o $@


$(NAME): $(OBJ_FILES)
		@echo "$(GRN)\n - Making cub3D Executable --- $(WHITE)"
		gcc $^ $(FLAGS) $(MLX) $(LIBFT) $(FT_PRINTF) -o $(NAME)

bonus:
		@echo "$(GRN)\n--- Start Makefile Cub3D, (Bonus == $(BONNUS), System == $(UNAME_S)) --- $(WHITE)"
		@$(MAKE) $(MAKEDIR) BONNUS=1


re:		fclean all


clean:
		rm -rf $(OBJ_DIR)
#		cd libft && make fclean
		

fclean:	clean
		cd libft && make fclean
		cd ft_printf && make fclean
		rm -f cub3D

.PHONY: fclean bonus clean re all mlx clean_mlx
