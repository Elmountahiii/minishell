#include "minishell.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char	**give_array_pattern(char *pattern)
{
	DIR				*d;
	char			**pattern_strs;
	struct dirent	*dir;
	char			*path;

	if (!ft_strchr(pattern, '*'))
		write(1, "No * in pattern\n", 16);
	else if (pattern == NULL || pattern[0] == '\0')
	{
		write(1, "Pattern is NULL or empty\n", 26);
		return (NULL);
	}
	path = getcwd(NULL, 0);
	d = opendir(path);
	dir = readdir(d);
	pattern_strs = NULL;
	if (d != NULL && dir != NULL)
	{
		while (dir != NULL)
		{
			// if (fnmatch(pattern, dir->d_name))
				pattern_strs = append_to_array(pattern_strs, dir->d_name);
			dir = readdir(d);
		}
	}
	closedir(d);
	return (pattern_strs);
}

int	main(int argc, char **argv, char **env)
{
	char	**strs;

	strs = give_array_pattern("*.c");
	while (*strs)
	{
		printf("%s\n", *strs);
		strs++;
	}
}
