/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** error_manage_2.c
*/

#include "../../include/sokoban.h"

void print_arg_error(void)
{
    write(2, BAD_ARGS, my_strlen(BAD_ARGS));
    exit(FAILURE);
}

int check_one_player(char *map)
{
    int nb_players = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'P')
            nb_players++;
    }
    if (nb_players != 1) {
        write(2, BAD_NB_PLAYERS, my_strlen(BAD_NB_PLAYERS));
        return (84);
    }
    return (0);
}

static int test_not_movable(char **map, int i, int j, map_t s_map)
{
    int left = j == 0 ? 0 : j - 1;
    int right = j == s_map.width ? s_map.width : j + 1;
    int up = i == 0 ? 0 : i - 1;
    int down = i == s_map.height ? s_map.height : i + 1;
    int nb_walls_around = 0;

    if (map[i][j] =='X') {
        nb_walls_around += map[up][j] == '#' ? 1 : 0;
        nb_walls_around += map[i][right] == '#' ? 10 : 0;
        if (nb_walls_around > 10)
            return (1);
        nb_walls_around += map[down][j] == '#' ? 100 : 0;
        if (nb_walls_around >= 110)
            return (1);
        nb_walls_around += map[i][left] == '#' ? 1000 : 0;
        nb_walls_around += map[up][j] == '#' ? 500 : 0;
        if (nb_walls_around >= 1100 || nb_walls_around >= 1501)
            return (1);
    }
    return (0);
}

int check_movable_box(char **map, map_t s_map)
{
    int test = 0;

    for (int i = 0; i < s_map.height; i++) {
        for (int j = 0; map[i][j] != 0; j++) {
            test += test_not_movable(map, i, j, s_map) == 1 ? 1: 0;
        }
        if (test != 0) {
            write(2, UNMOVABLE_BOX, my_strlen(UNMOVABLE_BOX));
            return (84);
        }
    }
    return (0);
}