/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:37:22 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/06/19 16:56:12 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Code 0 = game ended succesfuly
//Code 1 = game closed by the player
//Code -1 = game ended with an error
void	game_close(t_game *game, int code)
{
	if (code == 0)
	{
		ft_printf("\033[0;32m");
		ft_printf("Well done, you beat the game in %d moves. "
			"May the ducks be with you.\n", game->move_count);
		exit(1);
	}
	else if (code == 1)
	{
		mlx_destroy_window(game->mlx, game->win);
		ft_printf("\033[0;31m");
		ft_printf("Game was closed.\n");
		exit(1);
	}
	else if (code == -1)
	{
		ft_printf("\033[0;31m");
		ft_printf("Error:\n      Something went wrong. "
			"Please check if your maps' format "
			"and the number of parameters are correct.\n");
		exit(-1);
	}
}

int	game_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_printf("\033[0;31m");
	ft_printf("Game was closed.\n");
	exit(1);
	return (1);
}
