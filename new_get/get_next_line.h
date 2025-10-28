/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:24:46 by malourei          #+#    #+#             */
/*   Updated: 2025/10/27 22:23:35 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

int		ft_strlen(char *s);
void	ft_strcpy(char *dest, char *src);
void	ft_strncat(char *dest, char *src, int size);
void	ft_join(char *dest, char *src, char *stack, int j);
char	*get_next_line(int fd);

#endif
