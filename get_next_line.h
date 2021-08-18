#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
char	*ft_strdup(char *str);
int	ft_strlen(char *str);
int	ft_is_line(char *str);
int	ft_error(char *str, char *line);
char	*ft_strjoin(char *s1, char *s2);
int		ft_char_in_str(char *str, char c);
char	*ft_substr(char *s, int start, int end);
int		get_next_line(char **line);
#endif
