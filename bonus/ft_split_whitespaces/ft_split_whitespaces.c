#include <stdlib.h>
#include <stdio.h>

int ft_count_all_words(char *str)
{
    int i;
    int words;

    i = 0;
    words = 0;
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            i++;
        words++;
    }
    return (words);
}

int ft_word_length(char *str, int i)
{
    int len;

    len = 0;
    while (str[i])
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            return (len);
        else 
            len++;
        i++;
    }
    return (len);
}

char **ft_split_whitespaces(char *str)
{
    char **tab;
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    if ((tab = (char**)malloc(sizeof(char*) * ft_count_all_words(str) + 1)) == NULL)
        return (0);
    while (str[i])
    {
        k = 0;
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        if ((tab[j] = (char*)malloc(sizeof(char) * ft_word_length(str, i) + 1)) == NULL)
            return (NULL);
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            tab[j][k] = str[i];
            i++;
            k++;
        }
        tab[j][k] = '\0';
        j++;
    }
    tab[j] = 0;
    return (tab);
}

//"Ana are mere."

int main(int ac, char **av)
{
    char *str;
    char **tab;
    int i;

    //printf("%d\n",ft_count_all_words("Salutare ce se-ntampla"));
    i = 0;
    if (ac != 2)
        return (0);
    str = av[1];
    tab = ft_split_whitespaces(str);
    while (tab[i])
    {
        printf("%s",tab[i]);
        i++;
    }
    printf("\n");
    return (0);
}
