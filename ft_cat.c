/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:05:20 by arabelo-          #+#    #+#             */
/*   Updated: 2023/05/15 17:13:28 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_cat(int fd)
{
	char	*buffer;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return ;
	buffer = "";
	buffer = get_whole_file(fd, buffer, temp);
	if (temp)
		free(temp);
	ft_putstr_fd(buffer, 1);
	if (buffer)
		free(buffer);
}

char	*get_whole_file(int fd, char *buffer, char *temp)
{
	int		r_status;

	r_status = 1;
	while (r_status)
	{
		r_status = read(fd, temp, BUFFER_SIZE);
		if (r_status == -1)
		{
			ft_putstr_fd("something went wrong\n", 1);
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[r_status] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	return (buffer);
}
