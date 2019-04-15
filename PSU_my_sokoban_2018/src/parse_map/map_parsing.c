/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** map_parsing.c
*/

#include "../../include/sokoban.h"

static int len_of_file(char *pathname)
{
    struct stat my_stat;
    int file_size = 0;

    if (stat(pathname, &my_stat) == 0) {
        file_size = my_stat.st_size;
    } else {
        write(2, BAD_STAT, my_strlen(BAD_STAT));
        return (-1);
    }
    return (file_size);
}

static char **check_size_lines(char **map, int height)
{
    int j = 0;
    int prev_len = 0;
    int len = 0;

    for (int i = 0; i < height; i++) {
        for (j = 0; map[i][j] != '\0'; j++);
        prev_len = len;
        len = j;
        if (len != prev_len && i != 0) {
            write(2, INVALID_SIZE_LINES, my_strlen(INVALID_SIZE_LINES));
            exit(SIZE_LINES_ERR);
        }
    }
    return (map);
}

map_t get_map(char *pathname)
{
    map_t new;

    new.fd = open(pathname, O_RDONLY);
    if (new.fd == -1) {
        new.full_map = NULL;
        return (new);
    }
    new.size = len_of_file(pathname);
    if (new.size <= 0) {
        write(2, INVALID_SIZE_MAP, my_strlen(INVALID_SIZE_MAP));
        return (new);
    }
    new.full_map = malloc(sizeof(char) * (new.size + 1));
    if (new.full_map == NULL)
        return (new);
    read(new.fd, new.full_map, new.size);
    new.height = get_map_err_check(new.full_map);
    for (new.width = 0; new.full_map[0 + new.width] != '\n'; new.width++);
    return (new);
}

char **go_to_next_char(map_t map, char **tab)
{
    int l_index = 0;
    int c_index = 0;

    for (int i = 0; map.full_map[i] != '\0'; i++) {
        if (map.full_map[i] == '\n') {
            l_index++;
            c_index = 0;
        } else {
            tab[l_index][c_index] = map.full_map[i];
            c_index++;
        }
    }
    return (tab);
}

char **parse_map_in_lines(map_t map)
{
    int i = 0;
    char **temp = malloc(sizeof(char *) * (map.height + 1));
    char **tab = NULL;

    if (temp == NULL)
        return (temp);
    for (i = 0; i < map.height; i++) {
        temp[i] = malloc(sizeof(char) * (map.width + 1));
        if (temp[i] == NULL) {
            temp = NULL;
            return (temp);
        }
    }
    tab = go_to_next_char(map, temp);
    tab = check_size_lines(tab, map.height);
    return (tab);
}