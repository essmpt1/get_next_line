/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:41:21 by malourei          #+#    #+#             */
/*   Updated: 2025/11/01 23:21:51 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stack[BUFFER_SIZE + 1];
	char		*line;
	char		n;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	i = 0;
	line = NULL;
	n = 0;
	while (!n)
	{
		if (!*stack)
		{
			i = read(fd, stack, BUFFER_SIZE);
			if (i <= 0)
				return (ft_check_erro(stack, i, line));
			stack[i] = 0;
		}
		line = read_line(stack, line, &n);
		if (!line)
			return (NULL);
	}
	return (line);
}
