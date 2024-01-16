/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:02:31 by codespace         #+#    #+#             */
/*   Updated: 2024/01/16 14:16:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

/*	Poner el limite max (si eso)	*/
long	ft_atol(const char *str)
{
	int		i;
	int		minus;
	long	res;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * minus);
}

int	get_args(int argc, char *argv[], t_data *data)
{
	if (argc != 5 && argc != 6)
		return (0);
	data->total_philos = ft_atol(argv[1]);
	if (!str_is_digit(argv[1]) || data->total_philos <= 0)
		return (0);
	data->t_die = ft_atol(argv[2]);
	if (!str_is_digit(argv[2]) || data->t_die <= 0)
		return (0);
	data->t_eat = ft_atol(argv[3]);
	if (!str_is_digit(argv[3]) || data->t_eat <= 0)
		return (0);
	data->t_sleep = ft_atol(argv[4]);
	if (!str_is_digit(argv[4]) || data->t_sleep <= 0)
		return (0);
	if (argv[5])
	{
		data->max_meals = ft_atol(argv[5]);
		if (!str_is_digit(argv[5]) || data->max_meals < 0)
			return (0);
	}
	return (1);
}
