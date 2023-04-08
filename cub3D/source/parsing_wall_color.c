#include "../include/struc.h"

int put_wall_in_struct(t_data *data, int i)
{ // met les murs dans la structure
    char **str = ft_split(data->map[i], ' ');
    if (str[2])
        return (ft_print_error("Error\nProbleme de textures", NULL));
    if (!ft_strncmp(data->map[i], "NO ", 3))
        data->NO = ft_strdup(str[1]);
    if (!ft_strncmp(data->map[i], "SO ", 3))
        data->SO = ft_strdup(str[1]);
    if (!ft_strncmp(data->map[i], "WE ", 3))
        data->WE = ft_strdup(str[1]);
    if (!ft_strncmp(data->map[i], "EA ", 3))
        data->EA = ft_strdup(str[1]);
    free_tab(str);
    return (0);
}

int is_color_legit(t_data *data, char letter)
{
    if (letter == 'F') // Je verifie que tous les nombres sont entre 0 et 255
    {
        if (data->f1 < 0 || data->f2 < 0 || data->f3 < 0 || data->f1 > 255 || data->f2 > 255 || data->f3 > 255)
            return (ft_print_error("Error\nProbleme de couleurs", NULL));
         else
            data->floor_color= (data->f1 << 16) | (data->f2 << 8) | (data->f3);
    }
    if (letter == 'C')
    {
        if (data->c1 < 0 || data->c2 < 0 || data->c3 < 0 || data->c1 > 255 || data->c2 > 255 || data->c3 > 255)
        {
            return (ft_print_error("Error\nProbleme de couleurs", NULL));
        }
        else
            data->ceil_color= (data->c1 << 16) | (data->c2 << 8) | (data->c3);
    }
    return (0);
}

int color_to_struct(t_data *data, char **tab, char letter)
{

    if (letter == 'F')
    {
        data->colorF += 1;
        data->f1 = ft_atoi(tab[0]);
        data->f2 = ft_atoi(tab[1]);
        data->f3 = ft_atoi(tab[2]);
         if (is_color_legit(data, 'F'))
            return (1);
    }
    if (letter == 'C')
    {
        data->colorC += 1;
        data->c1 = ft_atoi(tab[0]); // j'ai changé mon atoi de la libft, il renvoie -1 si tab[]
        data->c2 = ft_atoi(tab[1]); // possede autre chose qu'un chiffre et on ne peut plus ecrire +++--[lenombre] par exemple
        data->c3 = ft_atoi(tab[2]); 
        if (is_color_legit(data, 'C'))
            return (1);
    }
    return (0);
}


int get_color(t_data *data, int i)
{
    char **str = ft_split(data->map[i], ' '); // je split d'abord "C 1,1,1" avec l'espace pour me debarasser de la lettre
    char **tab = ft_split(str[1], ','); // je split les couleurs avec ',' pour isoler les 3 separement

    if (tab[3] || str[2]) // je fais planter le quelqu'un a rajouter du texte derriere les couleurs
    {
        free_tab(str);
        free_tab(tab);
        return (ft_print_error("Error\nProbleme de couleurs", NULL));
    }
    if (!ft_strncmp(data->map[i], "F ", 2))
        color_to_struct(data, tab, 'F');
    else
        color_to_struct(data, tab, 'C');
    
    free_tab(str);
    free_tab(tab);
    return (0);
}