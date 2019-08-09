/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:42:07 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/09 16:22:54 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <stdio.h>
# include <stdlib.h>
# include "error.h"
# include "key_press.h"
# include "libft/libft.h"
# include "SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"

# define TRUE				1
# define FALSE				-1

# define NODE				1
# define PIPE				2
# define MOVE				3

# define LINE_NODES			"# number of nodes            = "
# define LINE_PIPES			"# number of pipes            = "
# define LINE_MOVES			"# number of movements        = "
# define LINE_ACTIVE		"# number of inactive pipes   = "

# define COMMENT_START		"##start"
# define COMMENT_END		"##end"
# define COMMENT_ACTIVE		"#active"
# define COMMENT_INACTIVE	"#inactive"

# define NODE_UNUSED		-1
# define NODE_USED			0
# define NODE_START			1
# define NODE_END			2

# define PIPE_UNDEFINED		0
# define PIPE_ACTIVE		1
# define PIPE_INACTIVE		-1

# define S_WIDTH			1700
# define S_HEIGHT			1200

# define VISU_FAILED		-1
# define VISU_FINISHED		1

# define FRAMES				64

typedef struct		s_ants
{
	int				ant_index;
	int				current_move;
	int				current_node;
}					t_ants;

typedef struct		s_nodes
{
	int				node_index;
	char			*name;
	int				len_name;
	int				x;
	int				x_px;
	int				y;
	int				y_px;
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

typedef struct		s_moves
{
	int				move_index;
	int				current_index;
	int				ant_index;
	int				node1_index;
	int				node2_index;
	struct s_moves	*next;
}					t_moves;

typedef struct		s_texture
{
	char			*path;
	int				width;
	int				height;
	SDL_Texture		*texture;
}					t_texture;

typedef struct		s_master
{
	int				nb_ants;
	int				nb_nodes;
	int				nb_pipes;
	int				nb_inactive;
	int				nb_movements;
	t_ants			**ants_array;
	t_nodes			**nodes_array;
	t_pipes			**pipes_array;
	t_moves			**moves_array;
	int				start_index;
	char			*start_name;
	int				end_index;
	char			*end_name;
	int				current_node;
	int				current_pipe;
	int				current_move;
	int				max_x;
	int				min_x;
	int				max_y;
	int				min_y;
	SDL_Window		*window;
	SDL_Renderer	*render;
	SDL_Event		event;
	t_texture		**textures;
	t_texture		*background;
	t_texture		*start;
	t_texture		*finish;
	t_texture		*node;
	int				img_init_png;
	int				frame;
	int				delay;
	int				flag_move;
	int				flag_exit;
}					t_master;

/*
***		PARSER and INITIALIZATION
*/

void				parser(t_master *mstr);
void				ft_get_parameters(t_master *mstr, char *line, int nb_line);
void				ft_get_input(t_master *mstr, char *line);
void				ft_get_nodes(t_master *mstr, char *line);
void				ft_get_pipes(t_master *mstr, char *line);
void				ft_get_moves(t_master *mstr, char *line);

void				inizialization(t_master *mstr);

/*
***		CHECK
*/

void				check_parameters(t_master *mstr);
void				check_nodes_pipes_moves(t_master *mstr);


/*
***		VISUAL
*/

void				vs_init(t_master *mstr);
void				vs_load(t_master *mstr);
void				vs_run(t_master *mstr);
int					control(t_master *mstr);

/*
***		RENDER
*/

void				render_nodes(t_master *mstr);
void				render_pipes(t_master *mstr);
void				render_moves(t_master *mstr);
void				render_total_background(t_master *mstr);

/*
***		TEXTURE
*/

void				init_texture(t_texture *texture);
void				clear_texture(t_texture *texture);
int					free_texture(t_texture *texture);
int					load_texture_from_file(t_master *mstr,
					t_texture *texture, char *path);
void				render_texture(t_master *mstr,
					t_texture *texture, int x, int y);

/*
***		PRINT -> ALL OF THEM USE PRINTF AND ARE NOT WORKING
*/

void				print(t_master *mstr, int ac, char **av);
void				ft_print_parameters(t_master *mstr);
void				ft_print_nodes(t_master *mstr);
void				ft_print_pipes(t_master *mstr);
void				ft_print_moves(t_master *mstr);

/*
***		UTILS
*/

int					ft_get_index_node(t_master *mstr, char *name);
int					ft_str_cmp(char *s1, char *s2);
int					ft_str_isdigit(char *line);
int					ft_istrstr(const char *haystack, const char *needle);

/*
***		ERROR EXIT AND CLOSE PROGRAM
*/

void				ft_exit(t_master *mstr, t_errors error);
void				close_program(t_master *mstr, int program_state);

#endif
