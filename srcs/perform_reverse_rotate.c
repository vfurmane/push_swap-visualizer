/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:02:33 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/06 10:48:50 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_ps.h"

void	perform_rrx(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len)
{
	t_stack_elm	*last_elm_ptr;
	t_stack_elm	last_elm;

	(void)stack_b;
	last_elm_ptr = last_stack_elm(stack_a, len);
	if (last_elm_ptr == NULL)
		return ;
	last_elm = *last_elm_ptr;
	memmove(stack_a + 1, stack_a, (stack_len(stack_a, len) - 1) * sizeof (*stack_a));
	stack_a[0] = last_elm;
}

void	perform_rrr(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len)
{
	perform_rrx(stack_a, NULL, len);
	perform_rrx(stack_b, NULL, len);
}
