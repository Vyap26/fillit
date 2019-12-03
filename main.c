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

t_tetra *fill_mass()
{
	static t_tetra	*mass;
	t_tetra			*temp;
	t_tetra			*abr;
	int 			count;
	char 			*all;
	char 			*name1;
	char 			*name2;
	char			*name3;

	name1 = "a_1";
	name2 = "a_2";
	name3 = "b_1";
		count = 0;
	if (mass == NULL)
		mass = new_tetra(name1);
	temp = mass;

	temp->img = "#\n#\n#\n#\n";
	temp->num = 0;
	printf("%s\n", temp->name);
	printf("%s\n", temp->img);
	temp->next = new_tetra(name2);
	temp = temp->next;
	temp->img = "####\n";
	temp->num = 0;
	printf("%s\n", temp->name);
	printf("%s\n", temp->img);
	temp->next = new_tetra(name3);
	temp = temp->next;
	temp->img = "##\n#.\n#.\n";
	temp->num = 0;
	printf("%s\n", temp->name);
	printf("%s\n", temp->img);
	printf("%s\n", mass->img);

	abr = mass;
	while (ft_strcmp(abr->name, name2) != 0)
		abr = abr->next;
	abr->num = abr->num + 1;
	printf("%s\n", abr->name);
	printf("%s\n", abr->img);
	printf("%d\n", abr->num);
	return (mass);

}


//if abr->img == nashla() //тут мы ищем совпадение
//	return abr->name; //возвращаем имя фигуры совпавшей
//
//void	num_plus(*imya) //сюда это имя совпавшее загоняем и прибавляем кол-во фигур в списке
//{
//	while (ft_strcmp(abr->img, imya) != 0)
//		abr = abr->next;
//	abr->num = abr->num + 1;
//}
//

char	opr_pole(t_tetra *mass)
{
	char 	*pole; //заводим поле
	t_tetra	*abc;

	abc = mass; // Определения самой здоровой фиггуры
	while (abc->next)

		if (abc->num < 1)
			abc = abc->next;
		else if (abc->name[0] == 'a')
			pole = "....\n....\n....\n....\n";
		else if (abc->name[0] != 'd')
			pole = "...\n...\n...\n";
		else
			pole = "..\n..\n";
	return(pole);
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
//	fill_mass();
	return (0);
}
/*
 * 1) Есть ли большая фигура (по имени) - определяет начальную сторону квадрата
 * 2) Пока общее кол-во фигур больше нуля, то выполняем в цикле
 *  - входит ли вторая по размеру фигуроа в квадрат определеный размеров первой фигуры
 *  	- если да - ок (пишем),
 *  	- если нет - пока не войдет в квадрат, сторона квадрата +1
 */
/* если у нас есть поле, заданное поиском поля от 1 фигуры, то главная задача разместить фигурку слева сверху
 *
 */

char	*ready_pole(char *pole, t_tetra *mass)
{
	char *red_pole;



	return(red_pole);
}
/*
так выглядит поле 4 на 4
....
....
....
....
так оно записано
"....\n....\n....\n....\n"

так записана фигура, которую надо вписать

"####\n"

так должен выглядеть результат

"####\n....\n....\n....\n"


 а вот другая фигура
 #.
 ##
 .#

  "#.\n##\n.#\n"

 а вот строка с первой фигурой
 "####\n....\n....\n....\n"

 то есть в строках фигуры и поля не обязательно должны совпадать \n, важно совпадение символов с начала строки в каждой
 строке, то есть условно для буквы Г в 20 на 20, если она рисуется с 5 места в верхней строке, должны быть свободны
 1-5, 1-6
 2-5
 3-5
 то есть считаем символы от начала каждой строки
 то есть
 если длина Х, а высота У и начало (левый верхний угол это у-х),
 то буква Г
 (y, x +4) (y, x +5)
 (y + 1, x +4)
 (y + 2, x +4)


 если это применительно к строке длинной привести
 то у - кол-во \n равно 0
 у + 1 - колво \n равно 1 и т/д/

 x = кол-во символов с начала строки и после каждого /n

каждый раз я должен проверить координаты 4 точек из которых состоит фигурка

 каждая точка имеет 2 координаты х и у
 перемещенеие это прибавление к х или у единички СРАЗУ у всех точек



 например фигура Г
 (1 + х, 1 + у), (2 + х, 1 + у)
 (1 + х, 2 + у)
 (1 + х, 3 + у)

 таким образом увеличивая х или у на 1 мы сдвигаем всю фигурку




 и если ок то заполнить их а если не ок пододвинуться дальше и опять проверить их все и так идти
 потом еслиок переходим на следующую фигурку



 в конце надо будет изменить алгоритм так? что мы вписываем 1 фигурку и потом вписываем следующую если она нет то
 следующую фигурку и только потом двигаемся если ок
 если не ок (в поле не входит) первой ставим вторую и т/д/


1) функция подсчета \n
2) функция подсчета символов в строке

*/

