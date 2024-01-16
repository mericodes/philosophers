/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:33:41 by codespace         #+#    #+#             */
/*   Updated: 2024/01/16 16:35:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/philo.h"

int	get_int(pthread_mutex_t *mutex, int *val)
{
	int	ret;

	pthread_mutex_lock(mutex);
	ret = *val;
	pthread_mutex_unlock(mutex);
	return (ret);
}

void	set_int(pthread_mutex_t *mutex, int *dest, int val)
{
	pthread_mutex_lock(mutex);
	*dest = val;
	pthread_mutex_unlock(mutex);
}

long	get_long(pthread_mutex_t *mutex, long *val)
{
	long	ret;

	pthread_mutex_lock(mutex);
	ret = *val;
	pthread_mutex_unlock(mutex);
	return (ret);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long val)
{
	pthread_mutex_lock(mutex);
	*dest = val;
	pthread_mutex_unlock(mutex);
}

int	sim_end(t_data *data)
{
	return (get_int(&data->mdata, &data->end));
}