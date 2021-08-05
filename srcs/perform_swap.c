/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:59:21 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/05 14:37:45 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_ps.h"

void	perform_sx(int *stack_a, int *stack_b, size_t len)
{
	int	tmp;

	(void)len;
	(void)stack_b;
	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
}

void	perform_ss(int *stack_a, int *stack_b, size_t len)
{
	perform_sx(stack_a, NULL, len);
	perform_sx(stack_b, NULL, len);
}
