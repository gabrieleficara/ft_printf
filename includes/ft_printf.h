/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:41:22 by gficara           #+#    #+#             */
/*   Updated: 2018/01/17 18:06:05 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct			s_flags
{
	int					min;
	int					plu;
	int					spa;
	int					zer;
	int					has;
	int					h;
	int					l;
	int					z;
	int					j;
	int					wid;
	int					pre;
	int					dot;
}						t_flags;

int						ft_printf(const char *restrict format, ...);
int						putspecstr(char *tmp, t_flags flags);
int						findspec(char *pnt, va_list ap, t_flags flags,
		int *count);
char					*ft_itoa_base(intmax_t n, int base, int caps);
char					*ft_itoa_base_u(unsigned long int n, int base,
		int caps);
int						putspecint(char *tmp, t_flags flags);
long long				ft_abs_base(long long n);

int						pr_str(va_list ap, t_flags flags);
int						pr_char(va_list ap, t_flags flags);
int						pr_dec(va_list ap, t_flags flags);

typedef struct			s_print
{
	char				spec;
	int					(*fun)(va_list, t_flags);
}						t_print;

static t_print			g_print[] = {{'s', &pr_str}, {'c', &pr_char},
	{'i', &pr_dec}, {'d', &pr_dec}};

#endif
