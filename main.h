//
// Created by Maina Kamau on 08/11/2022.
//

#ifndef SIMPLESHELL_MAIN_H
#define SIMPLESHELL_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define LSH_RL_BUFF_SIZE 1024
#define LSH_TOK_BUFF_SIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"




int lsh_cd(char **args);
int lsh_help();
int lsh_exit();
int lsh_launch(char **args);
char **lsh_split_line(char *line);
char *lsh_read_line(void);
void lsh_loop(void);
int lsh_execute(char **args);
int lsh_num_builtins();


#endif //SIMPLESHELL_MAIN_H
