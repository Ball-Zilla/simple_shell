                errno = 127;
        }
        return (0);
}

/**
 * builtin_set_env - ..
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_set_env(data_of_program *data)
{
        /* validate args */
        if (data->tokens[1] == NULL || data->tokens[2] == NULL)
                return (0);
        if (data->tokens[3] != NULL)
        {
                errno = E2BIG;
                perror(data->command_name);
                return (5);
        }

        env_set_key(data->tokens[1], data->tokens[2], data);

        return (0);
}

/**
 * builtin_unset_env - ..
 * @data: struct for the program's data'
 * Return: ..
 */
int builtin_unset_env(data_of_program *data)
{
        /* validate args */
        if (data->tokens[1] == NULL)
                return (0);
        if (data->tokens[2] != NULL)
        {
                errno = E2BIG;
                perror(data->command_name);
                return (5);
        }
        env_remove_key(data->tokens[1], data);

        return (0);
}
"builtins.c" 92L, 2015C                                                                                                                     92,1          Bot
