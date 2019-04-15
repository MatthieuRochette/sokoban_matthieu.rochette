/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** event_management.c
*/

#include "../../include/sokoban.h"

int event_management(int input, player_t *player)
{
    int actions[6] = {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, 27, 32};
    char diff[6] = {'u', 'd', 'l', 'r', 'e', ' '};

    for (int i = 0; i < 6; i++) {
        if (input == actions[i] && i < 4)
            move_player(player, diff[i]);
        else if (input == actions[4]) {
            return (0);
        }
    }
    return (1);
}