/*
** EPITECH PROJECT, 2019
** test_database
** File description:
** my_mysql
*/

#include <mysql/mysql.h>
#include <stdlib.h>
#include <stdio.h>

MYSQL *make_mysql(char * host, char *user, char *passws, char *db)
{
    MYSQL *mysql = mysql_init(NULL);

    if (mysql_real_connect(mysql, host, user, passws, db, 3306, NULL, 0) == NULL) {
        printf("%s\n", mysql_error(mysql));
        return (NULL);
    }
    return (mysql);
}

void my_mysql_close(void *pt)
{
    MYSQL *mysql = (MYSQL *)pt;

    mysql_close(mysql);
}