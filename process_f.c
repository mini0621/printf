/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:59:51 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/27 23:32:55 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*prcs_f(va_list *ap, t_printops *opt, size_t *l)
{
	long double	arg;
	char		*ret;
	t_lm		lm;
//TODO
	lm = opt->lmod;
	if (lm == 3)
		arg = (long double)va_arg(*ap, double);
	else
		arg = va_arg(*ap, long double);
	printf("%Lf\n", arg);
	if ((ret = ft_dltoa(arg, opt->precision))== NULL)
		return (NULL);
	*l = ft_strlen(ret);
	return (ret);
}
