/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:47:58 by bglover           #+#    #+#             */
/*   Updated: 2019/11/20 22:18:01 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Ловим разные ошибки
*/

void	ft_sdl_error(t_ps **new_ps, t_n_list **stack_a)
{
	const char	*out;

	out = SDL_GetError();
	write(1, "SDL_Error:", 10);
	write(1, out, 10);
	SDL_DestroyRenderer((*new_ps)->new_win->ren_a);
	SDL_DestroyRenderer((*new_ps)->new_win->ren_b);
	SDL_DestroyWindow((*new_ps)->new_win->window_a);
	SDL_DestroyWindow((*new_ps)->new_win->window_b);
	if ((*stack_a)->txt_a || (*stack_a)->txt_b)
		while ((*stack_a)->next)
		{
			SDL_DestroyTexture((*stack_a)->txt_a);
			SDL_DestroyTexture((*stack_a)->txt_b);
		}
	SDL_Quit();
	exit(-1);
}

/*
** Присваивание разных цветов элементам массива
*/

void	ft_texturing(t_n_list **stack_a, t_ps **new_ps)
{
	int r;

	while (ft_lstlens(stack_a) > 0)
	{
		r = (*stack_a)->order * 2;
		if (SDL_SetSurfaceColorMod((*new_ps)->new_win->surf, r, 0, 0) != 0)
			ft_sdl_error(new_ps, stack_a);
		if (!((*stack_a)->txt_a =
			SDL_CreateTextureFromSurface((*new_ps)->new_win->ren_a,
				(*new_ps)->new_win->surf)))
			ft_sdl_error(new_ps, stack_a);
		if (!((*stack_a)->txt_b =
			SDL_CreateTextureFromSurface((*new_ps)->new_win->ren_b,
				(*new_ps)->new_win->surf)))
			ft_sdl_error(new_ps, stack_a);
		(*stack_a) = (*stack_a)->next;
	}
}

/*
** Инициализация и присваивание элементам цветов и текстур
*/

void	ft_init_vis(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		int max)
{
	int			r;
	t_n_list	*tmp;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_sdl_error(new_ps, stack_a);
	if (!((*new_ps)->new_win->window_a = SDL_CreateWindow("Stack_a",
		900, 200, 600, 600, SDL_WINDOW_OPENGL)))
		ft_sdl_error(new_ps, stack_a);
	if (!((*new_ps)->new_win->window_b = SDL_CreateWindow("Stack_b",
		1500, 200, 600, 600, SDL_WINDOW_OPENGL)))
		ft_sdl_error(new_ps, stack_a);
	if (!((*new_ps)->new_win->ren_a =
		SDL_CreateRenderer((*new_ps)->new_win->window_a, -1, 0)))
		ft_sdl_error(new_ps, stack_a);
	if (!((*new_ps)->new_win->ren_b =
		SDL_CreateRenderer((*new_ps)->new_win->window_b, -1, 0)))
		ft_sdl_error(new_ps, stack_a);
	if (!((*new_ps)->new_win->surf =
		SDL_CreateRGBSurface(0, 20, 20, 8, 0, 0, 0, 0)))
		ft_sdl_error(new_ps, stack_a);
	tmp = (*stack_a);
	ft_texturing(stack_a, new_ps);
	(*stack_a) = tmp;
}

/*
** Отрисовка линий на рендере
*/

void	ft_draw_rect(t_n_list **stack_print, SDL_Texture *txt,
		SDL_Renderer *ren, t_ps **new_ps)
{
	if (SDL_PollEvent(&(*new_ps)->new_win->e))
		(*new_ps)->v = 0;
	(*new_ps)->new_win->destR.h = 600 / (*new_ps)->new_win->max;
	(*new_ps)->new_win->destR.w = (*stack_print)->order *
		(((*new_ps)->new_win->max > 100) ? 2 : 5);
	(*new_ps)->new_win->destR.x = 0;
	if (!(*stack_print)->previous)
		(*new_ps)->new_win->destR.y = 0;
	else
		(*new_ps)->new_win->destR.y += (*new_ps)->new_win->destR.h;
	SDL_RenderCopy(ren, txt, NULL, &(*new_ps)->new_win->destR);
	if ((*stack_print)->next)
		(*stack_print) = (*stack_print)->next;
	else
		return ;
	if ((*new_ps)->a_b)
		ft_draw_rect(stack_print, (*stack_print)->txt_a, ren, new_ps);
	else
		ft_draw_rect(stack_print, (*stack_print)->txt_b, ren, new_ps);
	while ((*stack_print)->previous)
		(*stack_print) = (*stack_print)->previous;
}

/*
** Начало визуализации
*/

void	ft_vis(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps)
{
	if (!(*new_ps)->v)
		return ;
	(*new_ps)->new_win->max = ft_calc_max(stack_a);
	(*new_ps)->new_win->destR.y = 0;
	if (!((*stack_a)->txt_a))
		ft_init_vis(stack_a, stack_b, new_ps, (*new_ps)->new_win->max);
	else
	{
		SDL_SetRenderDrawColor((*new_ps)->new_win->ren_a, 255, 255, 255, 255);
		SDL_SetRenderDrawColor((*new_ps)->new_win->ren_b, 255, 255, 255, 255);
	}
	SDL_RenderClear((*new_ps)->new_win->ren_a);
	(*new_ps)->a_b = 1;
	ft_draw_rect(stack_a, (*stack_a)->txt_a, (*new_ps)->new_win->ren_a, new_ps);
	SDL_RenderPresent((*new_ps)->new_win->ren_a);
	(*new_ps)->new_win->destR.y = 0;
	SDL_RenderClear((*new_ps)->new_win->ren_b);
	if (ft_lstlens(stack_b) > 0)
	{
		(*new_ps)->a_b = 0;
		ft_draw_rect(stack_b, (*stack_b)->txt_b,
			(*new_ps)->new_win->ren_b, new_ps);
		SDL_RenderPresent((*new_ps)->new_win->ren_b);
	}
	SDL_Delay((*new_ps)->new_win->max > 50 ? 10 : 50);
	if (!ft_check_sort(stack_a, new_ps))
		SDL_Delay(3000);
}
