/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fraction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:49:16 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/11 17:40:40 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		div_frac(unsigned long long *a, int times)
{
	int	i;
	int	e;
	unsigned long long c;

	e = 0;
	while (times != 0)
	{
		i = 100;
		c = 0;
		while (i != 0)
		{
			c = get_mincarry(a + i, c);
			i--;
		}
		carry_frac(a);
		e += shift_frac(a);
		times--;
	}
	return (e);
}

int		shift_frac(unsigned long long *a)
{
	int	e;
	int i;

	e = 0;
	while (100 - e > 0 && a[100 - e] == 0)
		e++;	
	i = 100;
	while (i - e > -1)
	{
		a[i] = a[i - e];
		i--;
	}
	return (e);
}

unsigned long long get_mincarry(unsigned long long *a, unsigned long long carry)
{
	unsigned long long tmp;

	if (*a == 0)
	{
		*a += carry;
		return (0);
	}
	tmp = *a;
	*a /= 2;
	*a += carry;
	if (tmp % 2 == 1)
		return (50000000);
	else
		return (0);
}

void		add_frac(unsigned long long *a, unsigned long long **b)
{
	int	i;
	int e;

	e = 0;
	i = 0;
	while (i < 101)
	{
		a[i] += *(*b + i);
		i++;
	}
	carry_frac(a);
	free(*b);
}

void	mult_frac(unsigned long long *frac, int a, int times, int zero)
{
	int	i;
	int	index;

	i = 0;
	while (i < times)
	{
		index = zero;
		while (index < 101)
		{
			frac[index] *= a;
			index++;
		}
		carry_frac(frac);
		i++;
	}
}

void	carry_frac(unsigned long long *frac10)
{
	int	i;
	unsigned long long c;

	i = 0;
	while (i < 100)
	{
		if (frac10[i] != 0)
		{
			c = frac10[i] / 100000000;
			frac10[i] %= 100000000;
		}
		else
			c = 0;
		frac10[i + 1] += c;
		i++;
	}
}