/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:40:31 by fcaetano          #+#    #+#             */
/*   Updated: 2022/09/19 19:52:08 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static unsigned int	ft_strlen(const char *str)
{
	unsigned int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	check_max(char *str, char *max, char *min)
{
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		max = min;
	}
	if (ft_strlen(str) > 10)
		return (1);
	else if (ft_strlen(str) < 10)
		return (0);
	while (*str && *max)
	{
		if (*str < *max)
			return (0);
		else if (*str == *max)
		{
			str++;
			max++;
		}
		else
			return (1);
	}
	return (0);
}

int	check_entry(char **entry)
{
	int	c;

	entry++;
	while (*entry)
	{
		c = 0;
		if ((entry[0][c] == '-' || entry[0][c] == '+') && entry[0][1] != 0)
			c++;
		while (entry[0][c])
		{
			if (ft_isdigit(entry[0][c]))
					c++;
			else
				return (0);
		}
		if ((ft_strlen(*entry) >= 10
				&& check_max(*entry, "2147483647", "2147483648"))
			|| ft_atoi(*entry) <= 0)
			return (0);
		entry++;
	}
	return (1);
}
