/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:46:58 by fcaetano          #+#    #+#             */
/*   Updated: 2023/03/17 14:56:53 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_free(t_philo *philos)
{
	free(philos->dat->forks);
	free(philos->dat->print);
	free(philos->dat->loopm);
	free(philos->dat->meals);
	free(philos);
}
