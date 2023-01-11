/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:11:50 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/06/26 15:38:59 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

int	map_update(t_game *game, int c, int v)
{
	void	*img;
	int		*pl_x;
	int		*pl_y;

	pl_x = &(game->player.pos_x);
	pl_y = &(game->player.pos_y);
	if (c == 0)
	{
		img = mlx_xpm_file_to_image(game->mlx, "./sprites/floor.xpm", &c, &c);
		put(game, img, ((*pl_x) + v) * OFFSET, *pl_y * OFFSET);
		put(game, img, *pl_x * OFFSET, *pl_y * OFFSET);
		mlx_destroy_image(game->mlx, img);
		img = mlx_xpm_file_to_image(game->mlx, "./sprites/play.xpm", &c, &c);
		put(game, img, *pl_x * OFFSET, *pl_y * OFFSET);
		mlx_destroy_image(game->mlx, img);
		return (0);
	}
	img = mlx_xpm_file_to_image(game->mlx, "./sprites/floor.xpm", &c, &c);
	put(game, img, *pl_x * OFFSET, ((*pl_y) + v) * OFFSET);
	put(game, img, *pl_x * OFFSET, *pl_y * OFFSET);
	mlx_destroy_image(game->mlx, img);
	img = mlx_xpm_file_to_image(game->mlx, "./sprites/play.xpm", &c, &c);
	put(game, img, *pl_x * OFFSET, *pl_y * OFFSET);
	mlx_destroy_image(game->mlx, img);
	return (0);
}
