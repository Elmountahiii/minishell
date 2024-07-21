#include "../minishell.h"

int our_cd(char **path)
{
    // printf("%s\n", getcwd(NULL, 0));
	chdir(path);
	// printf("%s\n", getcwd(NULL, 0));
	return 1;
}

