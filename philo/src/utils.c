/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:56:24 by codespace         #+#    #+#             */
/*   Updated: 2024/02/02 17:49:00 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if ((s1[i] && !s2[i]) || (s2[i] && !s1[i]))
		return (1);
	return (0);
}

long	get_time(long t_start)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		ft_error(GET_TIME);
		return (0);
	}
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000) - t_start);
}

void	ft_usleep(long time)
{
	time += get_time(0);
	while (get_time(0) <= time)
		usleep(200);
}

void	ft_print(char *str, t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->data->fmutex);
	dead = philo->data->end;
	pthread_mutex_unlock(&philo->data->fmutex);
	pthread_mutex_lock(&philo->data->wmutex);
	if (!dead || !ft_strcmp(str, "has died"))
		printf("%lu %i %s\n", get_time(philo->data->t_start), philo->id, str);
	pthread_mutex_unlock(&philo->data->wmutex);
}
