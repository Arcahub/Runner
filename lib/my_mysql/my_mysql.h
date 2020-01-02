/*
** EPITECH PROJECT, 2019
** test_database
** File description:
** my_mysql
*/

#include <mysql/mysql.h>

#ifndef MY_MYSQL_H_
#define MY_MYSQL_H_
char ***make_select_query(void *, char *, unsigned int, ...);
void make_insert_query(void *, char *, unsigned int, ...);
char ***transform_res_to_array(MYSQL_RES *);
void *make_mysql(char *, char *, char *, char *);
void my_mysql_close(void *);
#endif /* !MY_MYSQL_H_ */
