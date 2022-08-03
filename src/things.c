#include"../philo.h"

void print(t_philo *philo,char *str)
{
	pthread_mutex_lock(philo->data->display);
	printf("philo %d %s\n",philo->id,str);
	pthread_mutex_unlock(philo->data->display);
}

void	eating(t_philo *philo)
{
	
	print(philo,"is thinking");
	pthread_mutex_lock(&philo->data->forks[philo->left]);
	print(philo,"has take the left fork");
	pthread_mutex_lock(&philo->data->forks[philo->right]);
	print(philo,"has take the right fork");
	print(philo,"is eating");
	philo->last_time_eating = ft_time(philo->data->current_time);
	ft_usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->left]);
	pthread_mutex_unlock(&philo->data->forks[philo->right]);
}

void	sleeping(t_philo *philo)
{
		printf("philo %d is sleeping\n", philo->id);
		ft_usleep(philo->data->time_sleep * 1000);
}
