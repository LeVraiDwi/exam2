#include <unistd.h>

int	ft_is_inbuff(char *buff, char c)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		if (buff[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_add_buff(char *buff, char c)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		if (buff[i] == 0)
		{
			buff[i] = c;
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	buff[1000];
	int		i;

	i = 0;
	while (i < 1000)
		buff[i++] = 0;
	if (argc == 3 && (*argv[1] && *argv[2]))
	{
		while (*argv[1])
		{
			if (*argv[1] && !ft_is_inbuff(buff, *argv[1]))
			{
				ft_add_buff(buff, *argv[1]);
				write(1, argv[1], 1);
			}
			argv[1]++;
		}
		while (*argv[2])
		{
			if (*argv[2] && !ft_is_inbuff(buff, *argv[2]))
			{
				ft_add_buff(buff, *argv[2]);
				write(1, argv[2], 1);
			}
			argv[2]++;
		}
	}
	write(1, "\n", 1);
	return (1);
}
