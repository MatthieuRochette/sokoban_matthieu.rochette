/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** draw_game.c
*/

#include "../../include/sokoban.h"

int nb_o_left_unfilled(int i, int j, char **map)
{
    if (mvinch(i, j) == 'O' || (map[i][j] == 'O' && mvinch(i, j) == 'P')) {
        return (1);
    }
    return (0);
}

int game_is_won(char **map, map_t info)
{
    int nb_o = 0;
    int i;
    int j;

    for (i = 0; i < info.height; i++) {
        for (j = 0; j < info.width; j++) {
            nb_o += nb_o_left_unfilled(i, j, map);
        }
    }
    if (nb_o == 0) {
        mvprintw(i + 5, j + 11, "YOU WIN !");
        mvprintw(i + 6, j , "Press any key to close the game");
        return (0);
    }
    return (1);
}

void end_game(void)
{
    clear();
    endwin();
}