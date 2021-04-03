/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtrandom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:50:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 23:12:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

double		random_double(void)
{
	return rand() / (RAND_MAX + 1.0);
}

double		random_from(double min, double max)
{
	return min + (max - min) * random_double();
}

double		canonical_random(void)
{
	return (random_from(0.0, 1.0));
}

double		rp(void)
{
	return (random_from(-1.0, 1.0));
}

double		rr(void)
{
	return (random_from(0.0, 0.1));
}

t_vector_3d	rc(void)
{
	return ((t_color_3d){random_from(0.0, 1.0),
							random_from(0.0, 1.0),
							random_from(0.0, 1.0)});
}

t_vector_3d	random_vector(void)
{
	return ((t_vector_3d){random_double(), random_double(), random_double()});
}

t_vector_3d	random_vector_in(double min, double max)
{
	return ((t_vector_3d){random_from(min, max),
							random_from(min, max),
							random_from(min, max)});
}

t_vector_3d		random_unit_vector(void)
{
	t_vector_3d normalized_in_sphere;

	normalized_in_sphere = unit(random_in_unit_sphere());
	return (normalized_in_sphere);
}

t_point_3d		random_in_unit_sphere(void)
{
	t_point_3d random;

	while (true)
	{
		random = random_vector_in(-1.0, 1.0);
		if (length_squared(random) >= 1)
			continue ;
		return (random);
	}
}

t_point_3d		random_in_unit_disk(void)
{
	t_point_3d random;

	while (true)
	{
		random = (t_vector_3d){random_from(-1.0, 1.0), random_from(-1.0, 1.0), 0};
		if (length_squared(random) >= 1)
			continue ;
		return (random);
	}
}

t_vector_3d		random_in_hemisphere(const t_vector_3d normal)
{
	t_vector_3d in_unit_sphere;

	in_unit_sphere = random_in_unit_sphere();
	if (dot(in_unit_sphere, normal) > 0.0)
		return (in_unit_sphere);
	return (negative(in_unit_sphere));
}
