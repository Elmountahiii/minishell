#include "../minishell.h"

void	print_env_list(t_env_list*	list)
{
	// t_env_list* current = list;
	printf("hh\n");
	while (list != NULL)
	{
	    printf("%s=", list->key);
	    printf("%s\n", list->value);
	    list = list->next;
	}
}
