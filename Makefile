# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bglover <bglover@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 16:00:15 by bglover           #+#    #+#              #
#    Updated: 2019/11/11 17:19:38 by bglover          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
CC = gcc -g#-Wall -Wextra -Werror
SRC_DIR = srcs/
LIBFT_DIR = libft/
OBJ_DIR = obj/
#убрать -g из компиляции
PS_SRCS = ft_sort_a.c ft_sort_b.c ft_lstcom.c ft_pa_pb_ra_rb_rr.c ft_sa_sb_rra_rrb_rrr.c ft_init_ps.c \
ft_check_sort.c ft_calc_max.c ft_fill_order.c ft_for_three.c ft_print_com.c ft_push_swap.c ft_for_five.c \
ft_parse.c ft_free_all.c
CHECKER_SRCS = ft_checker.c ft_sa_sb_rra_rrb_rrr.c ft_init_ps.c ft_lstcom.c ft_check_sort.c ft_fill_order.c \
ft_pa_pb_ra_rb_rr.c ft_parse.c ft_free_all.c

CHECKER_OBJ = ${CHECKER_SRCS:c=o}
PS_OBJ = ${PS_SRCS:c=o}

all: $(CHECKER) $(PUSH_SWAP)

$(addprefix $(OBJ_DIR), %.o): $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -I libft/ -I include/ -c -o $@ $^

$(CHECKER): $(addprefix $(OBJ_DIR), $(CHECKER_OBJ))
	@make -C libft/
	@$(CC) $(addprefix $(OBJ_DIR), $(CHECKER_OBJ)) $(LIBFT_DIR)libft.a -I libft/ -I include/ -o $(CHECKER)
	@echo "🖕 "

$(PUSH_SWAP): $(addprefix $(OBJ_DIR), $(PS_OBJ))
	@$(CC) $(addprefix $(OBJ_DIR), $(PS_OBJ)) $(LIBFT_DIR)libft.a -I libft/ -I include/ -o $(PUSH_SWAP)
	@echo "🖕 "

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(CHECKER)
	@echo "\033[31m$(CHECKER)   💀"
	@rm -f $(PUSH_SWAP)
	@echo "$(PUSH_SWAP) 💀\033[m"

re: fclean all