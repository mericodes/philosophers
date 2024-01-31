/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:14:48 by codespace         #+#    #+#             */
/*   Updated: 2024/01/31 19:59:22 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	has_ended(t_data *data)
{
	pthread_mutex_unlock(&data->mdata);
}

void	routine_thread(t_philo *philo)
{
	pthread_mutex_lock(&philo->rfork);
	ft_print("has taken a fork (right)", philo);
	pthread_mutex_lock(&philo->lfork);
	ft_print("has taken a fork(left)", philo);
	pthread_mutex_lock(&philo->emutex);
	ft_print("is eating", philo);
	philo->meals++;
	pthread_mutex_unlock(&philo->emutex);
	ft_usleep(philo->data->t_eat);
	pthread_mutex_unlock(&philo->rfork);
	pthread_mutex_unlock(&philo->lfork);
	ft_print("is sleeping", philo);
	ft_usleep(philo->data->t_sleep);
	ft_print("is thinking", philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		end;

	philo = arg;
	end = 0;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->t_eat / 10);
	while (!end)
	{
		routine_thread(philo);
		pthread_mutex_lock(&philo->data->dmutex);
		end = philo->data->end;
		pthread_mutex_unlock(&philo->data->dmutex);
	}
	return ((void *)NULL);
}