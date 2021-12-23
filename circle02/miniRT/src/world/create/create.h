/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:07:46 by jungwkim          #+#    #+#             */
/*   Updated: 2021/12/23 18:58:10 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_H
# define CREATE_H

# include "ft_stddef.h"
# include "key_def.h"
# include "utils/utils.h"
# include "parsing/validate/validate.h"
# include "vec/vec.h"

int		create_members(t_world *world, char **strs, char *id);

int		init_obj_group(t_obj_group **group, char **strs,
					int (*init)(void **, char **),
					int (*hit)(void *, t_ray *, t_hit *));
int		add_obj_event(t_obj_group *group,
					void (*translate)(void *, int),
					void (*rotate)(void *, int, double),
					void (*scale)(void *, int));

/*
**	create
*/
int		create_r(t_world *world, char **strs);
int		create_a(t_world *world, char **strs);
int		create_c(t_world *world, char **strs);
int		create_l(t_world *world, char **strs);
int		create_sp(t_world *world, char **strs);
int		create_pl(t_world *world, char **strs);
int		create_sq(t_world *world, char **strs);
int		create_cy(t_world *world, char **strs);
int		create_tr(t_world *world, char **strs);

/*
**	clear
*/
void	clear_resolution(t_resolution **resolution);
void	clear_ambient(t_ambient **ambient);
void	clear_cam(t_cam **cam, int cam_num);
void	clear_light(t_light **light);
void	clear_object(t_obj_group **group);

/*
**	hit
*/
int		hit_sphere(void *obj, t_ray *ray, t_hit *hit);
int		hit_plane(void *obj, t_ray *ray, t_hit *hit);
int		hit_square(void *obj, t_ray *ray, t_hit *hit);
int		hit_cylinder(void *obj, t_ray *ray, t_hit *hit);
int		hit_triangle(void *obj, t_ray *ray, t_hit *hit);
void	init_coefficient(t_ray *ray, t_cylinder *cylinder,
						double radius, t_vec *coefficient);
void  loss_of_significance(double *q, double b, double discr);

/*
**	translate
*/
void	translate_sphere(void *obj, int key);
void	translate_plane(void *obj, int key);
void	translate_square(void *obj, int key);
void	translate_triangle(void *obj, int key);
void	translate_cylinder(void *obj, int key);

/*
**	rotate
*/
void	random_axis_rotate(t_vec *metrix, t_vec dir);
void	x_axis_rotate(t_vec *orient, double a);
void	y_axis_rotate(t_vec *orient, double a);
void	z_axis_rotate(t_vec *orient, double a);
void	reverse_rotate_metrix(t_vec *metrix);
void	init_metrix(t_vec *u, t_vec *v, double *n, t_vec *dir);

void	rotate_sphere(void *obj, int key, double angle);
void	rotate_plane(void *obj, int key, double angle);
void	rotate_square(void *obj, int key, double angle);
void	rotate_triangle(void *obj, int key, double angle);
void	rotate_cylinder(void *obj, int key, double angle);

/*
**	scale
*/
void	scale_sphere(void *obj, int key);
void	scale_plane(void *obj, int key);
void	scale_square(void *obj, int key);
void	scale_triangle(void *obj, int key);
void	scale_cylinder(void *obj, int key);

/*
**	solve
*/
int		solve_plane(t_ray *ray, t_vec point, t_vec dir);
int		solve_triangle(t_ray *ray, t_vec a, t_vec b, t_vec c);
int		solve_cylinder(t_ray *ray, t_cylinder *cylinder,
					double radius, double height);
int		solve_quadratic(double a, double b, double c, t_ray *ray);
int		solve_quadratic_max(double a, double b, double c, t_ray *ray);

/*
**	conversion metrix
*/
void	random_axis_rotate(t_vec *metrix, t_vec dir);
void	apply_metrix(t_vec *metrix, t_vec *vertex);
void	translate(t_vec center, t_vec *vertex);
void	reverse_rotate_metrix(t_vec *metrix);

void	init_cam_metrix(t_vec (*metrix)[3], double pan, double tilt);

#endif
