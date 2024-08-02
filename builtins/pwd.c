#include "../minishell.h"

char	*our_pwd(void)
{
	char *pwd;

	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	return (pwd);
}
