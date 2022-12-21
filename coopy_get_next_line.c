/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coopy_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:09:15 by itovar-n          #+#    #+#             */
/*   Updated: 2022/12/21 18:36:06 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_until_nl(char *s)
{
	int		i;
	int		j;
	char	*temp;
	int		pos;

	i = 0;
	j = 0;
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

char	*ft_get_line(char *line, int ret, char *buf, int fd)
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
	static char	*buf
	//static int	looprep = 0;
	char		*temp;

	line = malloc(BUFFER_SIZE * sizeof(*line) + 1);
	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (NULL);
	if (
	line = ft_strjoin(line, get_until_nl(buf, looprep + 1));
	ret = read (fd, buf, BUFFER_SIZE);
	if (ret <= 0)
		return (NULL);
	line = ft_get_line(line, ret, buf, fd);
	line = ft_strjoin(line, get_until_nl(buf, 0));
	looprep = 0;
	temp = line;
	if(line)
		free (line);
	return (temp);
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
