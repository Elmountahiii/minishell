#include "../minishell.h"


t_env_list *creat_env_node(char *str)
{
	t_env_list *node;

	node = malloc(sizeof(t_env_list));
	node->variable = ft_strdup(str);
	node->next = NULL;
	return (node);
}

void	add_back_for_env(t_env_list **list, char *str)
{
	t_env_list	*tmp;

	tmp = *list;
	if (!(*list))
	{
		*list = creat_env_node(str);
		return ;
	}
	while (tmp->next) 
		tmp = tmp->next;
	tmp->next = creat_env_node(str);
}