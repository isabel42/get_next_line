#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_until_nl(char *s, int loopret);
char	*get_line(char *line, int ret, char *buf, int fd);
int		ft_totalloop(char *buf);
char	*get_next_line(int fd);

#endif
