/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** main.c
*/

#include "../../include/sokoban.h"

static int check_if_out(int pos, char my_char, int f_wall, int l_wall)
{
    if (OK_IN_MAP(my_char)) {
        if (pos < f_wall || pos > l_wall)
            return (1);
    }
    return (0);
}

int check_outside_map(char **map, map_t s_map)
{
    int f_wall;
    int l_wall;
    int out_is_true = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (f_wall = 0; F_WALL(map[i][f_wall]); f_wall++);
        for (l_wall = s_map.width; L_WALL(map[i][l_wall], l_wall); l_wall--);
        if (f_wall == s_map.width || l_wall < 0) {
            write(2, INVALID_MAP, my_strlen(INVALID_MAP));
            write(2, NO_WALL_MSG, my_strlen(NO_WALL_MSG));
            return (FAILURE);
        }
        for (int j = 0; map[i][j] != '\0'; j++) {
            out_is_true += check_if_out(j, map[i][j], f_wall, l_wall);
        }
        if (out_is_true != 0) {
            write(2, INVALID_MAP, my_strlen(INVALID_MAP));
            return (FAILURE);
        }
    }
    return (0);
}

int only_ok_char(char *map)
{
    for (int i = 0; map[i] != '\0'; i++) {
        if (NOT_OK_CHAR(map[i])) {
            write(2, BAD_CHAR, my_strlen(BAD_CHAR));
            return (84);
        }
    }
    return (0);
}

int check_nb_box(char *map)
{
    int nb_box = 0;
    int nb_target = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        nb_box += map[i] == 'X' ? 1 : 0;
        nb_target += map[i] == 'O' ? 1 : 0;
    }
    if (nb_box != nb_target) {
        write(2, BAD_NB_BOX, my_strlen(BAD_NB_BOX));
        return (FAILURE);
    }
    return (0);
}

int get_map_err_check(char *map)
{
    int len = 0;

    for (int i = 0; map[i] != '\0'; i++)
        len += map[i] == '\n' ? 1 : 0;
    if (len <= 0) {
        free(map);
        write(2, INVALID_SIZE_MAP, my_strlen(INVALID_SIZE_MAP));
        exit(INVALID_SIZE_ERR_INT);
    }
    return (len);
}