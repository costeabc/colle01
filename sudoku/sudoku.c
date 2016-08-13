#include <stdlib.h>
#include <unistd.h>

int init_table(char **tab)
{
    int i;

    i = 0;
    if ((tab = (char**)malloc(10)) == NULL)
        return (0);
    while (i <= 10)
    {
        if ((tab = (char**)malloc(10)) == NULL)
            return (0);
        i++;
    }
    return (1);
}

void populate_table(char **dest, char **src)
{
    int i;
    int j;

    i = 0;
    while (src[i])
    {
        j = 0;
        while (src[i][j])
        {
            dest[i][j] = src[i][j];
            j++;
        }
        i++;
    }
}

int validate(int ac, char **av)
{
    int i;
    int len;

    i = 0;
    len = 0;
    if (ac != 10)
    {
        write(1, "Erreur\n", 7);
        return (1);
    }
    while (av[ac - 1])
    {
        len = 0;
        while (av[ac - 1][i])
        {
            if (!(av[ac - 1][i] <= '9' && av[ac - 1][i] >= '0'))
            {
                write(1, "Erreur\n", 7);
                return (1);
            }
            len++;
            i++;
        }
        if (len != 9)
            write(1, "Erreur\n", 7);
            return (1);
        ac--;
    }
    return (0);
}

//0 inseamna ca nu e buna valoare
int check(char **tab, char val, int ax, int ay)
{
    int x;
    int y;
    int flag;

    x = 0;
    y = 0;
    flag = 1;
    while (tab[0][x] && tab[0][x] != val)
        x++;
    while (tab[y][0] && tab[y][0] != val)
        y++;
    if (x != 10 || y != 10)
        flag = 0;
    // left here / gotta complete 3x3 square check with ax and ay vars into consideration
}

int main(int ac, char **av)
{
    char **tab;
    int x;
    int y;
    int val;

    if (validate(ac, av))
        return (0);
    if (!init_table(tab))
        return (0);
    populate_table(tab, av);
    val = 0;
    x = 0;
    while (tab[y])
    {
        y = 0;
        while (tab[y][x] && tab[y][x] == '.')
        {
            if(check(tab, val, x, y))
                tab[y][x] = val;
            else 
                val++; // not sure / too tired
            x++;
        }
        y++;
    }
    return (0);    
}
