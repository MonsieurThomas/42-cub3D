#include "../include/struc.h"

int check_around_each_zero(t_data *data, int i, int j)
{
    if (data->map[i-1][j] != '1' && data->map[i-1][j] != '0')
        return (ft_print_error("Error\nProbleme de carte", NULL));
    if (data->map[i+1][j] != '1' && data->map[i+1][j] != '0')
        return (ft_print_error("Error\nProbleme de carte", NULL));
    if (data->map[i][j+1] != '1' && data->map[i][j+1] != '0')
        return (ft_print_error("Error\nProbleme de carte", NULL));
    if (data->map[i][j-1] != '1' && data->map[i][j-1] != '0')
        return (ft_print_error("Error\nProbleme de carte", NULL));
    return (0);
}

int check_whole_frontier(t_data *data)
{
    int i = 0;
    while (data->map[0][i])
    {
        if (data->map[0][i] == '0')
            return (ft_print_error("Error\nProbleme de carte", NULL));
        i++;
    }

    i = 0;
    while (data->map[i])
    {
        if (data->map[i][0] == '0' || data->map[i][ft_strlen(data->map[i]) - 1] == '0')
            return (ft_print_error("Error\nProbleme de carte", NULL));
        i++;
    }
    i--;
    int j = 0;
    while (data->map[i][j])
    {
        if (data->map[i][j] == '0')
            return (ft_print_error("Error\nProbleme de carte", NULL));
        j++;
    }
    return (0);
}

int is_any_weird_char(t_data *data)
{
    int i = 0;
    int j = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] != '0' && data->map[i][j] != '1' && data->map[i][j] != ' ' && data->map[i][j] != '\n')
                return (ft_print_error("Error\nProbleme de carte", NULL));
            j++;
        }
        i++;
    }
    return (0);

}

int is_frontier_around_zeros(t_data *data)
{
    int i = 0;
    int j = 0;
    if (check_whole_frontier(data)) // je verifie d'abord les frontieres pour etre certain de pas verifier data->map[-1][-1] par exemple quand je regarde autour des '0' par la suite, sans quoi le code voudrait segfault
        return (1);
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == '0')
                if (check_around_each_zero(data, i, j))
                    return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int is_problem_with_map(t_data *data)
{
    if (where_is_player(data))
        return(1);
    if (is_any_weird_char(data))
        return (1);
    change_player_POV(data);
    if (is_frontier_around_zeros(data))
        return (1);
    return (0);
}



int create_new_map(t_data *data, int i)
{ // Dans cette fonction j'isole la carte du fichier .cub, et j'ecrase l'ancienne sauvegarde du tout le fichier pour ni 
// re-ecrire que la carte, donc on perd les walls et la couleur du sol et du plafond parce que je reecris par dessus, mais tout a deja ete sauvegardé 
// dans des variables. C'est bizarre de faire ça je sais, mais j'ai fait tout le raycasting avec la carte directement dans data->map[][] et j'ai pas envie de tout chambouler

    (void) data;
    int j = i;
    char **tab;
    while (data->map[j])
        j++;
    tab = (char **)malloc(sizeof(char *) * (j) + 1);
    j = 0;
    while (data->map[i])
        tab[j++] = ft_strdup(data->map[i++]);
    tab[j] = 0;
    free_tab(data->map);
    data->map = (char **)malloc(sizeof(char *) * ((j) + 1));
    i = -1;
    while (tab[++i])
        data->map[i] = ft_strdup(tab[i]);
    data->map[i] = 0;
    free_tab(tab);
    if (is_problem_with_map(data))
        return (1);
    return (0);
}

int is_beginning_of_map(t_data *data, int i)
{ // je me met a chercher la premiere occurence de '1' des que j'ai 4 murs et 2 couleurs
    int j = 0;

    while (data->map[i][j])
    {
        if (data->map[i][j] == '1')
            return (1);
        j++;
    }
    return (0);
    
}