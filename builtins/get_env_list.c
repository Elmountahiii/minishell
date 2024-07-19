#include "../minishell.h"

t_env_list	*get_env_list(char **env)
{
	t_env_list	*list;

	list = NULL;
	while (*env)
    {
		// printf("%s\n", *env);      
		add_back_for_env(&list, *env);
		env++;
	}
	return list;
}