/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:15:28 by mrafik            #+#    #+#             */
/*   Updated: 2022/08/05 16:44:25 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	int					number;
	pthread_mutex_t		*forks;
	long				time_eat;
	long				time_sleep;
	long				time_die;
	long				current_time;
	int					h_much;
	int					is_dead;
	pthread_mutex_t		*display;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				left;
	int				right;
	long			last_time_eating;
	int				counter;
	pthread_t		thread;
	t_data			*data;
}	t_philo;

void			*room(void *arg);
long			ft_time(long start);
int				v_init(t_data *data, int ac, char **argv);
void			philo_init(t_data *data, t_philo *philo);
void			ft_usleep(long time);
void			sleeping(t_philo *philo);
void			eating(t_philo *philo);
void			threads(t_philo *philo);
pthread_mutex_t	*init_mutex(pthread_mutex_t *mutex, int size);
void			*room(void *arg);
int				killer(t_philo *philo, t_data *data);
void			print(t_philo *philo, char *str, long time);
int				ft_atoi(const char *str);

#endif