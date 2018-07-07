/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstorcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:20:54 by mstorcha          #+#    #+#             */
/*   Updated: 2018/05/23 13:21:42 by mstorcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
		if ((sdl->wind = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED,
						SDL_WINDOWPOS_UNDEFINED, WIDTH,
						HEIGHT, SDL_WINDOW_SHOWN)))
			if ((sdl->rend = SDL_CreateRenderer(sdl->wind, -1,
							SDL_RENDERER_ACCELERATED)))
				if (!(sdl->sur = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32 , 0, 0, 0, 0)))
					exit(1);
				return ;
	ft_putendl("Error in init_sdl()");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_main	mlx;

	if (argc != 2)
		return (0);
	// mlx.scene = scene_create(argv);
	// mlx.mlx_ptr = mlx_init();
	// mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "RTv1");
	// mlx.image.data = mlx_new_image(mlx.mlx_ptr, HEIGHT, WIDTH);
	// mlx.image.ptr = (int *)mlx_get_data_addr(mlx.image.data,
	// 		&mlx.image.bits, &mlx.image.sz_l, &mlx.image.endi);
	// rendering(mlx);
	// mlx_hook(mlx.win_ptr, 2, 0, &key, &(mlx));
	// mlx_hook(mlx.win_ptr, 17, 0, (int (*)())exit, NULL);
	// mlx_loop(mlx.mlx_ptr);
	// t_sdl		sdl;
	SDL_Event	event;

	init_sdl(mlx.sdl);
	mlx.scene = scene_create(argv);
//	rendering(mlx); //t_main
	// SDL_RenderPresent(mlx.sdl->rend);
	while (1) {
        while (SDL_PollEvent(&event)) {
            if ((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type &&
                                             SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
                exit(0);
            else if (SDL_KEYDOWN == event.type && event.key.keysym.scancode == SDL_SCANCODE_UP) {
                printf("%f\n", mlx.scene->cam.d.x);
                mlx.scene->cam.d.x += 5;
                printf("%f\n", mlx.scene->cam.d.x);
            }
        }
        rendering(mlx);
    }
	return (0);
}
