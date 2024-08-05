/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:53:57 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/05 15:10:41 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	our_exit(int last_proccess_status)
{
	printf("exit\n");
	exit(last_proccess_status);
}