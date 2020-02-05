/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lgdbl_toa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:50:31 by dapinto           #+#    #+#             */
/*   Updated: 2019/11/06 11:01:43 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		rec_size(int nb, int fg_negative, int ret)
{
	if (nb == 0 && fg_negative == 1)
		return (ret + 1);
	else if (nb == 0 && fg_negative <= 0)
		return (ret);
	return (rec_size(nb / 10, fg_negative, ret + 1));
}

static char		*actualize(char *a, size_t len)
{
	int		i;

	i = ft_strichr(a, ':');
	while (len && i >= 0 && (a[i] == ':' || a[i] == '9' || a[i] == '.'))
	{
		if (a[i] == '9' || a[i] == ':')
			a[i] = '0';
		len--;
		i--;
	}
	if (i != -1)
	{
		a[i] = a[i] + 1;
		return (a);
	}
	if (ft_nchrchck(a, "0.", len) >= 0)
		a = clean_pad(a, '1', 0, 1);
	return (a);
}

static int		storedeci(long int fpart, char *a, int preci)
{
	int i;
	int fg;

	i = 0;
	while (fpart)
	{
		if (i == 0)
		{
			fg = fpart % 10;
			fpart /= 10;
			a[i++] = (fg >= 5) ? ((fpart % 10) + 1) + '0' : fpart % 10 + '0';
			fpart /= 10;
		}
		if (!fpart)
			break ;
		a[i++] = (fpart % 10) + '0';
		fpart /= 10;
	}
	while (i < preci)
		a[i++] = '0';
	a[i] = '\0';
	ft_strrev(a);
	return (i);
}

static int		storedigits(intmax_t nb, char *a, int fg)
{
	int i;

	i = 0;
	if (nb == 0)
		a[i++] = '0';
	while (nb)
	{
		a[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (fg)
		a[i++] = '-';
	a[i] = '\0';
	ft_strrev(a);
	return (i);
}

char			*ft_ldbltoa(long double nb, int preci, int fg)
{
	char		*a;
	int			i;
	long double	fpart;
	intmax_t	ipart;

	a = NULL;
	ipart = (intmax_t)nb;
	fpart = nb - (long double)ipart;
	preci += (preci > 0) ? 1 : 0;
	if (!(a = ft_strnew(rec_size((int)nb, fg, 0) + preci)))
		return (NULL);
	i = storedigits(ipart, a, fg);
	if (preci > 0)
	{
		a[i] = '.';
		preci--;
		fpart = fpart * ft_recursive_power(10, preci + 1);
		storedeci((long int)fpart, a + i + 1, preci);
	}
	a = (ft_strchr(a, ':')) ? actualize(a, ft_strlen(a)) : a;
	return (a);
}
