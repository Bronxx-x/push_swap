/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 03:21:53 by yhamdan           #+#    #+#             */
/*   Updated: 2024/10/25 03:33:11 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_sub(t_list **a, t_list **b, char *line)
{
	if (line[2] == 'a')
		rra(a, 1);
	else if (line[2] == 'b')
		rrb(b, 1);
	else if (line[2] == 'r')
		rrr(a, b, 1);
	else
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
}

char	*ft_check(t_list **a, t_list **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(a, b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb(a, b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_sub(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(a, b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(a, b, 1);
	else
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	return (get_next_line(0));
}

t_list	*process(int arg, char *argv[])
{
	t_list	*a;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (arg == 1 || (arg == 2 && !argv[1][0]))
		exit(1);
	while (argv[++j])
	{
		i = -1;
		while (argv[j][++i])
			if (!(ft_isdigit(argv[j][i]) || ((argv[j][i] == ' ')
				|| ((argv[j][i] == '-') && ft_isdigit(argv[j][i + 1])))))
				return (write(2, "ERROR\n", 6), exit(1), NULL);
	}
	a = NULL;
	if (arg == 2)
		checker_fill_list(&a, argv[1]);
	else
		checker_fill_list2(&a, ++argv);
	checker_ch_dub(a);
	return (a);
}

void	ft_checker(t_list **a, t_list **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check(a, b, line);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (sorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;
	char	*line;

	a = process(argc, argv);
	tmp = process(argc, argv);
	b = NULL;
	sort(&a);
	line = get_next_line(0);
	if (!line && sorted(a))
		write(2, "KO\n", 3);
	else if (!line && !sorted(a))
		write(2, "OK\n", 3);
	else
		ft_checker(&tmp, &b, line);
	ft_lstclear(&b, checker_del);
	ft_lstclear(&a, checker_del);
	ft_lstclear(&tmp, checker_del);
	return (0);
}
