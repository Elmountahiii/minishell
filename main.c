/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/11 22:10:50 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void	ft_check_leaks(void)
{
	system("leaks minishell");
}
int main(void)
{
	atexit(ft_check_leaks);
	char *line;
	char **split;
	int i = 0;
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			printf("exit\n");
			break;
		}
		add_history(line);
		//printf("line : %s\n", line);
		// printf("count words : %d\n", ft_count_words(line));
		// printf("super count words : %d\n", ft_count_words_v2(line));
		split = ft_lexical_spliter(line);
		while (split[i])
		{
			printf("split[%d] : %s\n", i, split[i]);
			i++;
		}
		ft_free_split(split, i);
		if (ft_strlen(line) > 0 && ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{
			printf("exit\n");
			free(line);
			break;
		}
		free(line);
		 i = 0;
	}
	//rl_clear_history();
	return 0;
}

// int main(void)
// {
// 	// "\"echo | cat\" \'Single quotes $HOME\'>file1.txt|\"cat  | ls  \">"
// 	char *line = "ls\"-la\" | wc -l hello world";
// 	printf("you need to allocate from %d\n", ft_sub_alloc(line));
// 	printf("the first word is %s\n", ft_substr_v2(line, 0));
// 	printf("the second word is %s\n", ft_substr_v2(line, 8));
// 	return 0;
// }

