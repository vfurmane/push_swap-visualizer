/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_ps.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:19:22 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/05 12:13:50 by vfurmane         ###   ########.fr       */
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

typedef void	(*t_operation)(void);

void	perform_pa(void);
void	perform_pb(void);

void	perform_rra(void);
void	perform_rrb(void);
void	perform_rrr(void);

void	perform_ra(void);
void	perform_rb(void);
void	perform_rr(void);

void	perform_sa(void);
void	perform_sb(void);
void	perform_ss(void);

#endif
