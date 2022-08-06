/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:15:19 by mrafik            #+#    #+#             */
/*   Updated: 2022/08/06 17:21:36 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int check_arg(char **str)
{
	int i;
	int x;
	
	i = 1;
	while(str[i])
	{
		x = 0;
		while(str[i][x])
		{
			if(!ft_isdigit(str[i][x]))
				return(0);
			x++;
		}
		i++;
	}
	return(1);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data || argc < 5 || argc > 6 || !check_arg(argv))
	{
		printf("invalid argument \n");
		return (0);
	}
	if (!v_init(data, argc, argv))
		return (0);
	philo = (t_philo *) malloc(sizeof(t_philo) * data->number);
	if (!philo)
		return (0);
	philo_init(data, philo);
	threads(philo);
	while (1)
	{
		if (killer(philo, data))
			return (0);
	}
	return (0);
}
