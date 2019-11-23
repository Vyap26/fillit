#define sqare 1
#define stick 2
#define Tsign 3
#define Ssign 4
#define Gsign 5

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
        if (str[i] == '#')
            flag = 1;
        else if (str[i] != '#' && flag == 1)
            flag = 2;
        else if (str[i] == '#' && flag == 2)
            return (-1);
        else if (i == 3 && flag == 0)
            flag = 1;
        i++;
    }
    if (flag == 1 || flag == 2)
        return (0);
    return (-1);
}
// int     figure_out(int **res)
// {
//     int i;
//     int j;

//     while (j < 4)
//     {
        
//     }
// }

char    ft_fillit(int fd)
{
    int ret;
    int res[4];
    char line[5];
    char *tmp[5];
    int fig;
    int i;
    char c;

    ret = get_next_line(fd, &line);
    i = 0;
    while(ret > 0)
    {
        c = ft_checkstr(line); //checking the srting for false symbols and it's repeating
        //it will return 0 if the string content only allowed symbols in correct order
        if (c == -1)
            return ("not a valid file");
        else
            tmp[i] = ft_strdup(line);//filling array with checked strings
        i++;
        
        if (i == 5)
        {
            fig = figure_out(tmp);//decode the array to it's contains figure
            tmp[i] = '\0';
            i = 0;
            //here will be a function that put the figure to array
            //free the tmp
        }
        //free the line
        ret = get_next_line(fd, &line);
    }
}

void    main(void)
{
    char    *res;
    int     fd;

    fd = open(fd, 0, O_RDONLY);
    res = ft_fillit(fd);
    if (res)
        ft_putstr(res);
    return (0);
}