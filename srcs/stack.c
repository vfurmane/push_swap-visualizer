/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:18:42 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/06 10:42:08 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_ps.h"

size_t	stack_len(t_stack_elm *stack, size_t len)
{
	size_t	i;

	if (stack[0].enabled == false)
		return (0);
	i = 0;
	while (i < len)
	{
		if (stack[i].enabled == false)
			return (i);
		i++;
	}
	return (i);
}

t_stack_elm	*last_stack_elm(t_stack_elm *stack, size_t len)
{
	size_t	i;

	if (stack[0].enabled == false)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		if (stack[i + 1].enabled == false)
			return (stack + i);
		i++;
	}
	return (stack + i);
}

t_stack_elm	*parse_stack(int argc, char **argv)
{
	int			i;
	t_stack_elm	*stack;

	stack = calloc(argc, sizeof (*stack));
	i = 0;
	while (i < argc)
	{
		stack[i].value = atoi(argv[i]);
		stack[i].enabled = true;
		i++;
	}
	return (stack);
}

int	perform_operation(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len,
	const char *operation)
{
	int8_t				fct_index;
	const char			*operations_list[11] = {"sa", "sb", "ss", "pa", "pb",
												"ra", "rb", "rr", "rra", "rrb",
												"rrr"};
	const t_operation	operations_fct[11] = {perform_sx, perform_sx,
										perform_ss, perform_px, perform_px,
										perform_rx, perform_rx, perform_rr,
										perform_rrx, perform_rrx, perform_rrr};

	fct_index = ft_strarr_index(operation, operations_list, 11);
	if (fct_index == -1)
	{
		fprintf(stderr, COLOR_RED "Unknown operation '%s'\n" RESET_COLOR,
			operation);
		return (-1);
	}
	if (operation[strlen(operation) - 1] == 'a')
		(operations_fct[fct_index])(stack_a, stack_b, len);
	else
		(operations_fct[fct_index])(stack_b, stack_a, len);
	return (0);
}
