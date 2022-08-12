#include "cub3D.h"

char	*load_def_map(t_data *data, char *line)
{
	int	i;
	int	rep;

	i = 0;
	rep = 0;
	while (line[i] != '\0')
	{
		printf("%c", line[i]);
		i++;
	}
	printf("\n");
	i = 0;
	if (data->rep == 0)
		if (line[i] == '\0' || line[i] == '\n' || line == NULL)
			rep = 1;
	if (data->rep == 1 && (line == NULL || line[0] == '\n' || line[0] == '\0'))
	{
		printf("ERROR :\n%s\n", "map pas correcte, ligne vide dans la map");
			exit(0);
	}
	if (rep == 0)
	{
		(data->count)++;
		data->map[data->count] = ft_strdup(line);
		data->rep = 1;
	}
	i = strlen(line);
	while (i >=  0)
	{
		line[i] = '\0';
		i--;
	}
	return (line);
}

void	set_count_y(t_data *data)
{
	data->count_y = 0;
	while (data->map[data->count_y] != NULL)
		(data->count_y)++;
	(data->count_y)--;
}

void	get_map_game(t_data *data)
{
	int	x;
//	int	count;
	char	*temp;
	int	i;

//	y = -1;
	data->count = -1;
	data->map = malloc(sizeof(char *) * 999);
	temp = malloc(sizeof(char) * 993);
//	printf("%s\n", "fuck");
	while (data->map_game[data->count_y] != NULL)
	{
		x = 0;
		i = -1;
		while (data->map_game[data->count_y][x] != '\0' )
		{
			temp[++i] = data->map_game[data->count_y][x];
			x++;
		}
		temp[i + 1] = '\0';
		temp = load_def_map(data, temp);
		(data->count_y)++;
	}
//	printf("%s\n", "doris");
	set_count_y(data);
	free(temp);
//	(data->count_y)--;
}
