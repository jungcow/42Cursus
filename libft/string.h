/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 03:47:22 by seunghoh          #+#    #+#             */
/*   Updated: 2021/04/15 20:46:19 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H
# define STRING_SIZE 1024

# include <stdbool.h>

typedef struct	s_string
{
	char		*content;
	int			length;
	int			capacity;
}				t_string;

bool    init_string(t_string *string);
bool    add_string(t_string *string, char ch);
void    clear_string(t_string *string);
#endif
