#include "../minishell.h"

char	*our_pwd(char	**env)
{
	(void)env;
	char *pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	// printf("pwd\n");
	return (pwd);
}
