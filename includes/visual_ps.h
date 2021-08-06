/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_ps.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:19:22 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/06 10:37:47 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_PS_H
# define VISUAL_PS_H

# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include "get_next_line.h"
# include "utils.h"

# ifndef RESET_COLOR
#  define RESET_COLOR "\e[0m"
# endif

# ifndef COLOR_RED
#  define COLOR_RED "\e[31m"
# endif

typedef struct s_stack_elm
{
	int		value;
	bool	enabled;
}				t_stack_elm;

typedef void	(*t_operation)(t_stack_elm*, t_stack_elm*, size_t);

void	perform_px(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len);

void	perform_rrx(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len);
void	perform_rrr(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len);

void	perform_rx(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len);
void	perform_rr(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len);

void	perform_sx(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len);
void	perform_ss(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len);

size_t		stack_len(t_stack_elm *stack, size_t len);
t_stack_elm	*last_stack_elm(t_stack_elm *stack, size_t len);
t_stack_elm	*parse_stack(int argc, char **argv);
int	perform_operation(t_stack_elm *stack_a, t_stack_elm *stack_b, size_t len,
	const char *operation);

#endif
