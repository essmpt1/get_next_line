/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:24:46 by malourei          #+#    #+#             */
/*   Updated: 2025/11/01 23:47:04 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_check_erro(char *stack, int i, char *line, int *stack_len);
char	*read_line(char *stack, int *stack_len, char *line, char *n);
char	*get_next_line(int fd);

#endif
