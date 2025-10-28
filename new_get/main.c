/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:23:47 by malourei          #+#    #+#             */
/*   Updated: 2025/10/27 23:01:26 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	fd = open("teste", O_RDONLY);
	if (fd < 0)
	{
		write(1, "Falha do open\n", 14);
		return (1);
	}
	i = 0;
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("Linha %d: %s", i, str);
		i++;
		free(str);
	}
	close(fd);
}
