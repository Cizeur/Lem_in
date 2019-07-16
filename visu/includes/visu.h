/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:42:07 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/16 17:01:40 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <stdio.h>
# include <stdlib.h>
# include "error.h"
# include "libft/libft.h"
# include "SDL.h"
# include "SDL_ttf.h"

# define TRUE			1
# define FALSE			-1

# define NODE_NOTHING	0
# define NODE_START		1
# define NODE_END		2

# define PIPE_ACTIVE	1
# define PIPE_INACTIVE	-1

# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480

typedef struct		s_nodes
{
	int				node_index;
	char			*name;
	int				len_name;
	int				x;
	int				y;
	int				*pipes;
	int				nb_pipes;
	int				flag;
}					t_nodes;

typedef struct		s_pipes
{
	int				pipe_index;
	char			*node1_name;
	int				node1_index;
	char			*node2_name;
	int				node2_index;
	int				active;
}					t_pipes;

// typedef struct		s_moves
// {
// 	int				move_index;

// }					t_moves;


typedef struct		s_master
{
	int				nb_ants;
	int				nb_nodes;
	int				nb_pipes;
	int				nb_inactive;
	int				nb_movements;
	t_nodes			**nodes_array;
	t_pipes			**pipes_array;
	// t_moves			**moves_array;
	int				start_index;
	char			*start_name;
	int				end_index;
	char			*end_name;
	int				current_node;
	int				current_pipe;
	int				max_x;
	int				min_x;
	int				max_y;
	int				min_y;
	SDL_Window      *gWindow;
	SDL_Surface     *gScreenSurface;
	SDL_Surface     *gHelloWorld;
	// int				current_movement;
}					t_master;

/*
***		PARSER
*/

int					parser(t_master *mstr);

/*
***		INITIALIZATION
*/

void  				inizialization(t_master *mstr);

/*
***		PARSER : FT_GET
*/

void				ft_get_parameters(t_master *mstr, char *line, int nb_line);
void				ft_get_input(t_master *mstr, char *line);
void				ft_get_nodes(t_master *mstr, char *line);
void				ft_get_pipes(t_master *mstr, char *line);
void				ft_get_movements(t_master *mstr, char *line);

/*
***		PRINT
*/

void			    ft_print_parameters(t_master *mstr);
void  				ft_print_nodes(t_master *mstr);
void  				ft_print_pipes(t_master *mstr);


/*
***		VISUAL
*/

void 			   	visual(t_master *mstr);

/*
***		FT_EXIT
*/

int				    ft_exit(t_errors error);

#endif