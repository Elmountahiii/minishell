#include "../minishell.h"

int	ft_str_chr_index(char *s, char c)
{
	int	i;
	int	length;

	i = 0;
	if (!s)
		return (-1);
	length = ft_strlen(s);
	while (i <= length)
	{
		if (s[i] == ((char)c))
			return (i);
		i++;
	}
	return (-1);
}

void our_export(char	*var, t_env_list	*env_list)
{
	t_env_list	*tmp;
	t_env_list	*new_node;
	t_env_list	*last_node;
	int			in_list;
	int			equal_index;

	tmp = env_list;
	last_node = NULL;
	in_list = 0;
	equal_index = ft_str_chr_index(var, '=');
	if (equal_index < 0)
	{
		write(2, "no equal sign\n", 14);
		return ;
	}
	while (tmp)
	{
		if (!ft_strncmp(var, tmp->variable, equal_index))
		{
			in_list = 1;
			free(tmp->variable);
			tmp->variable = ft_strdup(var);
		}
		if (!(tmp->next))
		{
			last_node = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	if (!in_list)
	{
		new_node = malloc(sizeof(t_env_list));
		new_node->variable = var;
		new_node->next = NULL;
		last_node->next = new_node;
	}
}
