/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:19:45 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/05 12:15:45 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_ps.h"

int	*parse_stack(int argc, char **argv)
{
	int	i;
	int	*stack;

	stack = calloc(argc, sizeof (*stack));
	i = 0;
	while (i < argc)
	{
		stack[i] = atoi(argv[i]);
		i++;
	}
	return (stack);
}

int	perform_operation(int *stack, const char *operation)
{
	int8_t				fct_index;
	const char			*operations_list[11] = {"sa", "sb", "ss", "pa", "pb",
												"ra", "rb", "rr", "rra", "rrb",
												"rrr"};
	const t_operation	operations_fct[11] = {perform_sa, perform_sb,
										perform_ss, perform_pa, perform_pb,
										perform_ra, perform_rb, perform_rr,
										perform_rra, perform_rrb, perform_rrr};

	fct_index = ft_strarr_index(operation, operations_list, 11);
	if (fct_index == -1)
	{
		fprintf(stderr, COLOR_RED "Unknown operation '%s'\n" RESET_COLOR,
			operation);
		return (-1);
	}
	printf("Operation '%s' is at index %d\n", operation, fct_index);
	(void)stack; /* ===== DELETE ===== */
	(void)operations_fct; /* ===== DELETE ===== */
	return (0);
}

int	main(int argc, char **argv)
{
	int			ret;
	char		*operation;
	int			*stack;

	if (argc <= 1)
		return (1);
	stack = parse_stack(argc - 1, &argv[1]);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(0, &operation);
		if (ret == -1)
			break ;
		if (perform_operation(stack, operation) == -1)
		{
			free(operation);
			free(stack);
			return (1);
		}
		free(operation);
	}
	free(stack);
	return (0);
}
