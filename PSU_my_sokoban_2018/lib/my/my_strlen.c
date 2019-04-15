/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** test
*/

int my_strlen(char const *str)
{
    int i = 0;
    char c = str[i];

    while (c != '\0') {
        i ++;
        c = str[i];
    }
    return (i);
}