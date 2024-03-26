/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:29:34 by codespace         #+#    #+#             */
/*   Updated: 2024/03/26 17:06:43 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*	LIBRARIES	*/
/*	printf	*/
# include <stdio.h>
/*	malloc, free	*/
# include <stdlib.h>
/*	write, usleep	*/
# include <unistd.h>
/*	mutex: init, destroy, lock, unlock; threads: create, join, detach	*/
# include <pthread.h>
/*	gettimeofday	*/
# include <sys/time.h>

/*	DEFINES	*/
# define ARGS_ERROR		0
# define INIT_ERROR		1
# define THREAD_ERROR	2
# define GET_TIME		3

/*	STRUCTS	*/
typedef struct s_data	t_data;

/*	struct of each philosopher	*/
typedef struct s_philo
{
	int					id;
	long				meals;
	long				last_meal;
	pthread_mutex_t		emutex;
	pthread_mutex_t		*lfork;
	pthread_mutex_t		rfork;
	t_data				*data;
}	t_philo;

/*	struct of general data	*/
struct s_data
{
	long				total_philos;
	long				t_die;
	long				t_eat;
	long				t_sleep;
	long				max_meals;
	long				philo_full;
	long				t_start;
	int					end;
	pthread_mutex_t		mdata;
	pthread_mutex_t		wmutex;
	pthread_mutex_t		fmutex;
	pthread_t			*threads;
	t_philo				*philos;
};

/*	args.c	*/
int		str_is_digit(char *str);
long	ft_atol(const char *str);
int		get_args(int argc, char *argv[], t_data *data);

/*	errors.c	*/
void	ft_error(int error);
void	ft_free(t_data *data);
void	ft_exit(t_data *data);
/*	init.c	*/
int		threads_init(t_data *data);
void	philos_init(t_data *data);
int		data_init(t_data *data);

/*	threads.c	*/
void	has_ended(t_data *data);
void	routine_thread(t_philo *philo, long t_start);
void	routine_one(t_philo *philo);
void	*routine(void *arg);

/*	utils.c	*/
int		ft_strcmp(char *s1, char *s2);
long	get_time(long t_start);
void	ft_usleep(long time);
void	ft_print(char *str, t_philo *philo);

#endif