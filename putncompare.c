#include "fillit.h"

void    ft_putimg(char **tmp, char *res)
{
    int i;
    int j;
    int s;
    char *str;

    str = ft_strnew(10);
    i = 0;
    j = 0;
    s = 0;
    while (i < 4)
    {
        if (tmp[i][j] == '.' || tmp[i][j] == '#')
        {
            str[s] = tmp[i][j];
            s++;
            if (j == 3)
            {
                str[s] = '\n';
                s++;
                i++;
                j = 0;
            }
            else 
                j++;
        }
        else
            j++;
    }
    str[s] = '\0';
    ft_putstr(str);
}