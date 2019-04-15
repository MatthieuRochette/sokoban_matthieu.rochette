/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** struct.h
*/

#ifndef STRUCT_H
#define STRUCT_H

#include <fcntl.h>
#include <sys/stat.h>
#include <ncurses.h>

#define ERROR "[Error]: "

#define INVALID_SIZE_ERR NULL
#define INVALID_SIZE_ERR_INT 84
#define INVALID_SIZE_MAP ERROR "Invalid map size (equal or less than zero)\n"
#define INVALID_MAP ERROR "The map is not valid.\n"

#define INVALID_SIZE_LINES ERROR "Lines are not all of equal length.\n"
#define SIZE_LINES_ERR 84

#define BAD_STAT ERROR "stat() failed.\nPlease verify your path and your file\n"
#define BAD_ARGS ERROR "Invalid arguments.\nretry with -h.\n"
#define BAD_OPEN ERROR "open() failed.\nPlease check your path / your file.\n"

#define UNMOVABLE_BOX ERROR "At least 1 unmovable box. Impossible to win.\n"

#define SUCCESS 0
#define FAILURE 84

typedef struct s_map {
    int size;
    char *full_map;
    int height;
    int width;
    int fd;
} map_t;

typedef struct s_player {
    int x;
    int y;
} player_t;

#endif