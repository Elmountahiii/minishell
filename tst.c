#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <minishell.h>

int main(int argc, char **argv, char **env)
{
    t_env_list		*env_list;

    env_list = get_env_list(env);
}