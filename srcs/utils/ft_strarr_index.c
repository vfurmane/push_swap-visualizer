/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:56:12 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/05 12:16:35 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strarr_index(const char *str, const char *arr[], size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (strcmp(str, arr[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}
