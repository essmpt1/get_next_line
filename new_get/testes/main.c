/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:23:47 by malourei          #+#    #+#             */
/*   Updated: 2025/11/01 23:57:35 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	*str;

	if (argc != 2)
	{
		write(1, "Falha nos argumentos...\n", 24);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Falha do open\n", 14);
		return (1);
	}
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("Linha: %s\n", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
}
