#include"../philo.h"

void print(t_philo *philo,char *str,long time)
{
	pthread_mutex_lock(philo->data->display);
	printf("%ld philo %d %s\n",time ,philo->id,str);	
	pthread_mutex_unlock(philo->data->display);
}
void	eating(t_philo *philo)
{
	
	print(philo,"is thinking",ft_time(philo->data->current_time));
	pthread_mutex_lock(&philo->data->forks[philo->left]);
	print(philo,"has take the left fork",ft_time(philo->data->current_time));
	pthread_mutex_lock(&philo->data->forks[philo->right]);
	print(philo,"has take the right fork",ft_time(philo->data->current_time));
	print(philo,"is eating",ft_time(philo->data->current_time));
	philo->last_time_eating = ft_time(philo->data->current_time);
	ft_usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->left]);
	pthread_mutex_unlock(&philo->data->forks[philo->right]);
}

void	sleeping(t_philo *philo)
{
		print(philo,"is sleeping",ft_time(philo->data->current_time));
		ft_usleep(philo->data->time_sleep * 1000);
}
