#include "../minishell.h"

void	print_env_list(t_env_list* list) 
{
	// t_env_list* current = list;
	while (list != NULL)
	{
	    printf("%s\n", list->variable);
	    list = list->next;
	}
}
