#include <unistd.h>

typedef struct t_env_list
{
	char				*key;
	char				*value;
	struct t_env_list	*next;
}t_env_list;

t_env_list	*get_env_list(char	**env)
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

char **append_to_array(char **array, char *str) {
    int len = 0;

    // Find the length of the array
    while (array && array[len]) {
        len++;
    }

    // Allocate memory for the new array
    char **new_array = (char **)calloc(len + 2, sizeof(char *));
    if (!new_array) {
        return NULL;
    }

    // Copy the old array to the new array
    for (int i = 0; i < len; i++) {
        new_array[i] = strdup(array[i]);
    }

    // Add the new string to the end of the new array
    new_array[len] = strdup(str);

    // Set the last element to NULL
    new_array[len + 1] = NULL;

    // Free the old array
    if (array) {
        free(array);
    }

    return new_array;
}

char	*ft_join_three(char *one, char *two, char *three)
{
	char	*join;
	char	*temp;

	if (!one || !two || !three)
		return (NULL);
	temp = ft_strjoin(one, two);
	join = ft_strjoin(temp, three);
	free(temp);
	return (join);
}

char	**give_array_str(t_env_list *env_list)
{
	char **env;
	char *line;

	env = NULL;
	line = NULL;
	while (env_list)
	{
		line = ft_join_three(env_list->key, "=", env_list->value);
		append_to_array(env, line);
		// don't forget to free the array
		env_list = env_list->next;
	}
	return (env);
}

int main(int ac, char **av, char **env) 
{
	t_env_list		*env_list;
	char			**envp;

	env_list = get_env_list(env);
	envp = give_array_str(env_list);
	char *argv[] = {"/usr/bin/clear", NULL};
	// char *envp[] = {NULL};
	execve(argv[0], argv, envp);
	return 0;
}