/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** sokoban.h
*/

#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <ncurses.h>
#include "my.h"
#include "functions.h"
#include "struct.h"

#define ENLARGE_WINDOW "Please enlarge your window.\n"
#define ENLARGE_MIN_SIZE "Minimum size required : %d, %d"

void my_sokoban(char **map, map_t s_map);
player_t get_init_pos(char **map, map_t s_map);
void print_map_on_screen(char **map, map_t info);
void launch_window(char **map, map_t info, player_t player);
int event_management(int input, player_t *player);
void end_game(void);

int is_an_obstacle(player_t *p, char side);
void is_a_box(char **map, player_t *p, char side);
void move_player(player_t *player, char side);
void draw_pos_player(player_t *p, int *old);
int check_depend_on_side(player_t *p, char side, char *obst);
void move_boxes(player_t *p, int x, int y, char side);
int game_is_won(char **map, map_t info);
player_t restart_game(char **map, map_t info);

#endif