/*
** EPITECH PROJECT, 2019
** test_database
** File description:
** my_res
*/

#include <mysql/mysql.h>
#include <stdlib.h>

char ***transform_res_to_array(MYSQL_RES *res)
{
    char ***res_array = NULL;
    int nbr_col = mysql_num_fields(res);
    int nbr_row = mysql_num_rows(res);
    MYSQL_ROW row;

    if (nbr_row == 0 || nbr_col == 0)
        return (NULL);
    res_array = malloc(sizeof(char **) * (nbr_row + 1));
    res_array[nbr_row] = NULL;
    for (int i = 0; i < nbr_row; i++) {
        row = mysql_fetch_row(res);
        res_array[i] = malloc(sizeof(char *) * (nbr_col + 1));
        res_array[i][nbr_col] = NULL;
        for (int j = 0; j < nbr_col; j++)
            res_array[i][j] = row[j];
    }
    return (res_array);
}