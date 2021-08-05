/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:02:33 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/05 14:32:20 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_ps.h"

void	perform_rrx(int *stack_a, int *stack_b, size_t len)
{
	int	tmp;

	(void)stack_b;
	tmp = stack_a[len - 1];
	memmove(stack_a + 1, stack_a, (len - 1) * sizeof (*stack_a));
	stack_a[0] = tmp;
}

void	perform_rrr(int *stack_a, int *stack_b, size_t len)
{
	perform_rrx(stack_a, NULL, len);
	perform_rrx(stack_b, NULL, len);
}
