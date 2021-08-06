/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:00:36 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/06 09:58:31 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_ps.h"

void	perform_px(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len)
{
	memmove(stack_a + 1, stack_a, (len - 1) * sizeof (*stack_a));
	stack_a[0] = stack_b[0];
	memmove(stack_b, stack_b + 1, (len - 1) * sizeof (*stack_a));
	bzero(&stack_b[len - 1], sizeof (*stack_b));
}
