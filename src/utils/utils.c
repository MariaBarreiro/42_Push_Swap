/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:37:04 by mda-enca          #+#    #+#             */
/*   Updated: 2025/09/02 16:23:13 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*ft_strdup_char(const char *arg, char delimiter)
{
	size_t	i;
	char	*dup;

	i = 0;
	while (arg[i] && arg[i] != delimiter)
	{
		if (arg[i] == '\0')
			return (0);
		i++;
	}
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (!dup)
	{
		free (dup);
		return (0);
	}
	i = 0;
	while (arg[i] && arg[i] != delimiter)
	{
		dup[i] = arg[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

bool	ft_atoi_modified(const char *str, int *result)
{
	size_t	i;
	long	n;
	int		signal;

	i = 0;
	n = 0;
	signal = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	if (!str[i])
		return (false);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i++] - '0');
		if (check_atoi(signal, n) == false)
			return (false);
	}
	if (str[i] != '\0')
		return (false);
	*result = n * signal;
	return (true);
}

bool	check_atoi(int signal, long n)
{
	if (signal == 1 && n > 2147483647)
		return (false);
	else if (signal == -1 && (n * -1) < -2147483648)
		return (false);
	return (true);
}
