/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:03:35 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/05/25 11:33:03 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 100

char	*get_next_line(int fd);
size_t	ft_slen(char *str, unsigned char c);
int		find_char(char *str, unsigned char c);
char	*stradd(char *storage, char *buf);
char	*get_buf(int fd, char *storage);
char	*rem_line(char *str);
char	*get_ret(char *storage);

#endif
