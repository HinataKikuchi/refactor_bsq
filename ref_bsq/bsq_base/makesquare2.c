/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makesquare2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HINATA <HINATA@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/08 11:19:45 by HINATA           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern	int g_max;
extern	int g_col;
extern	int g_row;

int		ft_check_vertical_and_horizen_edge(char **map, t_tempcrs *p_tempcrs, t_info *p_info)
{
	int i;

	i = 0;
	while (i <= p_tempcrs->size)
	{
		if (ft_check_map_edge(map, p_tempcrs->col + i,
		p_tempcrs->row + p_tempcrs->size, p_info) == FAIL)
		{
			return (FAIL);
		}
		i++;
	}
	i = 0;
	while (i <= p_tempcrs->size)
	{
		if (ft_check_map_edge(map, p_tempcrs->col + p_tempcrs->size,
		p_tempcrs->row + i, p_info) == FAIL)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

void	ft_check_maximum_size(char **map, t_tempcrs *p_tempcrs, t_info *p_info)
{
	p_tempcrs->size = 0;
	while (ft_check_vertical_and_horizen_edge(map, p_tempcrs, p_info) == 1)
	{
		p_tempcrs->size++;
	}
	if (g_max < p_tempcrs->size)
	{
		g_max = p_tempcrs->size;
		g_col = p_tempcrs->col;
		g_row = p_tempcrs->row;
	}
}

void	ft_put_map(char **map, t_info *p_info)
{
	int i;
	int j;

	i = 1;
	while (i <= p_info->num_rows)
	{
		j = 0;
		while (j < ft_map_colsize(map))
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_change_map(char **map, t_info *p_info)
{
	int		i;
	int		j;
	t_bsq	*p_bsq;

	i = 0;
	p_bsq = malloc(sizeof(t_bsq));
	set_bsq(p_bsq);
	while (i < g_max)
	{
		j = 0;
		while (j < g_max)
		{
			map[g_row + i][g_col + j] = p_info->full;
			j++;
		}
		i++;
	}
	ft_put_map(map, p_info);
	free(p_bsq);
	return ;
}

void	ft_make_map(char **map, t_info *p_info)
{
	t_tempcrs *p_tempcrs;

	g_max = 0;
	g_col = 0;
	g_row = 0;
	p_tempcrs = malloc(sizeof(t_tempcrs));
	set_tempcrs(p_tempcrs);
	while (p_tempcrs->row <= p_info->num_rows)
	{
		p_tempcrs->col = 0;
		while (p_tempcrs->col < ft_map_colsize(map))
		{
			if (ft_check_map_edge(map, p_tempcrs->col,
			p_tempcrs->row, p_info) == 1)
			{
				ft_check_maximum_size(map, p_tempcrs, p_info);
			}
			p_tempcrs->col++;
		}
		p_tempcrs->row++;
	}
	ft_change_map(map, p_info);
	free(p_tempcrs);
	return ;
}
