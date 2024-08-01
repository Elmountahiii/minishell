#include "../minishell.h"

int our_cd(char	**path, t_env_list **env)
{
	(void)env;
    // printf("%s\n", getcwd(NULL, 0));
	our_export("OLDPWD", getcwd(NULL, 0), env);
	chdir(path[1]);
	our_export("PWD", getcwd(NULL, 0), env);
	// printf("%s\n", getcwd(NULL, 0));
	return 1;
}

