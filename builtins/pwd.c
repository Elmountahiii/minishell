#include "../minishell.h"

void our_pwd(t_command *command, t_be_executed	*to_execute, int procss)
{
	(void)command;
	(void)to_execute;
	(void)procss;
	char *pwd;

	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	return ;
}
