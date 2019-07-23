/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:50:19 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/23 20:11:15 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int     vs_run(t_master *mstr)
{
    int         i;
    int         flag_quit;
    int         x;
    int         y;
    // SDL_Rect    *node;

    i = 0;
    flag_quit = FALSE;
    while (flag_quit == FALSE)
    {
        while (SDL_PollEvent(&mstr->event_Quit) != 0)
        {
            if (mstr->event_Quit.type == SDL_QUIT)
                flag_quit = TRUE;
            SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(mstr->render);
            render_texture(mstr, mstr->background, 0, 0);
            while (i < mstr->nb_nodes)
            {
                SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0x00, 0xFF);
                // if (!(node = (SDL_Rect*)ft_memalloc(sizeof(SDL_Rect))))
                //     return (ft_exit(INIT_SDL));
                x = (S_WIDTH / 10) * mstr->nodes_array[i]->x;
                y = (S_HEIGHT / 10) * mstr->nodes_array[i]->y;
                // node->x = (S_WIDTH / 10) + x;
                // node->y = (S_HEIGHT / 10) + y;
                // node->w = S_WIDTH / 50;
                // node->h = S_HEIGHT / 50;
                SDL_Rect node = {
                    (S_WIDTH / 10) + x,
                    (S_HEIGHT / 10) + y,
                    S_WIDTH / 50,
                    S_HEIGHT / 50
                };
                SDL_RenderFillRect(mstr->render, &node);
                // free(node);
                i++;
            }
            SDL_RenderPresent(mstr->render);
        }
    }
    return (TRUE);
}

/*
***     OPTION 1
*/

// while (i < mstr->nb_nodes)
// {
//     SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0x00, 0xFF);
//     x = (S_WIDTH / 10) * mstr->nodes_array[i]->x;
//     y = (S_HEIGHT / 10) * mstr->nodes_array[i]->y;
//     SDL_Rect    node = {
//         (S_WIDTH / 10) + x,
//         (S_HEIGHT / 10) + y,
//         S_WIDTH / 50,
//         S_HEIGHT / 50
//     };
//     SDL_RenderFillRect(mstr->render, &node);
//     SDL_RenderPresent(mstr->render);
//     printf("NAME = %s || x = %d -> %d || y = %d -> %d\n", mstr->nodes_array[i]->name,
//         mstr->nodes_array[i]->x, (S_WIDTH / 10) + x, mstr->nodes_array[i]->y, (S_HEIGHT / 10) + y);
//     i++;
// }
// SDL_RenderPresent(mstr->render);


/*
***     OPTION 2
*/

// SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0x00, 0xFF);
// x = (S_WIDTH / 10) * mstr->nodes_array[0]->x;
// y = (S_HEIGHT / 10) * mstr->nodes_array[0]->y;
// SDL_Rect    node1 = {
//     (S_WIDTH / 10) + x,
//     (S_HEIGHT / 10) + y,
//     S_WIDTH / 50,
//     S_HEIGHT / 50
// };
// SDL_RenderFillRect(mstr->render, &node1);

// x = (S_WIDTH / 10) * mstr->nodes_array[1]->x;
// y = (S_HEIGHT / 10) * mstr->nodes_array[1]->y;
// SDL_Rect    node2 = {
//     (S_WIDTH / 10) + x,
//     (S_HEIGHT / 10) + y,
//     S_WIDTH / 50,
//     S_HEIGHT / 50
// };
// SDL_RenderFillRect(mstr->render, &node2);

// x = (S_WIDTH / 10) * mstr->nodes_array[2]->x;
// y = (S_HEIGHT / 10) * mstr->nodes_array[2]->y;
// SDL_Rect    node3 = {
//     (S_WIDTH / 10) + x,
//     (S_HEIGHT / 10) + y,
//     S_WIDTH / 50,
//     S_HEIGHT / 50
// };
// SDL_RenderFillRect(mstr->render, &node3);

// x = (S_WIDTH / 10) * mstr->nodes_array[3]->x;
// y = (S_HEIGHT / 10) * mstr->nodes_array[3]->y;
// SDL_Rect    node4 = {
//     (S_WIDTH / 10) + x,
//     (S_HEIGHT / 10) + y,
//     S_WIDTH / 50,
//     S_HEIGHT / 50
// };
// SDL_RenderFillRect(mstr->render, &node4);

// x = (S_WIDTH / 10) * mstr->nodes_array[4]->x;
// y = (S_HEIGHT / 10) * mstr->nodes_array[4]->y;
// SDL_Rect    node5 = {
//     (S_WIDTH / 10) + x,
//     (S_HEIGHT / 10) + y,
//     S_WIDTH / 50,
//     S_HEIGHT / 50
// };
// SDL_RenderFillRect(mstr->render, &node5);

// SDL_RenderPresent(mstr->render);

/*
***     OPTION 3
*/

// SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0x00, 0xFF);
// x = (S_WIDTH / 10) * mstr->nodes_array[0]->x;
// y = (S_HEIGHT / 10) * mstr->nodes_array[0]->y;
// node->x = (S_WIDTH / 10) + x;
// node->y = (S_HEIGHT / 10) + y;
// node->w = S_WIDTH / 50;
// node->h = S_HEIGHT / 50;
// SDL_RenderFillRect(mstr->render, node);

// x = (S_WIDTH / 10) * mstr->nodes_array[1]->x;
// y = (S_HEIGHT / 10) * mstr->nodes_array[1]->y;
// node->x = (S_WIDTH / 10) + x;
// node->y = (S_HEIGHT / 10) + y;
// node->w = S_WIDTH / 50;
// node->h = S_HEIGHT / 50;
// SDL_RenderFillRect(mstr->render, node);

// x = (S_WIDTH / 10) * mstr->nodes_array[2]->x;
// y = (S_HEIGHT / 10) * mstr->nodes_array[2]->y;
// node->x = (S_WIDTH / 10) + x;
// node->y = (S_HEIGHT / 10) + y;
// node->w = S_WIDTH / 50;
// node->h = S_HEIGHT / 50;
// SDL_RenderFillRect(mstr->render, node);

// x = (S_WIDTH / 10) * mstr->nodes_array[3]->x;
// y = (S_HEIGHT / 10) * mstr->nodes_array[3]->y;
// node->x = (S_WIDTH / 10) + x;
// node->y = (S_HEIGHT / 10) + y;
// node->w = S_WIDTH / 50;
// node->h = S_HEIGHT / 50;
// SDL_RenderFillRect(mstr->render, node);

// x = (S_WIDTH / 10) * mstr->nodes_array[4]->x;
// y = (S_HEIGHT / 10) * mstr->nodes_array[4]->y;
// node->x = (S_WIDTH / 10) + x;
// node->y = (S_HEIGHT / 10) + y;
// node->w = S_WIDTH / 50;
// node->h = S_HEIGHT / 50;
// SDL_RenderFillRect(mstr->render, node);

// SDL_RenderPresent(mstr->render);