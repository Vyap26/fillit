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
	char	*a_1;
	char	*a_2;

	a_1 = "#\n#\n#\n#\n";
	a_2 = "####\n";

	printf("%s\n", a_1);
	printf("%s\n", a_2);
	return (0);
}

int		draw_img2(char *ugol)
{
	char	*b_1;
	char	*b_2;
	char 	*b_3;
	char 	*b_4;
	char 	*b_5;
	char 	*b_6;
	char 	*b_7;
	char 	*b_8;

	b_1 = "##\n#.\n#.\n";
	b_2 = "##\n.#\n.#\n";
	b_3 = "#.\n#.\n##\n";
	b_4 = ".#\n.#\n##\n";
	b_5 = "#..\n###\n";
	b_6 = "..#\n###\n";
	b_7 = "###\n..#\n";
	b_8 = "###\n#..\n";

	printf("%s\n", b_1);
	printf("%s\n", b_2);
	printf("%s\n", b_3);
	printf("%s\n", b_4);
	printf("%s\n", b_5);
	printf("%s\n", b_6);
	printf("%s\n", b_7);
	printf("%s\n", b_8);
	return (0);
}

int		draw_img3(char *z)
{
	char	*c_1;
	char	*c_2;
	char 	*c_3;
	char 	*c_4;

	c_1 = "##.\n.##\n";
	c_2 = ".##\n##.\n";
	c_3 = "#.\n##\n.#\n";
	c_4 = ".#\n##\n#.\n";

	printf("%s\n", c_1);
	printf("%s\n", c_2);
	printf("%s\n", c_3);
	printf("%s\n", c_4);
	return (0);
}

int		draw_img4(char *pipka)
{
	char	*d_1;
	char	*d_2;
	char 	*d_3;
	char 	*d_4;

	d_1 = ".#\n##\n.#\n";
	d_2 = "#.\n##\n#.\n";
	d_3 = "###\n.#.\n";
	d_4 = ".#.\n###\n";

	printf("%s\n", d_1);
	printf("%s\n", d_2);
	printf("%s\n", d_3);
	printf("%s\n", d_4);
	return (0);
}

int		draw_img5(char *kvad)
{
	char	*e_1;

	e_1 = "##\n##\n";
	printf("%s\n", e_1);
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