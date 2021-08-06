/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:01:32 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/06 10:50:54 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_ps.h"

void	perform_rx(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len)
{
	t_stack_elm	last_elm;

	(void)stack_b;
	last_elm = stack_a[0];
	if (last_elm.enabled == false)
		return ;
	memmove(stack_a, stack_a + 1, (stack_len(stack_a, len) - 1) * sizeof (*stack_a));
	*last_stack_elm(stack_a, len) = last_elm;
}

void	perform_rr(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len)
{
	perform_rx(stack_a, NULL, len);
	perform_rx(stack_b, NULL, len);
}
