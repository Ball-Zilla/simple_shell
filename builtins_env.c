#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "shell.h"

/**
 * builtin_env - 
 * @data: struct for the program's data
 * Return: Zero if success, or an error number if an issue occurs.
 */
int builtin_env(data_of_program *data){
	if (data->tokens[1] == NULL)
		return (0);
	return 0;
}


/**
 * builtin_set_env - Set an environment variable.
 * @data: struct for the program's data
 * Return: Zero if success, or an error number if an issue occurs.
 */
int builtin_set_env(data_of_program *data) {
    if (data->tokens[1] == NULL || data->tokens[2] == NULL) {
        return 0;
    }

    if (data->tokens[3] != NULL) {
        errno = E2BIG;
        perror(data->command_name);
        return 5;
    }

    env_set_key(data->tokens[1], data->tokens[2], data);

    return 0;
}

/**
 * builtin_unset_env - Unset an environment variable.
 * @data: struct for the program's data
 * Return: Zero if success, or an error number if an issue occurs.
 */
int builtin_unset_env(data_of_program *data) {
    if (data->tokens[1] == NULL) {
        return 0;
    }

    if (data->tokens[2] != NULL) {
        errno = E2BIG;
        perror(data->command_name);
        return 5;
    }

    env_remove_key(data->tokens[1], data);

    return 0;
}
