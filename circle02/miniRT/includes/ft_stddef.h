/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stddef.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:00:45 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/09 14:43:32 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDDEF_H
# define FT_STDDEF_H

# ifndef PI
#  define PI 3.141592
# endif

# ifndef FOCAL_LEN
#  define FOCAL_LEN 5.0
# endif

# ifndef BMP_HEADER
#  define BMP_HEADER 122
# endif

/*
**	Validate, Parsing
*/
typedef struct			s_info
{
	char				**elem;
	struct s_info		*next;
}						t_info;

/*
**	Vec
*/
typedef struct			s_vec
{
	double				x;
	double				y;
	double				z;
}						t_vec;

/*
**	Ray
*/
typedef struct			s_ray
{
	t_vec				origin;
	t_vec				dir;
	double				time;
}						t_ray;

/*
**	Hit
*/
typedef struct			s_hit
{
	t_vec				normal;
	t_vec				point;
	t_vec				dir;
	t_vec				origin;
	t_vec				color;
}						t_hit;

/*
**	Light
*/
typedef struct			s_ambient
{
	double				ratio;
	t_vec				color;
}						t_ambient;

typedef struct			s_light
{
	t_vec				point;
	double				ratio;
	t_vec				color;
	struct s_light		*next;
}						t_light;

/*
**	Resolution
*/
typedef struct			s_resolution
{
	int					width;
	int					height;
	double				a_ratio;
}						t_resolution;

/*
**	Camera
*/

typedef struct			s_cam
{
	t_vec				point;
	t_vec				orient;
	t_vec				metrix[3];
	double				pan;
	double				tilt;
	double				fov;
	double				focal_len;
	struct s_cam		*next;
}						t_cam;

/*
**	Objects
*/
typedef struct			s_obj_group
{
	void				*object;
	int					(*hit)(void *, t_ray *, t_hit *);
	void				(*translate)(void *, int);
	void				(*rotate)(void *, int, double);
	void				(*scale)(void *, int);
	t_vec				angle;
	struct s_obj_group	*next;
}						t_obj_group;

typedef struct			s_sphere
{
	t_vec				center;
	double				diameter;
	t_vec				color;
}						t_sphere;

typedef struct			s_plane
{
	t_vec				point;
	t_vec				orient;
	t_vec				color;
}						t_plane;

typedef struct			s_square
{
	t_vec				point;
	t_vec				orient;
	t_vec				vertex[4];
	double				size;
	t_vec				color;
}						t_square;

typedef struct			s_cylinder
{
	t_vec				point;
	t_vec				orient;
	double				diameter;
	double				height;
	t_vec				color;
}						t_cylinder;

typedef struct			s_triangle
{
	t_vec				point1;
	t_vec				point2;
	t_vec				point3;
	t_vec				color;
}						t_triangle;

/*
**	World
*/
typedef struct			s_world
{
	t_obj_group			*obj_group;
	t_light				*light;
	t_cam				*cam;
	int					cam_num;
	t_ambient			*ambient;
	t_resolution		*resolution;
}						t_world;

/*
**	MLX
*/
typedef struct			s_mlx
{
	void				*ptr;
	void				*win;
	void				*img;
	char				*addr;
	int					bpp;
	int					line;
	int					endian;
	int					width;
	int					height;
	double				a_ratio;
}						t_mlx;

/*
**	EVENT
*/
typedef struct			s_event
{
	t_obj_group			*selected_obj;
	t_cam				*selected_cam;
	int					selected;
	int					shift;
}						t_event;

/*
**	TRACE
*/
typedef struct			s_trace
{
	t_world				*world;
	t_mlx				*mlx;
	t_event				*event;
}						t_trace;

#endif
