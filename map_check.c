/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:25:43 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/06/19 17:16:47 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_walls(char **map, t_game *game)
{
	int	x;
	int	y;
	int	ret;

	x = 0;
	y = 0;
	ret = 1;
	while (map[y] != NULL)
	{
		if (map[y][x] != '1' || map[y][x + game->width - 1] != '1')
			ret = 0;
		y++;
	}
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x++] != '1' && (y == 0 || y == game->height - 1))
				ret = 0;
		}
		y++;
	}
	return (ret);
}

static void	set_copm_default(t_game *game)
{
	game->exit = 0;
	game->player_num = 0;
	game->col_n = 0;
	game->player.col = 0;
	game->move_count = 0;
}

static void	count_comp(char **map, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				game->player_num++;
				game->player.pos_x = x;
				game->player.pos_y = y;
			}
			else if (map[y][x] == 'E')
				game->exit++;
			else if (map[y][x] == 'C')
				game->col_n++;
			x++;
		}
		y++;
	}
}

static int	check_comp(t_game *game)
{
	int	ret;

	ret = 1;
	if (game->player_num != 1)
		ret = 0;
	else if (game->col_n < 1)
		ret = 0;
	else if (game->exit < 1)
		ret = 0;
	return (ret);
}

int	check_map(char **map, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	set_copm_default(game);
	while (map[y][x] != '\0')
		x++;
	game->width = x;
	while (map[y] != NULL)
		y++;
	game->height = y;
	if (game->height > 42 || game->width > 90)
		return (0);
	count_comp(map, game);
	if (check_walls(map, game) && check_comp(game))
		ft_printf("Map format is correct !\n");
	else
	{
		ft_printf("Map format is incorrect !\n");
		return (0);
	}
	return (1);
}
