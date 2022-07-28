#include"philo.h"

int	full_philo(t_philo *philo, int i, int *j)
{
	pthread_mutex_lock(&philo->data->data_race[2]);
	if (philo[i].counter >= philo[0].data->h_much
		&& philo->data->h_much != -1)
			(*j)++;
	pthread_mutex_unlock(&philo->data->data_race[2]);
	if (i == philo[0].data->number)
    {
        pthread_mutex_lock(&philo->data->display);
		return (0);
    }
	return (1);
}
void	someone(t_philo *philo)
{
	int	i[2];
	int	time;

	while (1)
	{
		i[0] = 0;
		i[1] = 0;
		while (i[0] < philo[0].data->number)
		{
			if (!full_philo(philo, i[0], &i[1]))
				return ;
			pthread_mutex_lock(&philo->data->data_race[0]);
			time = ft_time(philo[i[0]].data->current_time
					+ philo[i[0]].last_time_eating);
			pthread_mutex_unlock(&philo->data->data_race[0]);
			if (philo[i[0]].data->time_die <= time)
			{
				if (!dead(&philo[i[0]]))
					return ;
			}
			i[0]++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data || argc < 5 || argc > 6 || !check_arg(argc, argv))
	{
		printf("invalid arguments\n");
		return (0);
	}
	if (!init(data, argc, argv))
		return (0);
	philo = (t_philo *) malloc(sizeof(t_philo) * data->number);
	if (!philo)
		return (0);
	philo_init(data, philo);
	threads(philo);
	someone(philo);
	destory(data);
}