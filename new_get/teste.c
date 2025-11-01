# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

int	main(void)
{
	int		fd;
	char	buf[1000];
	int		size_byte;
	int		i;

	fd = open("teste", O_RDONLY);
	if (fd < 0)
	{
		write(1, "Falha do open\n", 14);
		return (1);
	}
	size_byte = read(fd, buf, sizeof(buf) - 1);
	if (size_byte < 0)
	{
		printf("BUF i < 0: %s\n", buf);
		close(fd);
		return (1);
	} else if (size_byte == 0)
	{
		printf("BUF i == 0: %s", buf);
		close(fd);
	}
	buf[size_byte] = '\0';
	i = 0;
	while (i < size_byte)
	{
		if (buf[i] > 31 && buf[i] < 127)
			write(1, &buf[i], 1);
		else if (buf[i] == '\n')
			write(1, "\n", 1);
		i++;
	}
	close(fd);
	return (0);
}
