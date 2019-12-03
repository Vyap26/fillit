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
        {
            str[s] = tmp[i][j];
            s++;
            j++;
        }
        else
            j++;  
        if (j == 3)
        {
            str[s] = '\n';
            s++;
            i++;
            j = 0;
        }
        if (tmp[i][0] == '\0')
            break ;
    }
    str[s] = '\0';
}

t_tetra ft_filllst(char *str)
{
    static t_tetra *fllt;
    t_tetra *temp;
    int fd;
    int res;
    char *buf;

    fillt = (t_tetra *)malloc(sizeof(t_tetra));
    fd = open("samples.txt", O_RDONLY);
    res = get_next_line(fd, &buf);
    while (res > 0)
    {
        fill -> name = (ft_strdup(buf));
        res = get_next_line(fd, &buf);
        if(res <= 0)
            break ;
        fill -> img = (ft_strdup(buf));
        ft_strclr(buf);
        res = get_next_line(fd, &buf);
        if(res <= 0)
            break ;
        
        fill -> next = new_tetra;
    }


}