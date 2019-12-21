#include "fillit.h"

void    ft_putimg(char **tmp, char *str)
{
    int i;
    int j;
    int s;

    i = 0;
    j = 0;
    s = 0;
    while (i < 4)
    {
        if (tmp[i][j] == '.' || tmp[i][j] == '#')
            str[s++] = tmp[i][j++];
        else
            j++;  
        if (j == 3)
        {
            if (tmp[i][j] == '.' || tmp[i][j] == '#')
                str[s++] = tmp[i][j];
            str[s++] = '\n';
            //str[s++] = 'n';
            i++;
            j = 0;
        }
        else if (tmp[i][0] == '\0')
            break ;
    }
    str[s] = '\0';
}

char    *initialiser(int i)
{
    char *arr[19];

    arr[0] = "#\n#\n#\n#\n";
    arr[1] = "####\n";
    arr[2] = "##\n#.\n#.\n";
    arr[3] =  "##\n.#\n.#\n";
    arr[4] = "#.\n#.\n##\n";
    arr[5] = ".#\n.#\n##\n";
    arr[6] = "#..\n###\n";
    arr[7] = "..#\n###\n";
    arr[8]= "###\n..#\n";
    arr[9] = "###\n#..\n";
    arr[10] = "##.\n.##\n";
    arr[11] = ".##\n##.\n";
    arr[12] = "#.\n##\n.#\n";
    arr[13] = ".#\n##\n#.\n";
    arr[14] = ".#\n##\n.#\n";
    arr[15] = "#.\n##\n#.\n";
    arr[16] = "###\n.#.\n";
    arr[17] = ".#.\n###\n";
    arr[18] = "##\n##\n";

    return (arr[i]);
}

int ft_compare(char *str)
{
    int i;

    i = 0;
    while (ft_strcmp(initialiser(i), str) != 0)
		{
//            ft_putstr("scan...\n");
//            printf("%s\n", str);
            i++;
            if (i == 20)
                return (-1);
        }
    //ФУНКЦИЯ МОЯ ЛЮБИМАЯ! где надо положить smpl->img с нормальными \n
//    ft_putstr("match!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    return (0);
}
