#include "../minishell.h"

void	add_to_env(char	*key, char	*value, t_env_list	**env_list)
{
	t_env_list	*tmp;
	t_env_list	*new_node;
	t_env_list	*last_node;
	int			in_list;

	tmp = *env_list;
	last_node = NULL;
	in_list = 0;
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
}

int count_array_str(char **array)
{
	int i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}
int	check_every_arg(char *arg)
{
	int i;

	i = 0;
	if (!ft_isalpha(arg[0]) && arg[0] != '_' )
		return 1;
	while (arg[i])
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return 1;
		i++;
	}
	return 0;
}

void add_every_var(char *key_value, t_env_list **env_list, int *exit_stt, int procss)
{
	char 		*key;
	char 		*value;
	char 		*equal_ptr;

	equal_ptr = ft_strchr(key_value, '=');
	if (equal_ptr == NULL)
	{
		key = key_value;
		value = NULL;
	}else {
		key = ft_substr_orig(key_value, 0, ft_strchr(key_value, '=') - key_value);
		value = ft_strchr(key_value, '=') + 1;
	}
	if (!check_every_arg(key))
		add_to_env(key, value, env_list);
	else
	{
		
		write(2, "minishell: export: `", 20);
		write(2, key, ft_strlen(key));
		write(2, "': not a valid identifier\n", 26);
		if (procss)
		{
			if (*exit_stt == 0)
				*exit_stt = 1;
		}
		else
		{
			if (exit_status == 0)
				exit_status = 1;
		}
	}
}

void	ft_export(t_command *command, t_be_executed	*to_execute, int procss)
{
	int			i;
	int			exit_sts;
	t_env_list	**env_list;
	char 		**args;

	exit_sts = 0;
	i = 1;
	args = command->command_args;
	env_list = to_execute->env_list;
	if (!command->command_args[1])
	{
		ft_export_env(*env_list, procss);
		if (procss)
			exit(0);
		else
		{
			exit_status = 0;
			return ;
		}
	}
	while (args[i])
	{
		add_every_var(args[i], to_execute->env_list, &exit_sts, procss);
		i++;
	}
	if (procss)
		exit(exit_sts);
}
