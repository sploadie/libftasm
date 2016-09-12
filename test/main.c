/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 10:48:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/12 16:55:01 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libfts.h"

int main(void)
{
	char	*tmp;
	char	buf[256];
	int		fd;
	// ft_puts
	dprintf(1, "\x1b[32mft_puts:\x1b[0m\n");
	dprintf(1, "\t''   -> %2d\n", ft_puts(""));
	dprintf(1, "\tNULL -> %2d\n", ft_puts(NULL));
	dprintf(1, "\tlol  -> %2d\n", ft_puts("lol"));
	dprintf(1, "\tcats -> %2d\n", ft_puts("cats"));
	// ft_bzero
	strcpy(buf, "lol");
	dprintf(1, "\x1b[32mft_bzero:\x1b[0m\n\t%s [original]\n", buf);
	dprintf(1, "\t%03d %03d %03d %03d [original]\n", buf[0], buf[1], buf[2], buf[3]);
	ft_bzero(NULL, 42);
	dprintf(1, "\t%03d %03d %03d %03d (null)\n", buf[0], buf[1], buf[2], buf[3]);
	ft_bzero(buf, 0);
	dprintf(1, "\t%03d %03d %03d %03d (zero)\n", buf[0], buf[1], buf[2], buf[3]);
	ft_bzero(buf, 1);
	dprintf(1, "\t%03d %03d %03d %03d (one)\n", buf[0], buf[1], buf[2], buf[3]);
	ft_bzero(buf, 2);
	dprintf(1, "\t%03d %03d %03d %03d (two)\n", buf[0], buf[1], buf[2], buf[3]);
	ft_bzero(buf, 4);
	dprintf(1, "\t%03d %03d %03d %03d (four)\n", buf[0], buf[1], buf[2], buf[3]);
	// ft_strcat
	strcpy(buf, "lol");
	dprintf(1, "\x1b[32mft_strcat:\x1b[0m\n");
	dprintf(1, "\t%s (buf)\n", buf);
	dprintf(1, "\t%s (buf, 'cats')\n", ft_strcat(buf, "cats"));
	dprintf(1, "\t%s (buf, '!')\n", ft_strcat(buf, "!"));
	dprintf(1, "\t%s (buf, '')\n", ft_strcat(buf, ""));
	dprintf(1, "\t%s (buf, NULL)\n", ft_strcat(buf, NULL));
	dprintf(1, "\t%s (NULL, 'hm...')\n", ft_strcat(NULL, "hm..."));
	// ft_isalpha
	dprintf(1, "\x1b[32mft_isalpha:\x1b[0m\n");
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
	dprintf(1, "\x1b[32mft_isdigit:\x1b[0m\n");
	dprintf(1, "\t%c -> %d\n", '+', ft_isdigit('+'));
	dprintf(1, "\t%c -> %d\n", '/', ft_isdigit('/'));
	dprintf(1, "\t%c -> %d\n", '0', ft_isdigit('0'));
	dprintf(1, "\t%c -> %d\n", '4', ft_isdigit('4'));
	dprintf(1, "\t%c -> %d\n", '2', ft_isdigit('2'));
	dprintf(1, "\t%c -> %d\n", '9', ft_isdigit('9'));
	dprintf(1, "\t%c -> %d\n", ':', ft_isdigit(':'));
	dprintf(1, "\t%c -> %d\n", 'z', ft_isdigit('z'));
	// ft_isalnum
	dprintf(1, "\x1b[32mft_isalnum:\x1b[0m\n");
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
	dprintf(1, "\x1b[32mft_isascii:\x1b[0m\n");
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
	dprintf(1, "\x1b[32mft_isprint:\x1b[0m\n");
	dprintf(1, "\t25  -> %d\n", ft_isprint(25));
	dprintf(1, "\t31  -> %d\n", ft_isprint(31));
	dprintf(1, "\t' ' -> %d\n", ft_isprint(' '));
	dprintf(1, "\t%c   -> %d\n", '@', ft_isprint('@'));
	dprintf(1, "\t%c   -> %d\n", '~', ft_isprint('~'));
	dprintf(1, "\t127 -> %d\n", ft_isprint(127));
	dprintf(1, "\t130 -> %d\n", ft_isprint(130));
	// ft_toupper
	dprintf(1, "\x1b[32mft_toupper:\x1b[0m\n");
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
	dprintf(1, "\x1b[32mft_tolower:\x1b[0m\n");
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
	// ft_strlen
	dprintf(1, "\x1b[32mft_strlen:\x1b[0m\n");
	dprintf(1, "\t%s -> %zu\n", NULL, ft_strlen(NULL));
	dprintf(1, "\t'' -> %zu\n", ft_strlen(""));
	dprintf(1, "\t%s -> %zu\n", "lol", ft_strlen("lol"));
	dprintf(1, "\t%s -> %zu\n", "cats", ft_strlen("cats"));
	dprintf(1, "\t%s -> %zu\n", "lolcats", ft_strlen("lolcats"));
	dprintf(1, "\t%s -> %zu\n", "lolcats!", ft_strlen("lolcats!"));
	// ft_memset
	memset(buf, 0, 256);
	dprintf(1, "\x1b[32mft_memset:\x1b[0m\n");
	dprintf(1, "\t'%s' <- buf\n", buf);
	dprintf(1, "\t'%s' <- ft_memset(NULL, 42, 42)\n", ft_memset(NULL, 42, 42));
	dprintf(1, "\t'%s' <- ft_memset(buf, '$', 25)\n", ft_memset(buf, '$', 25));
	dprintf(1, "\t'%s' <- ft_memset(buf, '-', 20)\n", ft_memset(buf, '-', 20));
	dprintf(1, "\t'%s' <- ft_memset(buf, '=', 10)\n", ft_memset(buf, '=', 10));
	dprintf(1, "\t'%s' <- ft_memset(buf, 'H', 5)\n",  ft_memset(buf, 'H', 5));
	dprintf(1, "\t'%s' <- ft_memset(buf, 'B', 1)\n",  ft_memset(buf, 'B', 1));
	dprintf(1, "\t'%s' <- ft_memset(buf, '~', 0)\n",  ft_memset(buf, '~', 0));
	// ft_memcpy
	memset(buf, 0, 256);
	dprintf(1, "\x1b[32mft_memcpy:\x1b[0m\n");
	dprintf(1, "\t'%s' <- buf\n", buf);
	dprintf(1, "\t'%s' <- ft_memcpy(NULL, buf, 42)\n", ft_memcpy(NULL, buf, 42));
	dprintf(1, "\t'%s' <- ft_memcpy(buf, NULL, 42)\n", ft_memcpy(buf, NULL, 42));
	dprintf(1, "\t'%s' <- ft_memcpy(buf, 'YOLOSWAG!', 9)\n", ft_memcpy(buf, "YOLOSWAG!", 9));
	dprintf(1, "\t'%s' <- ft_memcpy(buf, 'BLUE RACECAR', 6)\n", ft_memcpy(buf, "BLUE RACECAR", 6));
	dprintf(1, "\t'%s' <- ft_memcpy(buf, 'TRUTH AND JUSTICE', 2)\n", ft_memcpy(buf, "TRUTH AND JUSTICE", 2));
	dprintf(1, "\t'%s' <- ft_memcpy(buf, 'NOTHING', 0)\n", ft_memcpy(buf, "NOTHING", 0));
	// ft_strdup
	dprintf(1, "\x1b[32mft_strdup:\x1b[0m\n");
	dprintf(1, "\t'%s' <- ft_strdup(NULL)\n", (tmp = ft_strdup(NULL)));
	dprintf(1, "\t'%s' <- ft_strdup('')\n", (tmp = ft_strdup("")));
	free(tmp);
	dprintf(1, "\t'%s' <- ft_strdup('yolo')\n", (tmp = ft_strdup("yolo")));
	free(tmp);
	dprintf(1, "\t'%s' <- ft_strdup('My ft_strdup seems to work folks.')\n", (tmp = ft_strdup("My ft_strdup seems to work folks.")));
	free(tmp);
	// ft_cat
	dprintf(1, "\x1b[32mft_cat Makefile:\x1b[0m\n");
	fd = open("./Makefile", O_RDONLY);
	ft_cat(fd);
	close(fd);
	dprintf(1, "\x1b[32mft_cat stdin: (ctrl-D to quit)\x1b[0m\n");
	ft_cat(0);
	// ft_strcmp
	dprintf(1, "\x1b[32mft_strcmp:\x1b[0m\n");
	dprintf(1, "\t%d <- ft_strcmp('42', '42')\n", ft_strcmp("42", "42"));
	dprintf(1, "\t%d <- ft_strcmp('AAA', 'BBB')\n", ft_strcmp("AAA", "BBB"));
	dprintf(1, "\t%d <- ft_strcmp('1', '22')\n", ft_strcmp("1", "22"));
	dprintf(1, "\t%d <- ft_strcmp('11', '2')\n", ft_strcmp("11", "2"));
	dprintf(1, "\t%d <- ft_strcmp('1234', '123')\n", ft_strcmp("1234", "123"));
	dprintf(1, "\t%d <- ft_strcmp('123', '1234')\n", ft_strcmp("123", "1234"));
	dprintf(1, "\t%d <- ft_strcmp('Equal States', 'Equal Factions')\n", ft_strcmp("Equal States", "Equal Factions"));
	dprintf(1, "\t%d <- ft_strcmp('Equal Factions', 'Equal Factions')\n", ft_strcmp("Equal Factions", "Equal Factions"));
	// ft_memdup
	dprintf(1, "\x1b[32mft_memdup:\x1b[0m\n");
	tmp = ft_memdup(NULL, 42);
		dprintf(1, "\t'%s' <- ft_memdup(NULL, 42)\n", tmp);
	tmp = ft_memdup("", 0);
		dprintf(1, "\tZERO <- ft_memdup('', 0)\n");
		free(tmp);
	tmp = ft_memdup("", 1);
		dprintf(1, "\t'%s' <- ft_memdup('', 1)\n", tmp);
		free(tmp);
	tmp = ft_memdup("My ft_memdup seems to work folks.", 13);
		tmp[12] = 0;
		dprintf(1, "\t'%s' <- ft_memdup('My ft_memdup seems to work folks.', 13)\n", tmp);
		free(tmp);
	tmp = ft_memdup("My ft_memdup seems to work folks.", 34);
		dprintf(1, "\t'%s' <- ft_memdup('My ft_memdup seems to work folks.', 34)\n", tmp);
		free(tmp);
}
