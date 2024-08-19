#include "../minishell.h"

void	close_other_pipes(t_command	*command, t_pipe *list_pipes)
{
	t_pipe	*tmp;

	tmp = list_pipes;
	while (tmp)
	{
		if (tmp->fd[0] != command->fd_in)
			close(tmp->fd[0]);
		if (tmp->fd[1] != command->fd_out)
			close(tmp->fd[1]);
		tmp = tmp->next;
	}
}
