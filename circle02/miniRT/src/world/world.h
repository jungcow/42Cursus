/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 02:50:41 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/09 20:15:10 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "create/create.h"
# include "parsing/parsing.h"
# include "ft_stddef.h"

t_world		*create_world(t_info *info);
void		clear_world(t_world **world);

#endif
