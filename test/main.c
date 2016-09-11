/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 10:48:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/11 14:04:44 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libfts.h"

int main(void)
{
	char buf[256];
	// ft_puts
	// ft_bzero
	*buf = 0;
	strcat(buf, "lol");
	dprintf(1, "ft_bzero:\n\t%s\n", buf);
	dprintf(1, "\t%03d %03d %03d %03d (constant)\n", buf[0], buf[1], buf[2], buf[3]);
	ft_bzero(NULL, 42);
	dprintf(1, "\t%03d %03d %03d %03d (null)\n", buf[0], buf[1], buf[2], buf[3]);
	ft_bzero(buf, 0);
	dprintf(1, "\t%03d %03d %03d %03d (zero)\n", buf[0], buf[1], buf[2], buf[3]);
	ft_bzero(buf, 1);
	dprintf(1, "\t%03d %03d %03d %03d (one)\n", buf[0], buf[1], buf[2], buf[3]);
	ft_bzero(buf, 4);
	dprintf(1, "\t%03d %03d %03d %03d (four)\n", buf[0], buf[1], buf[2], buf[3]);
	// ft_strcat
	*buf = 0;
	strcat(buf, "lol");
	dprintf(1, "ft_strcat:\n\t%s\n", buf);
	ft_strcat(buf, "cats");
	dprintf(1, "\t%s\n", buf);
	ft_strcat(buf, "!");
	dprintf(1, "\t%s\n", buf);
	ft_strcat(buf, "");
	dprintf(1, "\t%s\n", buf);
	// ft_isalpha
	dprintf(1, "ft_isalpha:\n");
	dprintf(1, "\t%c -> %d\n", '!', ft_isalpha('!'));
	dprintf(1, "\t%c -> %d\n", '@', ft_isalpha('@'));
	dprintf(1, "\t%c -> %d\n", 'A', ft_isalpha('A'));
	dprintf(1, "\t%c -> %d\n", 'F', ft_isalpha('F'));
	dprintf(1, "\t%c -> %d\n", 'K', ft_isalpha('K'));
	dprintf(1, "\t%c -> %d\n", 'T', ft_isalpha('T'));
	dprintf(1, "\t%c -> %d\n", 'Z', ft_isalpha('Z'));
	dprintf(1, "\t%c -> %d\n", '[', ft_isalpha('['));
	dprintf(1, "\t%c -> %d\n", '`', ft_isalpha('`'));
	dprintf(1, "\t%c -> %d\n", 'a', ft_isalpha('a'));
	dprintf(1, "\t%c -> %d\n", 'f', ft_isalpha('f'));
	dprintf(1, "\t%c -> %d\n", 'k', ft_isalpha('k'));
	dprintf(1, "\t%c -> %d\n", 't', ft_isalpha('t'));
	dprintf(1, "\t%c -> %d\n", 'z', ft_isalpha('z'));
	dprintf(1, "\t%c -> %d\n", '{', ft_isalpha('{'));
	dprintf(1, "\t%c -> %d\n", '~', ft_isalpha('~'));
	// ft_isdigit
	dprintf(1, "ft_isdigit:\n");
	dprintf(1, "\t%c -> %d\n", '+', ft_isdigit('+'));
	dprintf(1, "\t%c -> %d\n", '/', ft_isdigit('/'));
	dprintf(1, "\t%c -> %d\n", '0', ft_isdigit('0'));
	dprintf(1, "\t%c -> %d\n", '4', ft_isdigit('4'));
	dprintf(1, "\t%c -> %d\n", '2', ft_isdigit('2'));
	dprintf(1, "\t%c -> %d\n", '9', ft_isdigit('9'));
	dprintf(1, "\t%c -> %d\n", ':', ft_isdigit(':'));
	dprintf(1, "\t%c -> %d\n", 'z', ft_isdigit('z'));
	// ft_isalnum
	dprintf(1, "ft_isalnum:\n");
	dprintf(1, "\t%c -> %d\n", '!', ft_isalnum('!'));
	dprintf(1, "\t%c -> %d\n", '/', ft_isalnum('/'));
	dprintf(1, "\t%c -> %d\n", '0', ft_isalnum('0'));
	dprintf(1, "\t%c -> %d\n", '4', ft_isalnum('4'));
	dprintf(1, "\t%c -> %d\n", '2', ft_isalnum('2'));
	dprintf(1, "\t%c -> %d\n", '9', ft_isalnum('9'));
	dprintf(1, "\t%c -> %d\n", ':', ft_isalnum(':'));
	dprintf(1, "\t%c -> %d\n", '@', ft_isalnum('@'));
	dprintf(1, "\t%c -> %d\n", 'A', ft_isalnum('A'));
	dprintf(1, "\t%c -> %d\n", 'F', ft_isalnum('F'));
	dprintf(1, "\t%c -> %d\n", 'K', ft_isalnum('K'));
	dprintf(1, "\t%c -> %d\n", 'T', ft_isalnum('T'));
	dprintf(1, "\t%c -> %d\n", 'Z', ft_isalnum('Z'));
	dprintf(1, "\t%c -> %d\n", '[', ft_isalnum('['));
	dprintf(1, "\t%c -> %d\n", '`', ft_isalnum('`'));
	dprintf(1, "\t%c -> %d\n", 'a', ft_isalnum('a'));
	dprintf(1, "\t%c -> %d\n", 'f', ft_isalnum('f'));
	dprintf(1, "\t%c -> %d\n", 'k', ft_isalnum('k'));
	dprintf(1, "\t%c -> %d\n", 't', ft_isalnum('t'));
	dprintf(1, "\t%c -> %d\n", 'z', ft_isalnum('z'));
	dprintf(1, "\t%c -> %d\n", '{', ft_isalnum('{'));
	dprintf(1, "\t%c -> %d\n", '~', ft_isalnum('~'));
	// ft_isascii
	dprintf(1, "ft_isascii:\n");
	dprintf(1, "\t-1  -> %d\n", ft_isascii(-1));
	dprintf(1, "\t0   -> %d\n", ft_isascii(0));
	dprintf(1, "\t25  -> %d\n", ft_isascii(25));
	dprintf(1, "\t31  -> %d\n", ft_isascii(31));
	dprintf(1, "\t' ' -> %d\n", ft_isascii(' '));
	dprintf(1, "\t%c   -> %d\n", '@', ft_isascii('@'));
	dprintf(1, "\t%c   -> %d\n", '~', ft_isascii('~'));
	dprintf(1, "\t127 -> %d\n", ft_isascii(127));
	dprintf(1, "\t130 -> %d\n", ft_isascii(130));
	// ft_isprint
	dprintf(1, "ft_isprint:\n");
	dprintf(1, "\t25  -> %d\n", ft_isprint(25));
	dprintf(1, "\t31  -> %d\n", ft_isprint(31));
	dprintf(1, "\t' ' -> %d\n", ft_isprint(' '));
	dprintf(1, "\t%c   -> %d\n", '@', ft_isprint('@'));
	dprintf(1, "\t%c   -> %d\n", '~', ft_isprint('~'));
	dprintf(1, "\t127 -> %d\n", ft_isprint(127));
	dprintf(1, "\t130 -> %d\n", ft_isprint(130));
	// ft_toupper
	dprintf(1, "ft_toupper:\n");
	dprintf(1, "\t%c -> %c\n", '!', ft_toupper('!'));
	dprintf(1, "\t%c -> %c\n", '@', ft_toupper('@'));
	dprintf(1, "\t%c -> %c\n", 'A', ft_toupper('A'));
	dprintf(1, "\t%c -> %c\n", 'F', ft_toupper('F'));
	dprintf(1, "\t%c -> %c\n", 'K', ft_toupper('K'));
	dprintf(1, "\t%c -> %c\n", 'T', ft_toupper('T'));
	dprintf(1, "\t%c -> %c\n", 'Z', ft_toupper('Z'));
	dprintf(1, "\t%c -> %c\n", '[', ft_toupper('['));
	dprintf(1, "\t%c -> %c\n", '`', ft_toupper('`'));
	dprintf(1, "\t%c -> %c\n", 'a', ft_toupper('a'));
	dprintf(1, "\t%c -> %c\n", 'f', ft_toupper('f'));
	dprintf(1, "\t%c -> %c\n", 'k', ft_toupper('k'));
	dprintf(1, "\t%c -> %c\n", 't', ft_toupper('t'));
	dprintf(1, "\t%c -> %c\n", 'z', ft_toupper('z'));
	dprintf(1, "\t%c -> %c\n", '{', ft_toupper('{'));
	dprintf(1, "\t%c -> %c\n", '~', ft_toupper('~'));
	// ft_tolower
	dprintf(1, "ft_tolower:\n");
	dprintf(1, "\t%c -> %c\n", '!', ft_tolower('!'));
	dprintf(1, "\t%c -> %c\n", '@', ft_tolower('@'));
	dprintf(1, "\t%c -> %c\n", 'A', ft_tolower('A'));
	dprintf(1, "\t%c -> %c\n", 'F', ft_tolower('F'));
	dprintf(1, "\t%c -> %c\n", 'K', ft_tolower('K'));
	dprintf(1, "\t%c -> %c\n", 'T', ft_tolower('T'));
	dprintf(1, "\t%c -> %c\n", 'Z', ft_tolower('Z'));
	dprintf(1, "\t%c -> %c\n", '[', ft_tolower('['));
	dprintf(1, "\t%c -> %c\n", '`', ft_tolower('`'));
	dprintf(1, "\t%c -> %c\n", 'a', ft_tolower('a'));
	dprintf(1, "\t%c -> %c\n", 'f', ft_tolower('f'));
	dprintf(1, "\t%c -> %c\n", 'k', ft_tolower('k'));
	dprintf(1, "\t%c -> %c\n", 't', ft_tolower('t'));
	dprintf(1, "\t%c -> %c\n", 'z', ft_tolower('z'));
	dprintf(1, "\t%c -> %c\n", '{', ft_tolower('{'));
	dprintf(1, "\t%c -> %c\n", '~', ft_tolower('~'));
	// ft_puts
	dprintf(1, "ft_puts:\n");
	dprintf(1, "\tlol  -> %d\n", ft_puts("lol"));
	dprintf(1, "\tcats -> %d\n", ft_puts("cats"));
}
