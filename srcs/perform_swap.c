/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:59:21 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/06 11:00:43 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_ps.h"

void	perform_sx(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len)
{
	t_stack_elm	second_elm;

	(void)stack_b;
	if (len < 2)
		return ;
	second_elm = stack_a[1];
	if (second_elm.enabled == false)
		return ;
	stack_a[1] = stack_a[0];
	stack_a[0] = second_elm;
}

void	perform_ss(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len)
{
	perform_sx(stack_a, NULL, len);
	perform_sx(stack_b, NULL, len);
}
