/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:22:32 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/19 12:00:08 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_back_env(char	*key, char *val, t_env_list **env, t_env_list *last)
{
	t_env_list	*new_node;

	new_node = malloc(sizeof(t_env_list));
	new_node->value = val;
	new_node->key = key;
	new_node->next = NULL;
	if (!last)
		*env = new_node;
	else
		last->next = new_node;
}

void	add_to_env(char	*key, char	*value, t_env_list	**env_list)
{
	t_env_list	*tmp;
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
			free(tmp->value);
			// free(key);
			tmp->value = value;
		}
		if (!(tmp->next))
			last_node = tmp;
		tmp = tmp->next;
	}
	if (!in_list)
		add_back_env(key, value, env_list, last_node);
}

int	check_every_arg(char *arg)
{
	int	i;

	i = 0;
	if (!ft_isalpha(arg[0]) && arg[0] != '_' )
		return (1);
	while (arg[i])
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	add_var(char *key_value, t_env_list **env, int *exit_stt, int procss)
{
	char	*key;
	char	*value;
	char	*equal_ptr;

	equal_ptr = ft_strchr(key_value, '=');
	if (equal_ptr == NULL)
	{
		key = ft_strdup(key_value);
		value = NULL;
	}
	else
	{
		key = ft_substr_orig(key_value, 0,
				ft_strchr(key_value, '=') - key_value);
		value = ft_strdup(ft_strchr(key_value, '=') + 1);
	}
	if (is_in_list(key, *env) && !value)
	{
		free(key);
		return ;
	}
	if (is_in_list(key, *env))
		free(key);
	if (!check_every_arg(key))
		add_to_env(key, value, env);
	else
		error_handler(exit_stt, key, value, procss);
}

void	ft_export(t_command *command, t_be_executed	*to_execute, int procss)
{
	int			i;
	int			exit_sts;
	t_env_list	**env_list;
	char		**args;

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
			exit_status = 0;
	}
	while (args[i])
	{
		add_var(args[i], to_execute->env_list, &exit_sts, procss);
		i++;
	}
	if (procss)
		exit(exit_sts);
}
