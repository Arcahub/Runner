/*
** EPITECH PROJECT, 2019
** test_database
** File description:
** query
*/

#include <mysql/mysql.h>
#include <stdarg.h>
#include <stdlib.h>

static int my_strlen(const char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

static char *my_strcat(char *dest, char const *src)
{
    int length = 0;
    int length_dest = 0;
    char *res = NULL;

    length = my_strlen(src);
    length_dest = my_strlen(dest);
    res = malloc(sizeof(char) * (length + length_dest + 1));
    for(int i = 0; i < length_dest; res[i] = dest[i], i++)
    for (int i = 0; i < length; i++) {
        res[length_dest  + i] = src[i];
    }
    res[length_dest + length] = '\0';
    return (res);
}

static char *my_strdup(char const *src)
{
    int length;
    char *str;

    length = my_strlen(src);
    str = malloc(sizeof(char) * (length + 1));
    str[length] = '\0';
    for (int i = 0; i <= length; i++) {
        str[i] = src[i];
    }
    return (str);
}

char *make_select_query_str(char *table, unsigned int items, va_list list)
{
    char *query = my_strdup("SELECT ");
    char *arg = 0;

    for (int i = 0; i < items; i++) {
        arg = va_arg(list, char *);
        query = my_strcat(query, arg);
        if (i < items - 1)
            query = my_strcat(query, ", ");
    }
    query = my_strcat(query, " FROM ");
    query = my_strcat(query, table);
    return (query);
}

char ***make_select_query(void *pt, char *table, unsigned int items, ...)
{
    va_list list;
    char *query = 0;
    MYSQL_RES *res = 0;
    char ***res_array = NULL;
    MYSQL *con = (MYSQL *)pt;

    if (items > 0)
        va_start(list, items);
    query = make_select_query_str(table, items, list);
    if (mysql_query(con, "SELECT * FROM scores"))
        printf("%s\n", mysql_error(con));
    else
        res = mysql_store_result(con);
    va_end(list);
    res_array = transform_res_to_array(res);
    return (res_array);
}

char *make_insert_query_str(char *table, unsigned int items, va_list list)
{
    char *query = my_strdup("INSERT INTO \0");
    char *arg = 0;

    query = my_strcat(query, table);
    query = my_strcat(query, " VALUES (");
    for (int i = 0; i < items; i++) {
        arg = va_arg(list, char *);
        query = my_strcat(query, "'");
        query = my_strcat(query, arg);
        query = my_strcat(query, "'");
        if (i < items - 1)
            query = my_strcat(query, ", ");
    }
    query = my_strcat(query, ");");
    return (query);
}

void make_insert_query(void *pt, char *table, unsigned int items, ...)
{
    va_list list;
    char *query = 0;
    MYSQL *con = (MYSQL *)pt;

    if (items > 0)
        va_start(list, items);
    query = make_insert_query_str(table, items, list);
    if (mysql_query(con, query))
        printf("%s\n", mysql_error(con));
    va_end(list);
}