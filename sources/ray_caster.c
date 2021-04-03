/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:21:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 04:18:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_color_3d		hit_gradient_background(const t_ray ray,
										t_color_3d background_tone)
{
	t_color_3d	ambient_light = {1.0, 1.0, 1.0};
	t_color_3d	cast;
	t_vector_3d	unit_direction;
	double		gradient;

	unit_direction = unit(ray.direction);
	gradient = 0.5 * (unit_direction.y + 1.0);
	ambient_light = scalar_times(1.0 - gradient, ambient_light);
	background_tone = scalar_times(gradient, background_tone);
	cast = add(ambient_light, background_tone);
	return (cast);
}

bool			hit_any_spheres(const t_ray ray,
									t_list *spheres,
									t_hit_record *record)
{
	t_hit_record current_record;
	bool hit_anything = false;
	double closest_so_far = RTINFINITY;

	if (spheres == NULL || spheres->content == NULL)
		return (false);

	int sphere_count = ft_lstsize(spheres);
	while (sphere_count--)
	{
		if (ray_hits_sphere(ray, spheres->content, &current_record, 0.001, closest_so_far))
		{
			hit_anything = true;
			if (current_record.translation < closest_so_far)
			{
				closest_so_far = current_record.translation;
				set_record(record, current_record);
			}
		}
		spheres = spheres->next;
	}

	return hit_anything;
}

t_color_3d		cast_ray(const t_ray ray, t_list *spheres, int depth)
{
	t_hit_record	record;

	if (depth <= 0)
		return ((t_color_3d){0.0, 0.0, 0.0});
	if (hit_any_spheres(ray, spheres, &record))
		return (render_sphere(ray, &record, spheres, depth));
	return (hit_gradient_background(ray, (t_color_3d){0.5, 0.7, 1.0}));
}