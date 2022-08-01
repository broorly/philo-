
#include"../philo.h"


long	ft_time(long start)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000 - start);
}

void	ft_usleep(long time)
{
	long	current_time;

	current_time = ft_time(0);
	usleep(time / 1000);
	while (ft_time(current_time) * 1000 < time)
		usleep(100);
}

int	v_init(t_data *data, int ac, char **argv)
{

	data->number = atoi(argv[1]);
	data->time_die = atoi(argv[2]);
	data->time_eat = atoi(argv[3]);
	data->time_sleep = atoi(argv[4]);
	data->is_dead = 0;
	data->forks = init_mutex(data->forks , data->number);
	if (!data->forks)
		return (0);
	if (ac == 6)
		data->h_much = atoi(argv[5]);
	return (1);
}
void	philo_init(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->number)
	{
		philo[i].id = i + 1;
		philo[i].left = i;
		philo[i].right = i + 1;
		philo[i].data = data;
		philo[i].last_time_eating = 0;
		philo[i].counter = 0;
		if (i == data->number - 1)
			philo[i].right = 0;
		i++;
	}
}
void	threads(t_philo *philo)
{
	int	i;

	i = 0;
	philo->data->current_time = ft_time(0);
	while (i < philo->data->number)
	{
		if (pthread_create(&philo[i].thread, NULL, &room, &philo[i]) != 0)
			return;
		i++;
		usleep(50);
	}
	// usleep(100);
	// i = 1;
	// while (i < philo[0].data->number)
	// {
	// 	if (pthread_create(&philo[i].thread, NULL, &room, &philo[i]) != 0)
	// 		return;
	// 	i += 2;
	// }
}
