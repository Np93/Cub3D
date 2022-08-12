#include "cub3D.h"

void	ft_coolor_f(t_data *data, char *line)
{
	int	i;
	int	count;
	char 	**spliter;

	i = 0;
	count = -1;
	printf("%s\n", line);
	while (!(line[i] >= '0' && line[i] <= '9'))
		i++;
	while (line[i] != '\0') //&& line[i] != ' ')
	{
		if (line[i] == ' ' && line[i - 1] != (line[i - 1] >= '0' && line[i - 1] <= '9') && line[i - 1] != ',' && line[i + 1] != (line[i + 1] >= '0' && line[i + 1] <= '9'))
		{
			printf("ERROR :\n%s\n", "gros nul tu as mis un espace en trop dans le sol ou le plafond");
			exit(0);
		}
		if (!(line[i] >= '0' && line[i] <= '9') && line[i] != ',' && line[i] != ' ')
		{
			printf("ERROR :\n%s\n", "gros nooob c'est pas des chiffre ou , ou  ");
			exit(0);
		}
		if (line[i] != ' ')
			line[++count] = line[i];
		i++;
	}
	line[count + 1] = '\0';
	printf("%s\n", line);
	spliter = ft_split(line, ',');
	i = 0;
	count = 0;
	while (spliter[count])
		count++;
	if (count > 3)
	{
		printf("ERROR :\n%s\n", "trop d'argument dans le f ou c");
		exit(0);
	}
	data->ref_down = ft_atoi(spliter[0]);
	while (i < count)
	{
		data->down_int[i] = ft_atoi(spliter[i]);
		printf("%d\n", data->down_int[i]);
		if (data->down_int[i] < 0 || data->down_int[i] > 255)
		{
			printf("ERROR :\n%s\n", "valeur de c ou f trop basse ou trop haut");
			exit(0);
		}
		printf("%d\n", data->down_int[i]);
		i++;
	}
	while (i > 0)
		free(spliter[--i]);
	free(spliter);
}

void	ft_coolor_c(t_data *data, char *line)
{
	int	i;
	int	count;
	char 	**spliter;

	i = 0;
	count = -1;
	printf("%s\n", line);
	while (!(line[i] >= '0' && line[i] <= '9'))
		i++;
	while (line[i] != '\0')// && line[i] != ' ')
	{
		if (line[i] == ' ' && line[i - 1] != (line[i - 1] >= '0' && line[i - 1] <= '9') && line[i - 1] != ',' && line[i + 1] != (line[i + 1] >= '0' && line[i + 1] <= '9'))
		{
			printf("ERROR :\n%s\n", "gros nul tu as mis un espace en trop dans le sol ou le plafond");
			exit(0);
		}
		if (!(line[i] >= '0' && line[i] <= '9') && line[i] != ',' && line[i] != ' ')
		{
			printf("ERROR :\n%s\n", "gros nooob c'est pas des chiffre ou , ou  ");
			exit(0);
		}
		if (line[i] != ' ')
			line[++count] = line[i];
		i++;
	}
	line[count + 1] = '\0';
	printf("%s\n", line);
	spliter = ft_split(line, ',');
	i = 0;
	count = 0;
	while (spliter[count])
		count++;
	if (count > 3)
	{
		printf("ERROR :\n%s\n", "trop d'argument dans le f ou c");
		exit(0);
	}
//	printf("%s\n", spliter[0]);
	data->ref_up = ft_atoi(spliter[0]);
	while (i < count)
	{
		data->up_int[i] = ft_atoi(spliter[i]);
		printf("%d\n", data->up_int[i]);
		if (data->down_int[i] < 0 || data->down_int[i] > 255)
		{
			printf("ERROR :\n%s\n", "valeur de c ou f trop basse ou trop haut");
			exit(0);
		}
		i++;
	}
	while (i > 0)
		free(spliter[--i]);
	free(spliter);
}

char	*ft_load_img(char *line, char *path)
{
	int	i;
	int	count;

	i = 0;
	i = strlen(line);
	path = malloc(sizeof(char) * 993);
	count = -1;
	while (line[i] != '.')
		i--;
	if (line[i] != '.' || line[i + 1] != 'x' || line[i + 2] != 'p'
		|| line[i + 3] != 'm')
		exit(0);
	i = (i - 1);
	while (line[i] != '.')
		i--;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			break;
		path[++count] = line[i];
		i++;
	}
	path[count + 1] = '\0';
	if (path == NULL)
	{
		printf("%s\n", "probleme dans le path des image");
		exit(0);
	}
	return (path);
}

char	*get_img(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		data->path_n = ft_load_img(line, data->path_n);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		data->path_s = ft_load_img(line, data->path_s);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		data->path_w = ft_load_img(line, data->path_w);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		data->path_e = ft_load_img(line, data->path_e);
	else if (line[i] == 'C')
		ft_coolor_c(data, line);
	else if (line[i] == 'F')
		ft_coolor_f(data, line);
	i = strlen(line);
	while (i >= 0)
	{
		line[i] = '\0';
		i--;
	}
	return (line);
}

void	get_wall1(t_data *data)
{
	int	x;
	int	y;
	char	*temp;
	int	i;
//	int	z;

	y = -1;
	data->ref_down = -1;
	data->ref_up = -1;
	data->count = 0;
	temp = malloc(sizeof(char) * 993);
	while (data->map_game[++y] != NULL)
	{
		if (data->path_n != NULL && data->path_s != NULL && data->path_w != NULL
			&& data->path_e != NULL && data->up_int[0] == data->ref_up && data->down_int[0] == data->ref_down)
		{
			if ((++(data->count)) == 1)
				data->count_y = y;
				data->rep = 0;
		}
		x = 0;
		while (data->map_game[y][x] != '\0')
		{
		if (data->map_game[y][x] == 'N' || data->map_game[y][x] == 'S'
				|| data->map_game[y][x] == 'E' || data->map_game[y][x] == 'W' 
				|| data->map_game[y][x] == 'C' || data->map_game[y][x] == 'F')
			{
//				z = x;
				i = -1;
				while (data->map_game[y][x] != '\n' && data->map_game[y][x] != '\0')
				{
					temp[++i] = data->map_game[y][x];
					x++;
				}
				temp[i + 1] = '\0';
				temp = get_img(data, temp);
			}
			x++;
		}
	}
	free(temp);
}
