/*
** EPITECH PROJECT, 2022
** bs_myhunter
** File description:
** main
*/
#include "../include/my_hunter.h"

void description (void)
{
    my_printf ("USAGE\n\t./my_hunter\n");
    my_printf ("DESCRIPTION\n");
    my_printf ("\tshoot the ducks\n\tYou have three lives\n");
    my_printf ("ACTIONS\n\tmouse click:\tshoot\n");
    my_printf ("\tSpace:\t\tleave the game\n");
    my_printf ("\tescape:\t\tclose window\n");
}

int main (int argc, char **argv)
{
    if (argc == 1)
        open_window ();
    else if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h'
    && argv[1][2] == '\0')
        description ();
    else {
        write (2, "Bad arguments\n", 14);
        return 84;
    }
    return 0;
}
