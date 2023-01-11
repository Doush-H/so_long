/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:44:53 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/06/26 15:43:39 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_left(t_game *game, int *pl_x, int *pl_y)
{
	if (game->map[*pl_y][*pl_x - 1] != '1')
	{
		if (!(game->map[*pl_y][*pl_x - 1] == 'E'
			&& game->player.col != game->col_n))
		{
			game->map[*pl_y][(*pl_x)--] = '0';
			if (game->map[*pl_y][*pl_x] == 'E')
				game_close(game, 0);
			else if (game->map[*pl_y][*pl_x] == 'C')
				game->player.col++;
			game->map[*pl_y][*pl_x] = 'P';
			game->move_count++;
			ft_printf("Move count: %d\n", game->move_count);
			map_update(game, 0, 1);
		}
	}
}

static void	move_right(t_game *game, int *pl_x, int *pl_y)
{
	if (game->map[*pl_y][*pl_x + 1] != '1')
	{
		if (!(game->map[*pl_y][*pl_x + 1] == 'E'
			&& game->player.col != game->col_n))
		{
			game->map[*pl_y][(*pl_x)++] = '0';
			if (game->map[*pl_y][*pl_x] == 'E')
				game_close(game, 0);
			else if (game->map[*pl_y][*pl_x] == 'C')
				game->player.col++;
			game->map[*pl_y][*pl_x] = 'P';
			game->move_count++;
			ft_printf("Move count: %d\n", game->move_count);
			map_update(game, 0, -1);
		}
	}
}

static void	move_up(t_game *game, int *pl_x, int *pl_y)
{
	if (game->map[*pl_y - 1][*pl_x] != '1')
	{
		if (!(game->map[*pl_y - 1][*pl_x] == 'E'
			&& game->player.col != game->col_n))
		{
			game->map[(*pl_y)--][(*pl_x)] = '0';
			if (game->map[*pl_y][*pl_x] == 'E')
				game_close(game, 0);
			else if (game->map[*pl_y][*pl_x] == 'C')
				game->player.col++;
			game->map[*pl_y][*pl_x] = 'P';
			game->move_count++;
			ft_printf("Move count: %d\n", game->move_count);
			map_update(game, 1, 1);
		}
	}
}

static void	move_down(t_game *game, int *pl_x, int *pl_y)
{
	if (game->map[*pl_y + 1][*pl_x] != '1')
	{
		if (!(game->map[*pl_y + 1][*pl_x] == 'E'
			&& game->player.col != game->col_n))
		{
			game->map[(*pl_y)++][(*pl_x)] = '0';
			if (game->map[*pl_y][*pl_x] == 'E')
				game_close(game, 0);
			else if (game->map[*pl_y][*pl_x] == 'C')
				game->player.col++;
			game->map[*pl_y][*pl_x] = 'P';
			game->move_count++;
			ft_printf("Move count: %d\n", game->move_count);
			map_update(game, 1, -1);
		}
	}
}

void	player_move(int keycode, t_game *game, int *pl_x, int *pl_y)
{
	if (keycode == 0)
		move_left(game, pl_x, pl_y);
	else if (keycode == 1)
		move_down(game, pl_x, pl_y);
	else if (keycode == 2)
		move_right(game, pl_x, pl_y);
	else if (keycode == 13)
		move_up(game, pl_x, pl_y);
}
