/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:41:22 by gficara           #+#    #+#             */
/*   Updated: 2018/01/30 14:55:29 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

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
	int					per;
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
char					*zero(char *tmp, t_flags flags, int u);
void					uniwrite(int let, int len);
int						hashdown(t_flags flags, int c);
char					*mincor(char *tmp, t_flags flags);
char					*zerobase(char *tmp, t_flags flags, int u);
void					letfound(char *pnt, va_list ap, t_flags flags,
		int *count);
int						nfound(char *pnt, int i, int *count, t_flags flags);

int						pr_str(va_list ap, t_flags flags);
int						pr_char(va_list ap, t_flags flags);
int						pr_dec(va_list ap, t_flags flags);
int						pr_udec(va_list ap, t_flags flags);
int						pr_oct(va_list ap, t_flags flags);
int						pr_hex(va_list ap, t_flags flags);
int						pr_mhex(va_list ap, t_flags flags);
int						pr_bin(va_list ap, t_flags flags);
int						pr_pnt(va_list ap, t_flags flags);
int						pr_mdec(va_list ap, t_flags flags);
int						pr_mudec(va_list ap, t_flags flags);
int						pr_moct(va_list ap, t_flags flags);
int						pr_ustr(va_list ap, t_flags flags);
int						pr_uchar(va_list ap, t_flags flags);

typedef struct			s_print
{
	char				spec;
	int					(*fun)(va_list, t_flags);
}						t_print;

static t_print			g_print[] = {{'s', &pr_str}, {'c', &pr_char},
	{'i', &pr_dec}, {'d', &pr_dec}, {'u', &pr_udec}, {'o', &pr_oct},
	{'x', &pr_hex}, {'X', &pr_mhex}, {'b', &pr_bin}, {'p', &pr_pnt},
	{'D', &pr_mdec}, {'U', &pr_mudec}, {'O', &pr_moct}, {'S', &pr_ustr},
	{'C', &pr_uchar}, {'%', &pr_char}};

#endif
