#include "../minishell.h"



void	our_export(char	*key, char	*value, t_env_list	*env_list)
{
	t_env_list	*tmp;
	t_env_list	*new_node;
	t_env_list	*last_node;
	int			in_list;

	tmp = env_list;
	last_node = NULL;
	in_list = 0;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key))
		{
			in_list = 1;
			free(tmp->value);
			tmp->value = value;
		}
		if (!(tmp->next))
			last_node = tmp;
		tmp = tmp->next;
	}
	if (!in_list)
	{
		new_node = malloc(sizeof(t_env_list));
		new_node->value = ft_strdup(value);
		new_node->key = ft_strdup(key);
		// maybe just work with the params key and value wihtout ft_strdup
		new_node->next = NULL;
		last_node->next = new_node;
	}
}
