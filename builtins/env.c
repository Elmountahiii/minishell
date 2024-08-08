#include "../minishell.h"

void	our_env(t_command *command, t_be_executed	*to_execute, int procss)
{
	t_env_list	*envp;
	int exit_sts;

	exit_sts = 0;
	envp = *to_execute->env_list;
	(void)command;
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
	else	
		exit_status = 0;
	// change the global $?
	return ;
}
