/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:52:30 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/06/20 11:41:51 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_reg(int keycode, t_game *game)
{
	if ((keycode >= 0 && keycode <= 2) || keycode == 13)
		player_move(keycode, game, &(game->player.pos_x),
			&(game->player.pos_y));
	if (keycode == 53)
		game_close(game, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*tmp;

	game.mlx = mlx_init();
	if (argc != 2)
		game_close(&game, -1);
	tmp = read_map(argv[1], &game);
	game.map = ft_split(tmp, '\n');
	free(tmp);
	if (game.map == NULL)
		game_close(&game, -1);
	if (!check_map(game.map, &game))
		game_close(&game, -1);
	game.win = mlx_new_window(game.mlx, game.width * OFFSET,
			game.height * OFFSET, "So_long and ducks");
	render_floor(&game, game.mlx, game.win);
	render_map(&game, game.mlx);
	mlx_key_hook(game.win, key_reg, &game);
	mlx_hook(game.win, 17, 0L, game_destroy, &game);
	mlx_loop(game.mlx);
	return (0);
}
