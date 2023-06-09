/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:39:31 by fcaetano          #+#    #+#             */
/*   Updated: 2023/02/13 15:42:04 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_wspaces(char *str)
{
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	return (str);
}

static int	ft_catnbr(char *str)
{
	unsigned int	c;
	unsigned int	mult;
	long int		result;

	c = 0;
	while (str[c] >= '0' && str[c] <= '9' && str[c] != 0)
			c++;
	mult = 1;
	result = 0;
	while (c > 0)
	{
		result += (str[c - 1] - '0') * mult;
		mult *= 10;
		c--;
	}
	return (result);
}

long int	ft_atoi(char *str)
{
	long int	result;

	result = 1;
	str = ft_wspaces(str);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			result = -1;
		str++;
	}
	result *= ft_catnbr(str);
	return (result);
}
