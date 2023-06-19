/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-clement.monnoire
** File description:
** my_str_to_wold_array
*/

#include "stdlib.h"
#include "stdio.h"

int nb_string(char *str, char sep)
{
    int nb_string = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep && (str[i + 1] == sep || str[i + 1] == '\0'))
            continue;;
        if (str[i] == sep)
            nb_string++;
    }
    return nb_string + 1;
}

char *malloc_string(char *str, char separator)
{
    int i = 0;
    char *new_str = NULL;

    for (i; str[i] != '\0' && str[i] != separator; i++);
    new_str = malloc(sizeof(char) * (i + 1));
    return new_str;
}

int copy_string(char *src, char *dest, char separator)
{
    int i = 0;

    for (i; src[i] != '\0' && src[i] != separator; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return i - 1;
}

char **my_str_to_word_array(char *str, char separator)
{
    char **array = NULL;
    int nstr = 0;
    int nchar = 0;

    if (!str)
        return NULL;
    while (str[0] == separator)
        str++;
    array = malloc(sizeof(char *) * (nb_string(str, separator) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator)
                continue;
        array[nstr] = malloc_string(str + i, separator);
        i += copy_string(str + i, array[nstr], separator);
        nstr++;
    }
    array[nstr] = NULL;
    return array;
}
