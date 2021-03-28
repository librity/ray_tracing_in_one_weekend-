/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtrandom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:50:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/28 16:43:51 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

double	random_double(void)
{
	return rand() / (RAND_MAX + 1.0);
}

double	random_from(double min, double max)
{
	return min + (max - min) * random_double();
}

double	rp(void)
{
	return (random_from(-1.0, 1.0));
}

double	rr(void)
{
	return (random_from(0.0, 0.1));
}

double	canonical_random(void)
{
	return (random_from(0.0, 1.0));
}
