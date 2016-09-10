/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 10:48:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/10 15:55:22 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libfts.h"

int main(void)
{
	char buf[256];
	// ft_bzero
	*buf = 0;
	strcat(buf, "lol");
	printf("ft_bzero:\n\t%s\n", buf);
	printf("\t%03d %03d %03d %03d (constant)\n", buf[0], buf[1], buf[2], buf[3]);
	ft_bzero(NULL, 42);
	printf("\t%03d %03d %03d %03d (null)\n", buf[0], buf[1], buf[2], buf[3]);
	ft_bzero(buf, 0);
	printf("\t%03d %03d %03d %03d (zero)\n", buf[0], buf[1], buf[2], buf[3]);
	ft_bzero(buf, 1);
	printf("\t%03d %03d %03d %03d (one)\n", buf[0], buf[1], buf[2], buf[3]);
	ft_bzero(buf, 4);
	printf("\t%03d %03d %03d %03d (four)\n", buf[0], buf[1], buf[2], buf[3]);
	// ft_strcat
	*buf = 0;
	strcat(buf, "lol");
	printf("ft_strcat:\n\t%s\n", buf);
	ft_strcat(buf, "cats");
	printf("\t%s\n", buf);
	// ft_isdigit
	printf("ft_isdigit:\n");
	printf("\t%c -> %d\n", '+', ft_isdigit('+'));
	printf("\t%c -> %d\n", '0', ft_isdigit('0'));
	printf("\t%c -> %d\n", '4', ft_isdigit('4'));
	printf("\t%c -> %d\n", '2', ft_isdigit('2'));
	printf("\t%c -> %d\n", '9', ft_isdigit('9'));
	printf("\t%c -> %d\n", 'z', ft_isdigit('z'));
	// ft_isprint
	printf("ft_isprint:\n");
	printf("\t25  -> %d\n", ft_isprint(25));
	printf("\t' ' -> %d\n", ft_isprint(' '));
	printf("\t%c   -> %d\n", '@', ft_isprint('@'));
	printf("\t%c   -> %d\n", '~', ft_isprint('~'));
	printf("\t130 -> %d\n", ft_isprint(130));
}
