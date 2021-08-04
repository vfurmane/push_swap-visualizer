/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:19:45 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/04 16:52:51 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_ps.h"

int	main(void)
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret)
	{
		ret = get_next_line(0, &line);
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
