/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_ps.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:19:22 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/05 13:32:19 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_PS_H
# define VISUAL_PS_H

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

typedef void	(*t_operation)(int*, size_t);

void	perform_px(int *stack, size_t len);

void	perform_rrx(int *stack, size_t len);
void	perform_rrr(int *stack, size_t len);

void	perform_rx(int *stack, size_t len);
void	perform_rr(int *stack, size_t len);

void	perform_sx(int *stack, size_t len);
void	perform_ss(int *stack, size_t len);

#endif
