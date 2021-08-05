/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:19:45 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/05 13:40:37 by vfurmane         ###   ########.fr       */
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

int	perform_operation(int *stack_a, int *stack_b, size_t len,
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
	printf("Operation '%s' is at index %d\n", operation, fct_index);
	if (operation[strlen(operation) - 1] == 'a')
		(operations_fct[fct_index])(stack_a, len);
	else
		(operations_fct[fct_index])(stack_b, len);
	return (0);
}

int	main(int argc, char **argv)
{
	int			ret;
	char		*operation;
	int			*stack_a;
	int			*stack_b;
	size_t		count;

	if (argc <= 1)
		return (1);
	stack_a = parse_stack(argc - 1, &argv[1]);
	stack_b = malloc((argc - 1) * sizeof (stack_b));
	count = 0;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(0, &operation);
		if (ret == -1)
		{
			fprintf(stderr, COLOR_RED "Unable to read stdin\n" RESET_COLOR);
			free(stack_a);
			free(stack_b);
			return (1);
		}
		else if (ret == 0)
			break ;
		if (perform_operation(stack_a, stack_b, argc - 1, operation) == -1)
		{
			free(operation);
			free(stack_a);
			free(stack_b);
			return (1);
		}
		free(operation);
		count++;
	}
	printf("TOTAL: %zu\n", count);
	free(operation);
	free(stack_a);
	free(stack_b);
	return (0);
}
