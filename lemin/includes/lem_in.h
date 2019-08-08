/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:20:16 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/08 09:25:40 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

//
# include <stdio.h>
//
# include "error.h"

/*
** STORAGE BATCH SIZES
*/

# define BATCH_MALLOC_SIZE 50000
# define BATCH_PRINT_SIZE 1000000

/*
** DICTIONARY
*/

# define HASH_SIZE 100153

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
# define CONFIRMED 2

/*
** DFS DEFINE
*/

# define DEAD_END 0
# define SUCCESS 1

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
# define DISCONNECTED -1
# define INACTIVE 1
# define ACTIVATED 2

/*
** AJACENCY OPTIONS
*/

# define A_OPTIONS 15

# define A_LINKS_NB 0
# define A_LOADED 1
# define A_LINE_INDEX 2
# define A_ANT 3
# define A_ANT_HIST 4
# define A_STORED_SOLUTION 5
# define A_CURRENT_SOLUTION 6
# define A_STORED_PATH_LEN 7
# define A_CURRENT_PATH_LEN 8
# define A_VISIT_FLOW 9
# define A_VISIT_BACKFLOW 10
# define A_PARENT_FLOW 11
# define A_LOADED_FINDER 12
# define A_PATH_NUMBER 13
# define A_SOLUTION_START 14

/*
** FLOW TYPE
*/

# define F_FLOW 1
# define F_BACKFLOW -1

typedef enum	e_ln_type
{
	END_OF_READ, ANTS, ERROR, START, END, NODE, PIPE, COMMENT
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

typedef struct	s_line_info
{
	char				*line;
	t_ln_type			type;
	int					hash_key;
	int					line_index;
	int					node_number;
	int					name_len;
	int					pipe[2];
	int					active_pipe;
}				t_line_info;

typedef struct	s_storage
{
	t_line_info			entry[BATCH_MALLOC_SIZE];

	struct s_storage	*next;
}				t_storage;

typedef struct	s_master
{
	int				ants;
	int				nodes;
	int				pipes;
	int				inactives_pipes_nb;
	int				max_flow;
	int				command_line;
	int				**adjacency_mtx;
	int				*node_queue;
	int				*node_path;
	int				*node_parents;
	int				*stored_solution;
	t_storage		*storage;
	t_storage		*storage_start;
	t_hash_dico		*dico;
	int				piping;
	t_line_info		*start;
	t_line_info		*end;
	int				lines_nb;
	int				buffer_pos;
	int				turn_counter;
	int				end_of_search;
	int				final_flow;
	int				skip;
	int				line_started;
	char			output[BATCH_PRINT_SIZE + 1];
	int				output_type;
	int				fringe_start_end;
	int				ants_nb_modified;
}				t_master;

/*
** INIT AND EXIT
*/

void			ft_init_mstr(t_master *mstr);
void			ft_option_get(t_master *mstr, int argc, char **argv);
void			ft_exit(t_errors error, t_master *mstr);
void			ft_free_everything(t_master *mstr);

//
//# include "debug.h"
//

/*
** PARSER PROTOTYPES
*/

void			parser(t_master *mstr);
void			ft_parser_ants_get(t_master *mstr, char *line, int activation);
t_ln_type		ft_parser_check_node(char *line, t_ln_type type);
t_ln_type		ft_parser_check_pipe(char *line, t_ln_type type);
t_ln_type		ft_parser_line_type(char *line, int piping);
void			ft_parser_fill_entry_node(t_master *mstr, char *line,
					t_line_info *entry);
void			ft_parser_fill_entry_pipe(t_master *mstr, char *line,
					t_line_info *entry);
void			ft_parser_apply_command(t_master *mstr, t_line_info *entry);

/*
** STORAGE PROTOTYPES
*/

void			ft_storage_grow(t_master *mstr);
t_ln_type		ft_storage_add_line(char *line, t_master *mstr);
t_line_info		*ft_storage_get_line(t_master *mstr, int line_nb);
void			ft_dico_add(t_master *mstr,
								t_hash_dico *dico, t_line_info *entry);
int				ft_dico_get(t_master *mstr,
								t_hash_dico *dico, char *needle, int len);

/*
** MATRIX PROTOTYPES
*/

void			ft_matrix_popping(int max_nodes, int **mtx, int *node_path);
void			ft_matrix_reset_state(t_master *mstr);
void			ft_matrix_reset_one_path(t_master *mstr, int path);
void			ft_matrix_generate(t_master *mstr, t_storage *storage);
void			ft_solution_print(t_master *mstr);

/*
** SOLVER PROTOTYPES
*/

void			solver(t_master *mstr);
int				ft_solver_paths_splitter(t_master *mstr,
					int **mtx, int cur_node, int end_node);
void			ft_solver_paths_finder(t_master *mstr, int flow);
void			ft_solver_paths_shortener(t_master *mstr, int flow);
void			ft_solver_paths(t_master *mstr, int flow);
void			ft_solver_turn_counter(t_master *mstr, int flow);
void			ft_solver_solution_store(t_master *mstr,
					int max_nodes, int flow);

/*
** OUTPUT PROTOTYPES
*/

void			output(t_master *mstr);
void			output_start_end(t_master *mstr);
void			ft_output_solution(t_master *mstr);
void			ft_output_count_inactive_pipes(t_master *mstr);
void			ft_output_putstr(char *str, t_master *mstr);
void			ft_output_putnstr(char *str, int n, t_master *mstr);
void			ft_output_putnbr(int n, t_master *mstr);
void			ft_output_buffer_flush(t_master *mstr);
void			ft_output_explained(t_master *master, int o_case);

#endif
