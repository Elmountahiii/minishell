#include "../minishell.h"

int our_env(char	**envp)
{
	while (*envp)
	{
		printf("%s\n", *envp);
		envp++;
	}
	return 0;
}
