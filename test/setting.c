#include "cub3D.h"

int	count_lign(char *dos)
{
	int		fd;
	int		lign;
	int		comptread;
	char	a;

	fd = open(dos, O_RDONLY);
	if (!fd)
		return (-1);
	lign = 0;
	comptread = 1;
	while (comptread > 0)
	{
		comptread = read(fd, &a, 1);
		if (comptread == 0)
			break ;
		if (comptread < 0)
			return (-1);
		if (a == '\n')
			lign++;
	}
	close(fd);
	return (lign);
}

void	check_ber(t_data *data, char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
		i++;
	if (av[i - 1] != 'b' || av[i - 2] != 'u'
		|| av[i - 3] != 'c' || av[i - 4] != '.')
		error_handle(1);
	data->ref_down = -1;
	data->ref_up = -1;
	data->count = 0;
}

int	count_col(t_data *data)
{
	int	y;
	int	i;
	int	width;

	y = -1;
	width = 0;
	while (data->map_game[++y] != NULL)
	{
		i = strlen(data->map_game[y]);
		if (i > width)
			width = i;
	}
	return (width);
}
