/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:01:32 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/05 14:35:18 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_ps.h"

void	perform_rx(int *stack_a, int *stack_b, size_t len)
{
	int	tmp;

	(void)stack_b;
	tmp = stack_a[0];
	memmove(stack_a, stack_a + 1, (len - 1) * sizeof (*stack_a));
	stack_a[len - 1] = tmp;
}

void	perform_rr(int *stack_a, int *stack_b, size_t len)
{
	perform_rx(stack_a, NULL, len);
	perform_rx(stack_b, NULL, len);
}
