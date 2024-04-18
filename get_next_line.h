#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 30
#endif
# define MAX_FD 1024
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <string.h>

char	*get_next_line(int fd);
void read_and_append(char **line, int fd);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *line, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strsub(char const *line, unsigned int start, size_t len, int flag);

#endif