/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:28:21 by yhamdan           #+#    #+#             */
/*   Updated: 2024/10/26 18:28:34 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	checker_strcmp_free(t_list **a_head, t_list *a, char **str, int i)
{
	ft_lstclear(a_head, checker_del);
	free(a);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
	write(2, "ERROR\n", 6);
	exit(1);
}

void	checker_del(void *a)
{
	if (a)
		free(a);
	return ;
}

void	checker_fill_list2(t_list **a_head, char **str)
{
	int		i;
	t_list	*a;

	i = 0;
	while (str[i])
	{
		a = (t_list *)malloc(sizeof(t_list));
		if (ft_strncmp("2147483647", str[i]) > 0)
		{
			ft_lstclear(a_head, checker_del);
			free(a);
			write(2, "ERROR\n", 6);
			exit(1);
		}
		a->content = NULL;
		a->next = NULL;
		a->value = ft_atoi(str[i++]);
		ft_lstadd_back(a_head, a);
		a = NULL;
	}
}

int	checker_ch_dub(t_list *a)
{
	t_list	*tmp;
	t_list	*head;

	head = a;
	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->value == a->value)
			{
				ft_lstclear(&head, checker_del);
				write(2, "ERROR\n", 6);
				exit(1);
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	checker_fill_list(t_list **a_head, char *argv)
{
	char	**str;
	int		i;
	t_list	*a;

	i = 0;
	str = ft_split(argv, ' ');
	if (!str)
		return (1);
	while (str[i])
	{
		a = (t_list *)malloc(sizeof(t_list));
		if (ft_strncmp("2147483647", str[i]) > 0)
			checker_strcmp_free(a_head, a, str, i);
		a->value = ft_atoi(str[i++]);
		a->content = NULL;
		a->next = NULL;
		ft_lstadd_back(a_head, a);
		a = NULL;
		free(str[i - 1]);
	}
	free(str);
	return (2);
}
