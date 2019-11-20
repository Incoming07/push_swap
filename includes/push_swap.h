/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:06:39 by bglover           #+#    #+#             */
/*   Updated: 2019/11/20 21:08:22 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "/Users/bglover/.brew/Cellar/sdl2/2.0.10/include/SDL2/SDL.h"

typedef	struct			s_win
{
	SDL_Window 			*window_a;
	SDL_Window 			*window_b;
	SDL_Renderer 		*ren_a;
	SDL_Renderer 		*ren_b;
	SDL_Surface 		*surf;
	SDL_Rect 			destR;
	SDL_Event			e;
	int					max;
}						t_win;

typedef	struct
{
	int					next;
	int					max;
	int					flag;
	int					i;
	int					a_b;
	int					v;
	t_win				*new_win;
}						t_ps;

typedef struct			s_com_list
{
	char				*com;
	struct s_com_list	*next;
}						t_c_list;

typedef	struct			s_num_list
{
	struct s_num_list	*previous;
	long long			value;
	int					order;
	int					sort;
	int					flag;
	SDL_Texture 		*txt_a;
	SDL_Texture 		*txt_b;
	struct s_num_list	*next;
}						t_n_list;

char					*ft_pa(t_n_list **stack_a, t_n_list **stack_b);
char					*ft_pb(t_n_list **stack_a, t_n_list **stack_b);
char					*ft_ra(t_n_list **stack_a);
char					*ft_rb(t_n_list **stack_b);
char					*ft_rr(t_n_list **stack_a, t_n_list **stack_b);
char					*ft_rra(t_n_list **stack_a);
char					*ft_rrb(t_n_list **stack_b);
char					*ft_rrr(t_n_list **stack_a, t_n_list **stack_b);
char					*ft_sa(t_n_list **stack_a);
char					*ft_sb(t_n_list **stack_b);
t_c_list				*ft_lstcomnew(char *com);
t_n_list				*ft_lstnews(long long value);
int						ft_lstlens(t_n_list **lst);
void					ft_lstadds(t_n_list **first, t_n_list *second);
void					ft_lstcomadd(t_c_list **com_list_old,
						t_c_list *com_list_new);
void					ft_for_three(t_n_list **stack_b,
						t_c_list **com_stack);
int						ft_fill_order(t_n_list **stack_a);
int						ft_calc_max(t_n_list **stack);
int						ft_check_sort(t_n_list **stack_a, t_ps **new_ps);
int						ft_parse(char **argv, int argc, t_n_list **stack_a, t_ps **new_ps);
int						ft_free_temp(char **temp, int i);
void					ft_start_sort_a(t_n_list **stack_a,
						t_n_list **stack_b, t_ps **new_ps,
						t_c_list **com_stack);
void					ft_start_sort_b(t_n_list **stack_a,
						t_n_list **stack_b, t_ps **new_ps,
						t_c_list **com_stack);
void					ft_print_com(t_c_list **com_stack);
int						ft_free_all(t_n_list **stack_a, t_n_list **stack_b,
						t_ps **new_ps, t_c_list **com_stack);
void					ft_for_five(t_n_list **stack_a, t_n_list **stack_b,
						t_c_list **com_stack);
void					ft_init_ps(t_n_list **stack_a, t_ps **new_ps);
void					ft_vis(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps);
void					ft_push_next(t_n_list **stack_a, t_n_list **stack_b,
						t_ps **new_ps, t_c_list **com_stack);

#endif
