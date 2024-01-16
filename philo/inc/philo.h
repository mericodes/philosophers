/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:29:34 by codespace         #+#    #+#             */
/*   Updated: 2024/01/16 14:45:29 by codespace        ###   ########.fr       */
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
# define ARGS_ERROR 0
# define INIT_ERROR 1
# define THREAD_ERROR 2


/*	STRUCTS	*/
typedef struct s_data t_data;
/*	struct of forks	*/
typedef struct s_fork
{
	pthread_mutex_t	mfork;
	int				fid;
}	t_fork;

/*	struct of each philosopher	*/
typedef struct s_philo
{
	pthread_t	tid;
	int			id;
	long		meals;
	int			full;
	long		last_meal;
	t_fork		*fst_fork;
	t_fork		*scnd_fork;
	t_data		*data;
}	t_philo;

/*	struct of general data	*/
struct s_data
{
	long		total_philos;
	long		t_die;
	long		t_eat;
	long		t_sleep;
	long		max_meals;	// flag -1
	long		t_start;
	int			end;		//philo dies or philo full
	t_fork		*forks;		//array forks
	t_philo		*philos;	//arrau philos
};

/*	args.c	*/
int	get_args(int argc, char *argv[], t_data *data);

/*	init.c	*/
int	data_init(t_data *data);

/*	utils.c	*/
void	ft_error(int error);
void	ft_free(t_data *data);

#endif