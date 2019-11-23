/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:33:14 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/11/23 17:33:18 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* мейн компилится и просто выводит фигурки, принтэфы уберем потом))) пока что тут важны описания картинок*/
//
//int		make_img(void)
//{
//int		total;
//t_tetra	main;
//char 	*name;
//
//name = "1_1";
//total = 19;
//main = new_tetra(name);
//while (total != 0)
//{
//
//}
//


//}

t_tetra	*new_tetra(char *nam)
{
	t_tetra	*new;

	new = (t_tetra *)malloc(sizeof(t_tetra));
	new->name = nam;
	new->img = NULL;
	new->num = 0;
	new->next = NULL;
	return (new);
}

int		draw_img(char *line)
{
	char	*stoy;
	char	*niz;

	stoy = "#\n#\n#\n#\n";
	niz = "####\n";

	printf("%s\n", stoy);
	printf("%s\n", niz);
	return (0);
}

int		draw_img2(char *ugol)
{
	char	*stoypr;
	char	*stoylv;
	char 	*sidpr;
	char 	*sidlv;
	char 	*lezlev;
	char 	*lezpr;
	char 	*padpr;
	char 	*padlv;

	stoypr = "##\n#.\n#.\n";
	stoylv = "##\n.#\n.#\n";
	sidpr = "#.\n#.\n##\n";
	sidlv = ".#\n.#\n##\n";
	lezlev = "#..\n###\n";
	lezpr = "..#\n###\n";
	padpr = "###\n..#\n";
	padlv = "###\n#..\n";

	printf("%s\n", stoypr);
	printf("%s\n", stoylv);
	printf("%s\n", sidpr);
	printf("%s\n", sidlv);
	printf("%s\n", lezlev);
	printf("%s\n", lezpr);
	printf("%s\n", padpr);
	printf("%s\n", padlv);
	return (0);
}

int		draw_img3(char *z)
{
	char	*zlv;
	char	*zpr;
	char 	*zvnlv;
	char 	*zvnpr;

	zlv = "##.\n.##\n";
	zpr = ".##\n##.\n";
	zvnlv = "#.\n##\n.#\n";
	zvnpr = ".#\n##\n#.\n";

	printf("%s\n", zlv);
	printf("%s\n", zpr);
	printf("%s\n", zvnlv);
	printf("%s\n", zvnpr);
	return (0);
}

int		draw_img4(char *pipka)
{
	char	*lv;
	char	*pr;
	char 	*verh;
	char 	*niz;

	lv = ".#\n##\n.#\n";
	pr = "#.\n##\n#.\n";
	verh = "###\n.#.\n";
	niz = ".#.\n###\n";

	printf("%s\n", lv);
	printf("%s\n", pr);
	printf("%s\n", verh);
	printf("%s\n", niz);
	return (0);
}

int		draw_img5(char *kvad)
{
	char	*op;

	op = "##\n##\n";
	printf("%s\n", op);
	return (0);
}

int		main()
{
	char 	*palka;

	palka = "palka";
	draw_img(palka);
	draw_img2(palka);
	draw_img3(palka);
	draw_img4(palka);
	draw_img5(palka);
	return (0);
}
/*
 * 1) Есть ли большая фигура (по имени) - определяет начальную сторону квадрата
 * 2) Пока общее кол-во фигур больше нуля, то выполняем в цикле
 *  - входит ли вторая по размеру фигуроа в квадрат определеный размеров первой фигуры
 *  	- если да - ок (пишем),
 *  	- если нет - пока не войдет в квадрат, сторона квадрата +1
 */