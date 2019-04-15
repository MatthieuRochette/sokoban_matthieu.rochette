/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** event_management.c
*/

#include "../../include/sokoban.h"

int check_depend_on_side(player_t *p, char side, char *obst)
{
    char c;

    switch (side) {
        case 'u':
            c = mvinch(p->y - obst[0], p->x);
            break;
        case 'd':
            c = mvinch(p->y + obst[0], p->x);
            break;
        case 'l':
            c = mvinch(p->y, p->x - obst[0]);
            break;
        case 'r':
            c = mvinch(p->y, p->x + obst[0]);
            break;
    }
    if (c == obst[1])
        return (1);
    return (0);
}

int is_an_obstacle(player_t *p, char side)
{
    char obst[2] = {1, '#'};
    int wall = check_depend_on_side(p, side, obst);

    if (wall == 0) {
        obst[1] = 'X';
        wall = check_depend_on_side(p, side, obst);
    } else
        return (1);
    if (wall == 1) {
        obst[0] = 2;
        wall += check_depend_on_side(p, side, obst);
        obst[1] = '#';
        wall += check_depend_on_side(p, side, obst);
    } else
        return (0);
    if (wall == 1)
        return (0);
    return (wall);
}