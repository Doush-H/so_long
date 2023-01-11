/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:46:04 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/06/19 17:52:09 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *path, t_game *game)
{
	int		fd;
	int		i;
	char	*map_str;
	char	*tmp;

	i = ft_strlen(path);
	if (i < 4 || path[i - 4] != '.' || path[i - 3] != 'b'
		|| path[i - 2] != 'e' || path[i - 1] != 'r')
		game_close(game, -1);
	map_str = ft_strdup("");
	tmp = ft_strdup("");
	if (tmp == NULL || map_str == NULL)
		game_close(game, -1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		game_close(game, -1);
	while (tmp != NULL)
	{
		map_str = ft_strjoin(map_str, tmp);
		tmp = get_next_line(fd);
	}
	check_nl_and_extra(game, map_str);
	return (map_str);
}

void	check_nl_and_extra(t_game *game, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			game_close(game, -1);
		i++;
	}
	tmp = ft_strtrim(str, "\n01CEP");
	if (tmp[0] != '\0')
	{
		free(tmp);
		game_close(game, -1);
	}
	free(tmp);
}
