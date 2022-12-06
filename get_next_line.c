#include "get_next_line.h"

char	*get_until_nl(char *s, int loopret)
{
	int		i;
	int		j;
	char	*temp;
	int		pos;

	i = 0;
	j = 0;
	pos = 0;
	temp = malloc((ft_strlen(s)) + 1 * sizeof(*temp));
	if (!temp)
		return (NULL);
	while (s[i] != '\0' && pos <= loopret)
	{
		if (pos == loopret)
		{
			temp[j] = s[i];
			j++;
		}
		if (s[i] == '\n')
			pos++;
		i++;
	}
	return (temp);
}

char	*get_line(char *line, int ret, char *buf, int fd)
{
	while (ft_totalloop(buf) == 0)
	{
		line = ft_strjoin(line, buf);
		ret = read (fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
	}
	buf[ret] = '\0';
	return (line);
}

int	ft_totalloop(char *buf)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			count++;
		i++;
	}
	if (ft_strlen(buf) < BUFFER_SIZE)
		count++;
	return (count);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*line;
	static char	buf[BUFFER_SIZE];
	static int	looprep = 0;

	line = malloc(BUFFER_SIZE * sizeof(*line) + 1);
	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (NULL);
	if (looprep < ft_totalloop(buf) - 1)
	{
		looprep++;
		return (get_until_nl (buf, looprep));
	}
	line = ft_strjoin(line, get_until_nl(buf, looprep + 1));
	ret = read (fd, buf, BUFFER_SIZE);
	if (ret <= 0)
		return (NULL);
	line = get_line(line, ret, buf, fd);
	line = ft_strjoin(line, get_until_nl(buf, 0));
	looprep = 0;
	return (line);
}
/*

int	main(void)
{
	int		fd;
	char	*line;
	int i = 0;

	fd = open("42", O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		return (1);
	}
	while(i < 12)
	{
			line = get_next_line(fd);
			printf("New Line: %s",  line);
			i++;
	}
	if (close(fd) == -1)
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
*/
