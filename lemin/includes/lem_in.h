/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:44:24 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/02 15:43:40 by cgiron           ###   ########.fr       */
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
# define BATCH_PRINT_SIZE 10
/*
** DICTIONARY
*/
# define HASH_SIZE 23197
/*
** LINE DEFINES
*/
# define POS_LINE 0
# define POS_START 1
# define POS_X 2
# define POS_Y 3
/*
** LINE DEFINES
*/
# define NOPE 0
# define CERTAINLY 1
/*
** COMMAND LINES
*/
# define START_MK "##start"
# define END_MK "##end"

typedef enum	e_ln_type
{
	ERROR, START, END, CELL, PIPE, COMMENT, END_OF_READ
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
	char				*name;
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
	int					var;
*/
	struct s_solution	*next;
}				t_solution;

typedef struct	s_master
{
	int				ants_nb;
	char			**adjacency;
	t_storage		*storage;
	int				piping;
	int				start;
	int				end;
	int				lines_nb;
	t_hash_dico		*dico;
}				t_master;

void 				ft_init_mstr(t_master *mstr);
void				parser(t_master *mstr);
char				*ft_parser_ants_get(t_master *mstr);
void				ft_exit(t_errors error);
int					ft_dico_hasher_djb2(char *str, char *end, int amplitude);
//int					ft_dico_add(t_hash_dico *dico, char *pos[4]);
void				ft_storage_grow(t_master *mstr);

t_ln_type			ft_parser_check_cell(char *line, t_ln_type type);
t_ln_type			ft_parser_line_type(char *line, int piping);

#endif
