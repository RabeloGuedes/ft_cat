/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:23:40 by arabelo-          #+#    #+#             */
/*   Updated: 2023/05/15 17:16:02 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_putstr_fd("Usage ./a.out 'fileName'\n", 1);
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("open() failed!\n", 1);
		return (-1);
	}
	ft_cat(fd);
	fd = close(fd);
	if (fd == -1)
	{
		ft_putstr_fd("close() failed!\n", 1);
		return (-1);
	}
	return (0);
}
