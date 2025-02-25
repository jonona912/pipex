/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:16:19 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/22 15:38:20 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

# include <string.h>
# include <errno.h>

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_args
{
	char	***cmds;
	char	*here_doc;
	char	*limiter;
	char	*infile;
	char	*outfile;
	char	*cmd_path;
	int		cmd_cnt;
}	t_args;

typedef struct s_pipes
{
	int	pp1[2];
	int	pp2[2];
	int	temp_pp[2];
}	t_pipes;

typedef enum s_hd
{
	NOT_HERE_DOC,
	IS_HERE_DOC
}	t_hd;

typedef enum s_is_str
{
	MK_INFILE,
	MK_OUTFILE
}	t_is_str;

typedef struct s_split
{
	size_t	params;
	char	**ret;
	size_t	i;
	size_t	wl;
}	t_split;

// arg_split_helper_1.c
int		ppx_arg_len(char **argv);
char	*ppx_point_word(char const *s, char c);
char	*end_of_quote(char const *s, char *c_ignores);
size_t	count_cmd_param(char const *s, char c, char *c_ignores);
size_t	ppx_word_len(char const *s, char c, char *c_ignores);

// arg_split_helper_2.c
int		ppx_split_free(char ***str, int len);
char	**ppx_split(char const *s, char c, char *c_ignores);
size_t	ppx_strlen(char const *s, char *c_ignores);
char	*ppx_strdup(char *src, char *c_ignores);
int		make_here_doc_str(char ***argv, t_args *p_args);

// arg_split.c
int		make_in_out_file( char ***argv, t_args *p_args, int i, t_is_str make);
// void	ppx_free_perror(t_args *p_args, char *str);
int		ppx_arg_split(char **argv, t_args *p_args, char c);

// cmd_exec_1.c
int		execute_cmd(int read, int write, char **cmd, t_args *p_args);
int		set_pipes(t_pipes *pipes, int is_pp1);
void	execute_cmd_struct(t_pipes *pipes, t_args *p_args);
int		infile_pipe(t_pipes pipes, t_args *p_args);

// cmd_exec_2.c
char	**make_cat_argv(char *str);
int		infile_pipe_helper(t_pipes pipes, t_args *p_args, char ***cat);

// ppx_errors.c
int		ppx_print_error_cmd(char **cmds);
int		ppx_command_not_found(char **cmds, char **path);
void	ppx_free_perror(t_args *p_args, char *str);
void	ppx_print_error(t_args *p_args, char *str);

// ppx_free_meme.c
int		ppx_free_t_args_hlp(t_args *p_args);
int		ppx_free_t_args(t_args *p_args);

#endif
