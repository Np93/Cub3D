#include "cub3D.h"

char	*load_def_map(t_data *data, char *line)
{
	int	i;
	int	rep;

	i = 0;
	rep = 0;
	while (line[i] != '\0' && (line[i] == '0' || line[i] == '1' || line[i] == ' ' || line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'))
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			if (line[i + 1] != '0' && line[i + 1] != '1')
				rep = 1;
		}
		i++;
	}
	i = 0;
	if (line[i] == '\0' || line[i] == '\n')
		rep = 1;
	if (rep == 0)
	{
		(data->count)++;
		data->map[data->count] = ft_strdup(line);
	}
	i = strlen(line);
	while (i >=  0)
	{
		line[i] = '\0';
		i--;
	}
	return (line);
}

void	get_map_game(t_data *data)
{
	int	x;
	int	y;
	char	*temp;
	int	i;

	y = -1;
	data->count = -1;
	data->map = malloc(sizeof(char *) * 999);
	temp = malloc(sizeof(char *) *993);
	while (data->map_game[++y] != NULL)
	{
		x = 0;
		i = -1;
		while (data->map_game[y][x] != '\0' && (data->map_game[y][x] == '1'
				|| data->map_game[y][x] == '0' || data->map_game[y][x] == ' '
				|| data->map_game[y][x] == 'N' || data->map_game[y][x] == 'S'
				|| data->map_game[y][x] == 'E' || data->map_game[y][x] == 'W'))
		{
			temp[++i] = data->map_game[y][x];
			x++;
		}
		temp = load_def_map(data, temp);
	}
	free(temp);
}
/*
void	get_map_game(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if ((data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
				&& (data->map[y][x + 1] != '0' && data->map[y][x + 1] != '1'))
			{
				data->map[y][x] = '0';
			}
			else if (data->map[y][x] != 'N' && data->map[y][x] != 'S'
				&& data->map[y][x] != 'E' && data->map[y][x] != 'W'
				&& data->map[y][x] != '0' && data->map[y][x] != '1')
			{
				data->map[y][x] = '0';
			}
			x++;
		}
	}
}*/
