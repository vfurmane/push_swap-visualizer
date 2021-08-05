/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:19:45 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/05 14:32:34 by vfurmane         ###   ########.fr       */
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
	if (operation[strlen(operation) - 1] == 'a')
		(operations_fct[fct_index])(stack_a, stack_b, len);
	else
		(operations_fct[fct_index])(stack_b, stack_a, len);
	return (0);
}

size_t	longest_number_len(int *stack_a, int *stack_b, size_t len)
{
	size_t	i;
	size_t	number_len;
	size_t	longest_number;

	longest_number = 0;
	i = 0;
	while (i < len)
	{
		number_len = ft_intlen(stack_a[i]);
		if (number_len > longest_number)
			longest_number = number_len;
		number_len = ft_intlen(stack_b[i]);
		if (number_len > longest_number)
			longest_number = number_len;
		i++;
	}
	return (longest_number);
}

void	print_stacks(int *stack_a, int *stack_b, size_t len)
{
	size_t	i;
	size_t	longest_number;

	longest_number = longest_number_len(stack_a, stack_b, len);
	i = 0;
	while (i < len)
	{
		printf("%*d | %-*d\n", (int)longest_number, stack_a[i], (int)longest_number,
			stack_b[i]);
		i++;
	}
	i = 0;
	while (i++ < longest_number * 2 + 3)
		putchar('-');
	putchar('\n');
	putchar('\n');
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
	stack_b = calloc(argc - 1, sizeof (stack_b));
	print_stacks(stack_a, stack_b, argc - 1);
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
		if (!isatty(0))
			printf("%s\n", operation);
		print_stacks(stack_a, stack_b, argc - 1);
		free(operation);
		count++;
	}
	printf("TOTAL: %zu\n", count);
	free(operation);
	free(stack_a);
	free(stack_b);
	return (0);
}
