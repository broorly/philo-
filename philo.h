#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
#include <sys/time.h>

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
void	*room(void *arg);
long	ft_time(long start);

#endif