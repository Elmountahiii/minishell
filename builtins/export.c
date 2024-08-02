#include "../minishell.h"

void	our_export(char	*key, char	*value, t_env_list	**env_list, int procss)
{
	t_env_list	*tmp;
	t_env_list	*new_node;
	t_env_list	*last_node;
	int			exit_stts;
	int			in_list;

	tmp = *env_list;
	last_node = NULL;
	in_list = 0;
	exit_stts = 0;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key))
		{
			in_list = 1;
			tmp->value = value;
		}
		if (!(tmp->next))
			last_node = tmp;
		tmp = tmp->next;
	}
	if (!in_list)
	{
		new_node = malloc(sizeof(t_env_list));
		new_node->value = value;
		new_node->key = key;
		new_node->next = NULL;
		if (!last_node)
			*env_list = new_node;
		else
			last_node->next = new_node;
	}
	if (procss)
		exit(exit_stts);
}

void		ft_export(char	*key_value, t_env_list	**env_list, int procss)
{
	char 		*key;
	char 		*value;
	char 		*equal_ptr;
	int			exit_sts;

	exit_sts = 0;
	if (key_value[0] == '=')
	{
		printf("export: `%s': not a valid identifier", key_value);
		return ;
	}
	equal_ptr = ft_strchr(key_value, '=');
	if (equal_ptr == NULL)
	{
		key = key_value;
		value = NULL;
	}else {
		key = ft_substr_orig(key_value, 0, ft_strchr(key_value, '=') - key_value);
		value = ft_strchr(key_value, '=') + 1;
	}
	our_export(key, value, env_list, 0);
	if (procss)
		exit(exit_sts);
}