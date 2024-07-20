#include "../minishell.h"

int main(int argc, char* argv[], char* envp[])
{
    (void)argc;
    (void)argv;
    t_env_list *list = get_env_list(envp);
    print_env_list(list);
    printf("\n");
    // our_export("USER", "anwar ettaleb", list);
    our_unset("_", &list);
    print_env_list(list); 
}
