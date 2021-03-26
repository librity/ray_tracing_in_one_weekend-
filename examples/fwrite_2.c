/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fwrite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:49:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 19:49:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	FILE *fp;
	char str[] = "This is tutorialspoint.com";

	fp = fopen("file.txt", "w");
	fwrite(str, 1, sizeof(str), fp);

	fclose(fp);

	return (0);
}
