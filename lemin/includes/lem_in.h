/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:44:24 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/09 10:33:17 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#  include <stdio.h>
# include "error.h"
# include "libft/libft.h"


/*
** STORAGE BATCH SIZES
*/
# define BATCH_MALLOC_SIZE 1000
# define BATCH_PRINT_SIZE 1000
/*
** DICTIONARY
*/
# define HASH_SIZE 10015300
/*
** LINE DEFINES
*/
# define POS_LINE 0
# define POS_X 1
# define POS_Y 2
/*
** PIPE DEFINES
*/
# define NOPE 0
# define CERTAINLY 1
/*
** COMMAND DEFINES
*/
# define COM_DEFAULT 0
# define COM_START 1
# define COM_END 2

/*
** COMMAND LINES
*/
# define START_MK "##start"
# define END_MK "##end"

/*
** ADJACENCY
*/
#define DISCONNECTED -1

typedef enum	e_ln_type
{
	END_OF_READ, ERROR, START, END, NODE, PIPE, COMMENT, ANTS_NB
}				t_ln_type;

typedef struct	s_bucket
{
	int						line_index;
	struct s_bucket			*next;
}				t_bucket;

typedef struct	s_hash_dico
{
	t_bucket		dico_list[HASH_SIZE];
	int				collisions;
}				t_hash_dico;

typedef struct 	s_line_info
{
	char 				*line;
	t_ln_type			type;
	int					hash_key;
	int					line_index;
	int					node_number;
	int					name_len;
	int					pipe[2];
}				t_line_info;

typedef struct	s_storage
{
	t_line_info			entry[BATCH_MALLOC_SIZE];
	t_line_info			output[BATCH_PRINT_SIZE];
	struct s_storage	*next;
}				t_storage;

/*
** The flow of a path can be expressed in fixed turn (initialisation) than (one//var ant per turn)
*/

typedef struct	s_solution
{
	int					*path;
	int					fixed;
/*
**	int					var;
*/
	struct s_solution	*next;
}				t_solution;

typedef struct	s_master
{
	int				ants_nb;
	int				nodes_nb;
	int				command_line;
	int				**adjacency_mtx;
	t_storage		*storage;
	t_storage		*storage_start;
	int				piping;
	t_line_info		*start;
	t_line_info		*end;
	int				lines_nb;
	t_hash_dico		*dico;
}				t_master;

void 				ft_init_mstr(t_master *mstr);
void				ft_exit(t_errors error);

int					ft_dico_hasher_djb2(char *str, char *end, int amplitude);

//int					ft_dico_add(t_hash_dico *dico, char *pos[4]);

void				parser(t_master *mstr);
char				*ft_parser_ants_get(t_master *mstr);
t_ln_type			ft_parser_check_node(char *line, t_ln_type type);
t_ln_type			ft_parser_check_pipe(char *line, t_ln_type type);
t_ln_type			ft_parser_line_type(char *line, int piping);
void				ft_parser_fill_entry_node(t_master *mstr, char *line,
						t_line_info *entry);
void				ft_parser_fill_entry_pipe(t_master *mstr, char *line,
						t_line_info *entry);
void				ft_parser_apply_command(t_master *mstr, t_line_info *entry);

void				ft_storage_grow(t_master *mstr);
t_ln_type 			ft_storage_add_line(char *line, t_master *mstr);
t_line_info			*ft_storage_get_line(t_storage *storage_start, int line_nb);
int					ft_dico_add(t_storage *storage_start, t_hash_dico *dico,t_line_info *entry);
int					ft_dico_get(t_storage *storage_start, t_hash_dico *dico, char *needle, int len);


void				ft_adjacency_matrix_generate(t_master *mstr, t_storage *storage);

#endif
