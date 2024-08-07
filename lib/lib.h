/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:38:41 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/12 13:44:01 by yel-moun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

char	*ft_strchr(char *s, int c);
int		ft_strlen(char *str);
int		ft_count_words(char *str);
int		ft_count_words_dil(char *str, char dil);
char	**ft_split_dil(char *str, char dil);
char	**ft_split(char *str);
char	*ft_strnstr(char *haystack, char *needle, int len);
void	ft_print(char *str, int fd);
int		ft_is_space(char c);
void	ft_free_split(char **split, int c);
char	*ft_substr_dil(char *str, int start, char dil);
char	*ft_substr(char *str, int start);
int		ft_split_count(char **split);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_join_three(char *one, char *two, char *three);
char	*ft_strdup(char *s1);
int		ft_is_quote(char c);
int		ft_count_allocation(char *str, int *start);
int		ft_skip_space(char *str, int index);
int		ft_skip_quotes(char *str, int index);
int		ft_count_quote_allocation(char *str, int *start);
void	ft_error_exit(char *message, char *error);
void	ft_command_not_found(char *command);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strcmp(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_is_all_space(char *str);
int     ft_atoi(const char *str);
char	*ft_itoa(int n);

// v2
char	**ft_super_split(char *str);
int		ft_count_words_v2(char *str);
int		ft_is_space_v2(char c);
int		ft_skip_space_v2(char *str, int index);
int		ft_is_metachar(char c);
int		ft_is_append(char c, char *str);
int		ft_is_heredoc(char c, char *str);
int		ft_shift_space(char *str, int index);
int		ft_count_alloc(char *str, int index);
int		ft_count_space(char *str);
int		ft_count_metachar(char *str);
int		ft_count_quotes(char *str);
char	*ft_substr_orig(char *s, unsigned int start, size_t len);
int		ft_strcpy(char *dst, char *src);
int     is_alnum(char c);

#endif