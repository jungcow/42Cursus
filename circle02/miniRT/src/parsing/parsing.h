/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:03:29 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/06 09:02:35 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "get_next_line/get_next_line.h"
# include "validate/validate.h"

t_info			*parsing(char *filename);
int				check_filename(char *filename);
void			clear_info(t_info **info);

#endif
