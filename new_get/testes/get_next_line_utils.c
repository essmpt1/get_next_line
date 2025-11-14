/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:25:27 by malourei          #+#    #+#             */
/*   Updated: 2025/11/02 00:02:31 by malourei         ###   ########.fr       */
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
	int	src_len;

	i = 0;
	src_len = 0;
	if (src)
	{
		// copia tudo, até ao terminador nulo incluído
		while (src[src_len])
			src_len++;
	}

	// copia src
	while (i < src_len)
	{
		dest[i] = src[i];
		i++;
	}

	free(src);
	n = i;
	i = 0;

	// copia j bytes da stack (pode conter \0)
	while (i < j)
	{
		dest[n + i] = stack[i];
		i++;
	}
	dest[n + i] = '\0';
}

static void	free_stack(char *stack, int *stack_len, int consumed)
{
	int	i = 0;

	if (consumed >= *stack_len)
	{
		*stack_len = 0;
		return ;
	}
	while (consumed + i < *stack_len)
	{
		stack[i] = stack[consumed + i];
		i++;
	}
	*stack_len = i;
}

char	*read_line(char *stack, int *stack_len, char *line, char *n)
{
	int		j;
	char	*str;
	int		line_len;

	j = 0;
	// percorre o buffer até encontrar '\n' ou chegar ao limite de bytes válidos
	while (j < *stack_len && stack[j] != '\n')
		j++;

	// se encontrou newline, marcar fim da linha e consumir +1 byte
	if (j < *stack_len && stack[j] == '\n')
	{
		*n = '1';
		j++;
	}

	line_len = ft_strlen(line);
	str = malloc(sizeof(char) * (line_len + j + 1));
	if (!str)
		return (NULL);

	ft_join(str, line, stack, j);
	free_stack(stack, stack_len, j);

	return (str);
}

char	*ft_check_erro(char *stack, int i, char *line, int *stack_len)
{
	(void)stack;
	if (i < 0)
	{
		*stack_len = 0;
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}
