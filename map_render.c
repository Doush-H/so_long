/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:30:55 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/05/19 16:22:57 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_and_destroy(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * OFFSET, y * OFFSET);
	mlx_destroy_image(game->mlx, img);
}

void	render_map(t_game *game, void *mlx)
{
	int		y;
	int		x;
	void	*img;
	int		w;

	y = -1;
	while (game->map[++y] != NULL)
	{
		x = -1;
		while (game->map[y][++x] != '\0')
		{
			if (game->map[y][x] == '1')
				img = mlx_xpm_file_to_image(mlx, "./sprites/wall.xpm", &w, &w);
			else if (game->map[y][x] == 'E')
				img = mlx_xpm_file_to_image(mlx, "./sprites/exit.xpm", &w, &w);
			else if (game->map[y][x] == 'P')
				img = mlx_xpm_file_to_image(mlx, "./sprites/play.xpm", &w, &w);
			else if (game->map[y][x] == 'C')
				img = mlx_xpm_file_to_image(mlx, "./sprites/coll.xpm", &w, &w);
			if (game->map[y][x] != '0')
				put_and_destroy(game, img, x, y);
		}
	}
}

void	render_floor(t_game *game, void *mlx, void *win)
{
	int		y;
	int		x;
	void	*img;
	int		w;
	int		h;

	y = 0;
	x = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			img = mlx_xpm_file_to_image(mlx, "./sprites/floor.xpm", &w, &h);
			mlx_put_image_to_window(mlx, win, img, x * OFFSET, y * OFFSET);
			mlx_destroy_image(mlx, img);
			x++;
		}
		y++;
	}
}
