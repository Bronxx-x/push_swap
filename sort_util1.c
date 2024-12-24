/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:23:20 by yhamdan           #+#    #+#             */
/*   Updated: 2024/10/11 22:27:23 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

int	high(t_list *l, int high)
{
	t_list	*tmp;
	int		h;

	tmp = l;
	h = tmp->value;
	if (h > high)
		return (-1);
	while (tmp)
	{
		if (tmp->value > h)
			h = tmp->value;
		tmp = tmp->next;
	}
	if (h == high)
		return (0);
	return (1);
}

int	small(t_list *l, int small)
{
	t_list	*tmp;
	int		s;

	tmp = l;
	s = tmp->value;
	while (tmp)
	{
		if (tmp->value < s)
			s = tmp->value;
		tmp = tmp->next;
	}
	if (s == small)
		return (0);
	return (1);
}

int	sorted(t_list *l)
{
	t_list	*tmp;
	int		i;

	tmp = l;
	i = 0;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	ft_lstsize(t_list *l)
{
	int		i;
	t_list	*tmp;

	tmp = l;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	del(void *a)
{
	if (a)
		free(a);
	return ;
}
