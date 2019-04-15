/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** event_management.c
*/

#include "../../include/sokoban.h"

int move_in_axis(char side)
{
    if (side == 'u' || side == 'l') {
        return (-1);
    } else {
        return (1);
    }
}

void move_player(player_t *player, char side)
{
    int old[2] = {player->x, player->y};

    move(player->y, player->x);
    if (side =='u' || side == 'd') {
        if (is_an_obstacle(player, side) == 0) {
            player->y += move_in_axis(side);
            move_boxes(player, player->x, player->y, side);
            draw_pos_player(player, old);
        }
    } else if (side == 'l' || side == 'r') {
        if (is_an_obstacle(player, side) == 0) {
            player->x += move_in_axis(side);
            move_boxes(player, player->x, player->y, side);
            draw_pos_player(player, old);
        }
    }
}