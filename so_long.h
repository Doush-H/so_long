/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:14:09 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/06/26 15:39:42 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "MLX/mlx.h"
# include <fcntl.h>
# define OFFSET 32

typedef struct s_player {
	int	pos_x;
	int	pos_y;
	int	col;
}				t_player;

typedef struct s_game {
	void			*mlx;
	void			*win;
	unsigned int	move_count;
	int				col_n;
	int				exit;
	int				player_num;
	int				height;
	int				width;
	char			**map;
	t_player		player;
}				t_game;

char	*read_map(char *path, t_game *game);
int		check_map(char **map, t_game *game);
void	render_floor(t_game *game, void *mlx, void *win);
void	render_map(t_game *game, void *mlx);
int		key_reg(int keycode, t_game *game);
void	player_move(int keycode, t_game *game, int *pl_x, int *pl_y);
void	game_close(t_game *game, int code);
int		game_destroy(t_game *game);
int		map_update(t_game *game, int c, int v);
void	check_nl_and_extra(t_game *game, char *str);

#endif