/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:19:15 by codespace         #+#    #+#             */
/*   Updated: 2024/01/16 16:55:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	forks_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		data->forks[i].fid = i;
		if (pthread_mutex_init(&data->forks[i].mfork, NULL) != 0)
			return (0);
		// printf("FORK ID::::::::; %i\n", data->forks[i].fork_id);
		i++;
	}
	return (1);
}

void	forks_assign(t_philo *philo, t_fork *forks, int i)
{
	int	ph_num;

	ph_num = philo->data->total_philos;
	philo->fst_fork = &forks[(i + 1) % ph_num];
	philo->scnd_fork = &forks[i];
	if (philo->id % 2 == 0)
	{
		philo->fst_fork = &forks[i];
		philo->scnd_fork = &forks[(i + 1) % ph_num];
	}
	//printf("PHILO ID:::: %i   FIRST FORK:::: %i   SECOND FORK:::: %i\n", 
	//	philo->id, philo->fst_fork->fid, philo->scnd_fork->fid);
}

void	philos_init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->total_philos)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = 0;
		philo->meals = 0;
		philo->data = data;
		forks_assign(philo, data->forks, i);
	}
}

int	data_init(t_data *data)
{
	data->end = 0;
	data->start = 0;
	pthread_mutex_init(&data->mdata, NULL);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->total_philos);
	if (!data->philos)
		return (0);
	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->total_philos);
	if (!data->forks)
		return (0);
	if (!forks_init(data))
		return (0);
	philos_init(data);
	return (1);
}