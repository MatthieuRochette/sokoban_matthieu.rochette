/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** main.c
*/

#include "../../include/sokoban.h"

static void print_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, containing");
    my_putstr(" '#' for walls,\n");
    my_putstr("          'P' for the player, 'X' for boxes and 'O' for ");
    my_putstr("storage locations.\n");
}

int check_errors_in_map(char **final_map, map_t s_map)
{
    int error = check_outside_map(final_map, s_map);

    error = error == 0 ? only_ok_char(s_map.full_map) : 84;
    error = error == 0 ? check_nb_box(s_map.full_map) : 84;
    error = error == 0 ? check_movable_box(final_map, s_map) : 84;
    error = error == 0 ? check_one_player(s_map.full_map) : 84;
    return (error);
}

void free_all(map_t s_map, char **final_map)
{
    free(s_map.full_map);
    for (int i = 0; i < s_map.height; i++)
        free(final_map[i]);
    free(final_map);
}

void my_sokoban(char **map, map_t s_map)
{
    player_t player = get_init_pos(map, s_map);
    launch_window(map, s_map, player);
}

int main(int ac, char **av)
{
    map_t raw_map;
    char **final_map;
    int error = 0;

    if (ac != 2) {
        print_arg_error();
    } else if (av[1][0] == '-' && av[1][1] == 'h') {
        print_usage();
    } else {
        raw_map = get_map(av[1]);
        if (raw_map.full_map == NULL || raw_map.size <= 0)
            return (FAILURE);
        final_map = parse_map_in_lines(raw_map);
        error = check_errors_in_map(final_map, raw_map);
        if (error != 0)
            return (FAILURE);
        my_sokoban(final_map, raw_map);
        free_all(raw_map, final_map);
    }
    return (SUCCESS);
}