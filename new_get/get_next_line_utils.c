/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:25:27 by malourei          #+#    #+#             */
/*   Updated: 2025/10/29 01:20:14 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static void	ft_join(char *dest, char *src, char *stack, int j)
{
	int	i;
	int	n;

	i = 0;
	if (!src)
		*dest = 0;
	else
	{
		while (src[i] != 0)
		{
			dest[i] = src[i];
			i++;
		}
	}
	if (src)
		free(src);
	n = i;
	i = 0;
	while (j > 0)
	{
		dest[n + i] = stack[i];
		i++;
		j--;
	}
	dest[n + i] = '\0';
}

static void	free_stack(char *stack)
{
	int	i;
	int	j;
	int	n;

	if (!*stack)
		return ;
	i = 0;
	n = 0;
	j = ft_strlen(stack);
	while (stack[n] && stack[n] != '\n')
		n++;
	if (n == j)
	{
		*stack = 0;
		return ;
	}
	stack[n] = 0;
	n++;
	while (n < j)
	{
		stack[i] = stack[n];
		n++;
		i++;
	}
	stack[i] = 0;
}

char	*read_line(char *stack, char *line, char *n)
{
	int		j;
	char	*str;

	j = 0;
	while (stack[j] && stack[j] != '\n')
		j++;
	if (stack[j++] == '\n')
		*n = '1';
	str = malloc(sizeof(char) * (j + ft_strlen(line) + 1));
	if (!str)
		return (NULL);
	ft_join(str, line, stack, j);
	free_stack(stack);
	return (str);
}

char	*ft_check_erro(char *stack, int i, char *line)
{
	if (*stack && i < 0)
	{
		if (*stack)
			*stack = 0;
		return (line);
	}
	return (line);
}
