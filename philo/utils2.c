/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:11:48 by fcaetano          #+#    #+#             */
/*   Updated: 2023/02/12 14:11:49 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_meals(t_dat *dat)
{
	int	ret;

	pthread_mutex_lock(dat->loopm);
	ret = dat->n_meals;
	pthread_mutex_unlock(dat->loopm);
	return (ret);
}

void	update_meals(t_dat *dat)
{
	pthread_mutex_lock(dat->loopm);
	dat->n_meals++;
	pthread_mutex_unlock(dat->loopm);
}

void	ft_printf(char *str, unsigned long time, t_philo *philo)
{
	if (check_loop(philo->dat))
		return ;
	pthread_mutex_lock(philo->dat->print);
	if (check_loop(philo->dat))
	{
		pthread_mutex_unlock(philo->dat->print);
		return ;
	}
	printf("%05ld %i %s",
		(time - philo->dat->init_time) / 1000, philo->id, str);
	pthread_mutex_unlock(philo->dat->print);
}

void	update(t_dat *dat, unsigned long *var, unsigned long time)
{
	pthread_mutex_lock(dat->loopm);
	*var = time;
	pthread_mutex_unlock(dat->loopm);
}

void	ph_printf(char act, t_philo *philo)
{
	unsigned long	now;

	now = time_us();
	if (act == 'e')
	{
		update(philo->dat, &(philo->l_eat), now);
		ft_printf("is eating\n", now, philo);
	}
	else if (act == 't')
		ft_printf("is thinking\n", now, philo);
	else if (act == 'f')
		ft_printf("has taken a fork\n", now, philo);
	else if (act == 's')
	{
		update(philo->dat, &(philo->l_sleep), now);
		ft_printf("is sleeping\n", now, philo);
	}
}
