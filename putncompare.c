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
            str[s++] = '\\';
            str[s++] = 'n';
            i++;
            j = 0;
        }
        if (tmp[i][0] == '\0')
            break ;
    }
    str[s] = '\0';
}

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

t_tetra *ft_filllst()
{
    static t_tetra *fllt;
    t_tetra *temp;
    int fd;
    int res;
    char *buf;

    fllt = new_tetra("a_1");
    temp = fllt;
    fd = open("samples.txt", O_RDONLY);
    res = get_next_line(fd, &buf);
    while (res > 0)
    {
        temp -> name = (ft_strdup(buf));
        res = get_next_line(fd, &buf);
        if (res <= 0)
            break ;
        temp -> img = (ft_strdup(buf));
        ft_strclr(buf);
        res = get_next_line(fd, &buf);
        if (res <= 0)
            break ;
        temp -> next = new_tetra("");
        temp = temp -> next;
    }
    return (fllt);
}
int ft_compare(char *str, t_tetra *smpl)
{
    while (ft_strcmp(smpl->img, str) != 0)
		{
            ft_putstr("scan...\n");
            printf("%s\n", smpl->img);
            smpl = smpl->next;
            if (smpl == NULL)
                return (-1);
        }
    smpl->num = smpl->num + 1;
    ФУНКЦИЯ МОЯ ЛЮБИМАЯ! где надо положить smpl->img с нормальными \n
    ft_putstr("match!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    return (0);
}