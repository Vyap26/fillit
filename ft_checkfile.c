#include "fillit.h"

int     ft_checkstr(char *str)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    if (ft_strlen(str) != 4 || !str)
        return (-1);
    while ((str[i] == '.' || str[i] == '#') && (str[i] != '\0'))
    {
        if (str[i] == '#' && flag == 0)
            flag = 1;
        else if (str[i] != '#' && flag == 1)
            flag = 2;
        if (str[i] == '#' && flag == 2)
            return (-1);
        if (i == 3 && flag == 0)
            flag = 1;
        i++;
    }
    return (0);
}

int    ft_checkv(char **tmp)
{
    int i;
    int j;
    int flag;

    i = 0;
    j = 0;
    flag = 0;
    while (i < 4 && j < 4)
    {
        while (j == 0 && ft_checkstr(tmp[i]) != 0)
            return (-1);
        if (tmp[i][j] == '#' && flag == 0)
            flag = 1;
        else if (tmp[i][j] == '.' && flag == 1)
            flag = 2;
        else if (tmp[i][j] == '#' && flag == 2)
            return (-1);
        i++;
        if (i == 4 && j < 3)
        {
            i = 0;
            flag = 0;
            j++;
        }
    }
    //if (flag == 0)
    //   return (-1);
    return (0);
}
// int     figure_out(int **res)
// {
//     int i;
//     int j;

//     while (j < 4)
//     {
        
//     }
// }