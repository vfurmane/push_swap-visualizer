/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:19:45 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/06 11:03:51 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_ps.h"

size_t	longest_number_len(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len)
{
	size_t	i;
	size_t	number_len;
	size_t	longest_number;

	longest_number = 0;
	i = 0;
	while (i < len)
	{
		number_len = ft_intlen(stack_a[i].value);
		if (number_len > longest_number)
			longest_number = number_len;
		number_len = ft_intlen(stack_b[i].value);
		if (number_len > longest_number)
			longest_number = number_len;
		i++;
	}
	return (longest_number);
}

void	print_stacks(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len)
{
	size_t	i;
	size_t	longest_number;

	longest_number = longest_number_len(stack_a, stack_b, len);
	i = 0;
	while (i < len && (stack_a[i].enabled == true || stack_b[i].enabled == true))
	{
		if (stack_a[i].enabled)
			printf("%*d", (int)longest_number, stack_a[i].value);
		else
			printf("%*c", (int)longest_number, ' ');
		printf(" | ");
		if (stack_b[i].enabled)
			printf("%*d", (int)longest_number, stack_b[i].value);
		else
			printf("%*c", (int)longest_number, ' ');
		printf("\n");
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
	t_stack_elm	*stack_a;
	t_stack_elm	*stack_b;
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
