/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** functions.h
*/

#ifndef FCNT_H
#define FCNT_H

#include "struct.h"

#define F_WALL(i) (i != '#' && i != '\0')
#define L_WALL(i, j) (i != '#' && j > 0)
#define OK_IN_MAP(i) (i == 'P' || i == 'O' || i == 'X')

#define CHAR_LIST_1(i) (i != 'P' && i != 'X' && i != '#')
#define CHAR_LIST_2(i) (i != ' ' && i != '\n' && i != 'O')
#define NOT_OK_CHAR(i) (CHAR_LIST_1(i) && CHAR_LIST_2(i))
#define BAD_CHAR ERROR "Bad characters in map.\n"

#define INVALID_WALL ERROR "Wall place is unvalid.\n"
#define NO_WALL_MSG "No walls on at least one line.\n"

#define BAD_NB_PLAYERS ERROR "There can only be one player in the map.\n"
#define BAD_NB_BOX ERROR "Number of boxes not equal to number of targets.\n"

int get_map_err_check(char *map);
void err_size(void);
int check_outside_map(char **map, map_t s_map);
int only_ok_char(char *map);
int check_nb_box(char *map);
int check_movable_box(char **map, map_t s_map);
int check_one_player(char *map);
void print_arg_error(void);

map_t get_map(char *pathname);
char **parse_map_in_lines(map_t map);

#endif