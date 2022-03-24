/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:18:34 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/22 13:35:14 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../includes/push_swap.h"

void		ft_sorts_lst(t_mem *save);
int			ft_sortss_lst(int i, t_mem *save);
int			ft_sortss1_lst(int i, t_mem *save);
int			ft_sortss2_lst(int i, t_mem *save);
int			ft_sortss3_lst(int i, t_mem *save);
int			ft_sortss4_lst(int i, t_mem *save);
int			ft_check_cmd(char *cmd);
int			ft_case_0(char *cmd);
int			ft_case_1(char *cmd);
int			ft_case_2(char *cmd);
void		ft_output(t_mem *save);

#endif
