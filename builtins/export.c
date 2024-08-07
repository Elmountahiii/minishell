#include "../minishell.h"

void	add_to_env(char	*key, char	*value, t_env_list	**env_list)
{
	t_env_list	*tmp;
	t_env_list	*new_node;
	t_env_list	*last_node;
	// int			exit_stts;
	int			in_list;

	tmp = *env_list;
	last_node = NULL;
	in_list = 0;
	// exit_stts = 0;
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
	// if (procss)
	// 	exit(exit_stts);
}

int count_array_str(char **array)
{
	int i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}

// int check_args(char **args, int *exit_sts, int procss)
// {
// 	char	*key_value;
// 	int 	i;	

// 	i = 1;
// 	while (args[i])
// 	{
// 		if (check_every_arg(args[i], exit_sts))
// 			break;
// 		i++;
// 	}
// 	return i;
// }

void add_every_var(char *key_value, t_env_list **env_list)
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
	add_to_env(key, value, env_list);
}

int	check_every_arg(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (!is_alnum(arg[i]) && arg[i] != '_')
			return 1;
		i++;
	}
	return 0;
}

int check_args(char **args)
{
	int		i;
	char	*key;
	i = 1;
	while (args[i])
	{
		key = ft_substr_orig(args[i], 0, ft_strchr(args[i], '=') - args[i]);
		if (check_every_arg(key))
		{
			free(key);
			return 1;
		}
		free(key);
		i++;
	}
	return 0;
}
// void		ft_export(char	*key_value, t_env_list	**env_list, int procss)
void	ft_export(t_command *command, t_be_executed	*to_execute, int procss)
{
	int			i;
	int			exit_sts;
	t_env_list	**env_list;

	exit_sts = 0;
	i = 1;
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
	if (check_args(command->command_args))
	{
			write(2, "minishell: export: `", 20);
			write(2, "hh@'", 4);
			write(2, ": not a valid identifier\n", 25);
		if (procss)
			exit(1);
		else
		{
			exit_status = 1;
			return ;
		}
	}
	while (command->command_args[i])
	{
		add_every_var(command->command_args[i], to_execute->env_list);
		i++;
	}
	if (procss)
		exit(exit_sts);
}
