/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:25:50 by seunghoh          #+#    #+#             */
/*   Updated: 2021/04/30 19:38:37 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include <stdbool.h>
# include "parse/pipeline.h"

typedef struct	s_instruction
{
	t_pipeline	*pipelines;
	int			length;
}				t_instruction;

void			init_instruction(t_instruction *instruction);
bool			parse_instruction(t_instruction *instruction,
									t_string *command);
void			clear_instruction(t_instruction *instruction);
#endif
