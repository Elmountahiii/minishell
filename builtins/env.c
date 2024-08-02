#include "../minishell.h"

int	our_env(t_env_list	*envp, int procss)
{
	int exit_sts;

	exit_sts = 0;
	while (envp)
	{
		if (envp->value)
		{
			printf("%s=", envp->key);
			printf("%s\n", envp->value);
		}
		envp = envp->next;
	}
	if (procss)
		exit(exit_sts);
	return 0;
}
