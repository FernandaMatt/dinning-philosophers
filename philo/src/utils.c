/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:57:04 by fcaetano          #+#    #+#             */
/*   Updated: 2023/03/17 14:56:20 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

unsigned long	time_us(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

void	ft_usleep(unsigned long wait, t_dat *dat)
{
	unsigned long	start;
	unsigned long	now;

	start = time_us();
	now = time_us();
	while (start + wait > now)
	{
		now = time_us();
		usleep(50);
		if (check_loop(dat))
			return ;
	}
	return ;
}

int	right_fork(t_philo philo)
{
	return ((philo.id - 2 + philo.dat->n_philos) % philo.dat->n_philos);
}

int	check_loop(t_dat *dat)
{
	int	ret;

	pthread_mutex_lock(dat->loopm);
	ret = dat->loop;
	pthread_mutex_unlock(dat->loopm);
	return (ret);
}

void	kill(t_dat *dat)
{
	pthread_mutex_lock(dat->loopm);
	dat->loop = 42;
	pthread_mutex_unlock(dat->loopm);
}
