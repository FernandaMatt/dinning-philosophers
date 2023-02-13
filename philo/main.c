/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:51:43 by fcaetano          #+#    #+#             */
/*   Updated: 2023/02/13 15:31:27 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	terminate_philos(t_philo *philo, int np)
{
	while (np-- > 0)
		pthread_join(philo[np].thid, NULL);
}

static unsigned long	in_time(t_philo philo)
{
	unsigned long	ret;

	pthread_mutex_lock(philo.dat->loopm);
	ret = philo.l_eat + philo.dat->time_to_die;
	pthread_mutex_unlock(philo.dat->loopm);
	return (ret);
}

static int	check_death(t_philo *philos)
{
	int				philo;
	unsigned long	time;

	philo = philos->dat->n_philos;
	while (philo--)
	{
		time = in_time(philos[philo]);
		if (time < time_us())
		{
			time = time_us();
			pthread_mutex_lock(philos->dat->print);
			kill(philos->dat);
			printf("%05ld %i is dead\n",
				(time - philos->dat->init_time) / 1000, philos[philo].id);
			pthread_mutex_unlock(philos->dat->print);
			return (1);
		}
	}
	return (0);
}

static void	check_simulation(t_philo *philos)
{
	while (42)
	{
		if (check_death(philos))
			return ;
		if (check_meals(philos->dat) == philos->dat->n_philos)
		{
			kill(philos->dat);
			return ;
		}
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	t_dat	dat;
	t_philo	*philos;

	if (argc > 4 && argc < 7)
	{
		if (!check_entry(argv))
		{
			printf("Error: parameters should be integers greater than 0.\n");
			return (1);
		}
		init_params(&dat, argv);
		philos = init_philos(&dat);
		check_simulation(philos);
		terminate_philos(philos, dat.n_philos);
		ft_free(philos);
	}
	else
	{
		printf("Wrong number os parameters.\n");
		return (1);
	}
	return (0);
}
