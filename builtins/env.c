#include "../minishell.h"

int our_env(t_env_list	*envp)
{
	while (envp)
	{
		if (envp->value)
		{
			printf("%s=", envp->key);
			printf("%s\n", envp->value);
		}
		envp = envp->next;
	}
	return 0;
}
