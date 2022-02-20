# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/18 22:32:44 by flormich          #+#    #+#              #
#    Updated: 2021/12/14 14:21:22 by pnuti            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CFLAGS = -Wall -Wextra -Werror -g
DIR_LIB = libft
DIR_P = parsing
DIR_E = echo
DIR_ENV = env
DIR_D = dir
DIR_G = gnl
HEADER = $(DIR_LIB)/libft.h minishell_libs.h

SRC = ms_main.c ms_error.c ms_launch_cmd.c ms_sig_hook.c ms_run_exit.c \
	ms_set_redirection.c
SRC_P = $(DIR_P)/ms_0_expand_input.c $(DIR_P)/ms_1_extract_cmd.c \
	$(DIR_P)/ms_2_parse_input.c $(DIR_P)/ms_2_parse_input_utils.c \
	$(DIR_P)/ms_2_parse_input_utils_2.c $(DIR_P)/ms_extract_utils.c \
	$(DIR_P)/ms_extract_files.c $(DIR_P)/ms_3_extract_redirection.c \
	$(DIR_P)/ms_add_path.c $(DIR_P)/ms_clean_arr.c $(DIR_P)/ms_expand_variable.c \
	$(DIR_P)/ms_expand_variable_utils.c $(DIR_P)/ms_expand_variable_utils_2.c \
	$(DIR_P)/ms_buffer.c $(DIR_P)/ms_utils_isvariable.c
SRC_E = $(DIR_E)/ms_echo.c $(DIR_E)/ms_echo_utils.c
SRC_ENV =	$(DIR_ENV)/ms_env.c $(DIR_ENV)/ms_export.c $(DIR_ENV)/ms_unset.c \
			$(DIR_ENV)/ms_manage_env.c $(DIR_ENV)/ms_get_env.c \
			$(DIR_ENV)/ms_free_env.c
SRC_D = $(DIR_D)/ms_cd.c $(DIR_D)/ms_pwd.c
SRC_G = $(DIR_G)/ms_gnl.c $(DIR_G)/ms_gnl_utils.c \
	$(DIR_G)/ms_read_till_limiter.c

OBJ = $(SRC:.c=.o)
OBJ_P = $(SRC_P:.c=.o)
OBJ_E = $(SRC_E:.c=.o)
OBJ_LIB = $(SRC_LIB:.c=.o)
OBJ_ENV = $(SRC_ENV:.c=.o)
OBJ_D = $(SRC_D:.c=.o)
OBJ_G = $(SRC_G:.c=.o)

all: $(NAME)

$(NAME): $(HEADER) $(OBJ) $(OBJ_P) $(OBJ_E) $(OBJ_LIB) $(OBJ_ENV) $(OBJ_D) $(OBJ_G)
	make all -C ./$(DIR_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_P) $(OBJ_E) $(OBJ_ENV) $(OBJ_D) $(OBJ_G) -o $(NAME) -L libft/ -lft -lreadline

clean:
	make clean -C ./$(DIR_LIB)
	rm -f $(OBJ) $(OBJ_P) $(OBJ_E) $(OBJ_ENV) $(OBJ_D) $(OBJ_G) minishell.o

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./$(DIR_LIB)

re: fclean all

.PHONY: all clean fclean re
