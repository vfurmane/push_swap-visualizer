/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:00:36 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/05 14:34:00 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_ps.h"

void	perform_px(int *stack_a, int *stack_b, size_t len)
{
	memmove(stack_a + 1, stack_a, (len - 1) * sizeof (*stack_a));
	stack_a[0] = stack_b[0];
	memmove(stack_b, stack_b + 1, (len - 1) * sizeof (*stack_a));
	stack_b[len - 1] = 0;
}
