#include <unistd.h>

int	ft_strinstr(char c, char *str, int l)
{
	int i;

	i = 0;
	while (str[i] && i < l)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 0;
	if (argc == 3 && (*argv[1] && *argv[2]))
	{
		str = argv[1];
		while (str[i])
		{
			if (str[i] && !ft_strinstr(str[i], str, i) && ft_strinstr(str[i], argv[2], ft_strlen(argv[2])))
				write(1, str + i, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (1);
}
