#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

int	ft_is_line(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

char	*ft_error(char *str, char *line)
{
	if (str)
		free(str);
	if (line)
		free(line);
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*s;
	int		l;

	l = 0;
	if ( !str || !*str)
	{
		s = (char *)malloc(sizeof(char) * 1);
		if (!s)
			return (0);
		s[0] = 0;
		return (s);
	}
	s = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!s)
		return (0);
	while (*str && *str != EOF)
	{
		s[l++] = *str++;
	}
	s[l] = 0;
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int l;
	char *str;

	if (!s1 || !*s1)
	{
		str = ft_strdup(s2);
		if (!str)
			return (0);
		return(str);
	}
	if (!s2 || !*s2)
	{
		str = ft_strdup(s1);
		if (!str)
			return (0);
		return(str);
	}
	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * l);
	if (!str)
		return (0);
	l = 0;
	while (*s1)
	{
		str[l++] = *s1++;
	}
	while (*s2)
	{
		str[l++] = *s2++;
	}
	str[l] = 0;
	return (str);
}

int	ft_char_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char *s, int start, int end)
{
	char	*str;
	int		l;

	l = end - start + 1;
	str = (char *)malloc(sizeof(char) * l);
	if (!str)
		return (0);
	l = 0;
	while (s[start] && start < end)
	{
		str[l++] = s[start++];
	}
	str[l] = 0;
	return (str);
}

char	*ft_send_line(char **str)
{
	char 	*tmp;
	int	l;
	char 	*line;

	l = ft_char_in_str(*str, '\n');
	line = ft_substr(*str, 0, l + 1);
	if (!line)
		return (ft_error(*str, 0));
	tmp = *str;
	*str = ft_substr(*str, l + 1, ft_strlen(*str));
	if (!*str)
		return (ft_error(tmp, line));
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buff[BUFFER_SIZE + 1];
	int		l;
	char		*tmp;
	char		*line;

	l = 1;
	tmp = 0;
	if (str && *str && ft_is_line(str))
		return (ft_send_line(&str));
	else
	{
		while (!ft_is_line(str) && l)
		{
			l = read(fd, buff, BUFFER_SIZE);
			if (l == -1)
			{
				return (ft_error(str, 0));
			}
			else if (l)
			{
				if (l)
					buff[l] = 0;
				tmp = str;
				str = ft_strjoin(str, buff);
				if (!str)
					return (ft_error(tmp, 0));
				if (tmp)
					free(tmp);
			}
		}
		if (str & ft_is_line(str))
			return (ft_send_line(&str));
		else
		{
			if (str && *str)
			{
				if (!(line = ft_strdup(str)))
					return (ft_error(str, 0));
				free(str);
				str = 0;
				return (line);
			}
			else if (str && !*str)
			{
				if (str)
					free(str);
				str = 0;
				return (ft_strdup(""));
			}
			else
				return (0);
		}
	}
}
