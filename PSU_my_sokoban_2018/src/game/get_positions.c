/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** get_positions.c
*/

#include "../../include/sokoban.h"

void get_player(char c, int x, int y, player_t *player)
{
    if (c == 'P') {
        player->x = y;
        player->y = x;
    }
}

player_t get_init_pos(char **map, map_t s_map)
{
    player_t player;
    int i;
    int j;

    for (i = 0; i != s_map.height; i++) {
        for (j = 0; j != s_map.width; j++) {
            get_player(map[i][j], i, j, &player);
        }
    }
    return (player);
}