/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:02:51 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/03/29 18:00:08 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	check_spaces(const char **str)
{
	while (**str == ' ' || **str == '\n'
		|| **str == '\t' || **str == '\f' || **str == '\v' || **str == '\r')
	{
		(*str)++;
	}
}

static int	check_minplus(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign *= -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	check_spaces(&str);
	sign = check_minplus(&str);
	while (*str && *str >= 48 && *str <= 57)
	{
		if (res > 2147483647 / 10 || (res == 2147483647 / 10 && *str - 48 > 7))
		{
			if (sign == 1)
				return (-1);
			else if (sign == -1 && (*str - 48) > 8)
				return (0);
		}
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}
