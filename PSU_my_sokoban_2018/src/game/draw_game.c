/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** draw_game.c
*/

#include "../../include/sokoban.h"

void print_map_on_screen(char **map, map_t info)
{
    int x = getmaxx(stdscr);
    int y = getmaxy(stdscr);
    int print_y = y / 2;
    int print_x = x / 2 - my_strlen(ENLARGE_WINDOW) / 2;

    if (x < info.width || y < info.height) {
        mvprintw(print_y - 1, print_x, ENLARGE_WINDOW);
        mvprintw(print_y, print_x - 1, ENLARGE_MIN_SIZE, x, y);
    } else {
        for (int i = 0; i != info.height; i++) {
            printw(map[i]);
            printw("\n");
        }
    }
}

void move_boxes(player_t *p, int x, int y, char side)
{
    char test_box = mvinch(p->y, p->x);

    if (test_box == 'X') {
        switch(side) {
            case 'u':
                mvaddch(y - 1, x, 'X');
                break;
            case 'd':
                mvaddch(y + 1, x, 'X');
                break;
            case 'l':
                mvaddch(y, x - 1, 'X');
                break;
            case 'r':
                mvaddch(y, x + 1, 'X');
                break;
        }
    }
}

void draw_pos_player(player_t *p, int *old)
{
    mvaddch(old[1], old[0], ' ');
    mvaddch(p->y, p->x, 'P');
}

void fix_target_draw(char **map, map_t info)
{
    for (int i = 0; i < info.height; i++) {
        for (int j = 0; j < info.width; j++) {
            mvinch(i, j) == 32 && map[i][j] == 'O' ?
                mvaddch(i, j, 'O') : 0;
        }
    }
}

void launch_window(char **map, map_t info, player_t player)
{
    int input;
    int test = 1;

    initscr();
    keypad(stdscr, TRUE);
    print_map_on_screen(map, info);
    noecho();
    curs_set(0);
    while (test != 0) {
        test = game_is_won(map, info);
        refresh();
        input = getch();
        if (input == 32 && test != 0)
            player = restart_game(map, info);
        if (test != 0) {
            test = event_management(input, &player);
            fix_target_draw(map, info);
        }
        refresh();
    }
    end_game();
}