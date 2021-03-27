/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:17:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 03:31:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

static void	print_error(char *message)
{
	while (*message)
		write(1, message++, 1);
	write(1, "\n", 1);
}

static char	*fetch_error_message(t_bitmap_error code)
{
	static char	*error_messages[GENERIC_ERROR] = {
		"Error creating file.",
		"Header didn't initialize properly.",
		"Unable to allocate required memory.",
		"Generic bitmap error.",
	};

	return (error_messages[code]);
}

void		ft_die_bitmap(t_bitmap_error code)
{
	print_error(fetch_error_message(code));
	exit(EXIT_FAILURE);
}