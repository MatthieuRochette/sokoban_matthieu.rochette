/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** draw_game.c
*/

#include "../../include/sokoban.h"

player_t restart_game(char **map, map_t info)
{
    clear();
    print_map_on_screen(map, info);
    return (get_init_pos(map, info));
}