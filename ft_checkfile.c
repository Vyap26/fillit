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
    return (0);
}
void    ft_cutrow(char **tmp)
{
    int i;
    int k;

    i = 0;
    k = 3;

    while (i <= k)
    {
        if (ft_strcmp(tmp[i], "....") == 0)
        {
            ft_putstr ("found spare\n"); 
            while (i < k)
            {
                ft_strcpy(tmp[i], tmp[i + 1]);
                i++;
            }
            ft_strclr(tmp[k]);
            i = 3 - k;
            if (strcmp(tmp[i], "...."))
                k--;
        }
        else
            i++;
    }
}

void    ft_cutcol(char **tmp)
{
    int i,j;

    i = 0;
    j = 0;
    while (j < 3)
    {
        if (tmp[0][j] != '#' && tmp[1][j] != '#' && tmp[2][j] != '#' && 
        tmp[3][j] != '#')
        {
            while (i < 4 && j < 1)
            {
                tmp[i][j] = tmp[i][j + 1];
                i++;
            }
            i = 0;
        }
        else
            j++;
        
    }
}

int ft_checkfile(int fd)
{
    int ret;
    char *line;
    char *tmp[4];
    char *res;
    int fig;
    int i;
    int j;

    ret = get_next_line(fd, &line);
    i = 0;
    while (ret > 0)
    {
        tmp[i] = ft_strdup(line);//filling array with checked strings
        i++;
        if (i == 4)
        {
            if (ft_checkv(tmp) == -1)
                return (-1);
            ft_cutrow(tmp);
            ft_cutcol(tmp);
            j = 0;
            while (j < 4)
                {
                    ft_putstr(tmp[j]);
                    ft_putchar('\n');
                    j++;
                }
            fig =  0;//figure_out(tmp);//decode the array to it's contains figure
            i = 0;
            //here will be a function that put the figure to array
            //free the tmp
            //ft_putchar('\n'); 
            if (get_next_line(fd, &line) == 1 && *line != '\0') // if i==4 && (line[0] != '\0' && ret == 0) mean an error
                return (-1);
        }
        free(line);
        if (ret != 0)
            ret = get_next_line(fd, &line);
    }
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