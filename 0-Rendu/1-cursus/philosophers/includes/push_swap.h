/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:18:34 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/16 11:32:59 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/includes/libft.h"

typedef struct save_mem
{
	t_struct	*l_lst_a;
	t_struct	*l_lst_b;
	int			index_a;
	int			index_b;
	long long	int_s;
	long long	int_e;
	long long	int_m1;
	long long	int_m2;
	int			rr;
	int			rrp;
	int			gr;
	int			n_gr;
	int			int_n_gr;
	int			int_gr;
	int			pos;
	int			mv;
}		t_mem;

	//1_ft_check_arg.c
char		**ft_check_arg(int argc, char **argv, t_mem *save);
char		**ft_is_string_arg(int argc, char **argv, t_mem *save);
char		**ft_is_multi_arg(int argc, char **argv, t_mem *save);
int			ft_is_nbr(int argc, char **argv);

	//2_ft_make_lst.c
int			ft_make_lst(int argc, char **argv, t_mem *save);
int			ft_check_int(int argc, t_mem *save);

	//3_ft_sort_lst.c
void		ft_sort_lst(t_mem *save);
int			ft_check_lst(t_struct *l_lst, int index);
void		ft_sort_3(t_mem *save);
void		ft_spot(t_mem *save);
void		ft_finish(t_mem *save);

	//4_ft_sort_lst_utils.c
void		ft_sch_start(t_struct *l_lst, t_mem *save);
void		ft_sch_end(t_struct *l_lst, t_mem *save);
void		ft_sch_m2(t_struct *l_lst, int index, t_mem *save);
void		ft_sch_m1(t_struct *l_lst, int index, t_mem *save);

	//5.0_ft_sort_gr_utils.c
void		ft_sort_gr(t_mem *save);
void		ft_start_rra(t_mem *save);
void		ft_while_gr_a(t_mem *save);
int			ft_m2(t_mem *save);
void		ft_sch_nb_a(t_mem *save);

	//5.1_ft_sort_gr_utils.c
void		ft_sort_grr(t_mem *save);
void		ft_while_gr_b(t_mem *save);
int			ft_m1(t_mem *save);
void		ft_sch_nb_b(t_mem *save);

	//6_ft_spot_utils.c
void		ft_pos(t_mem *save);
void		ft_return_zero(t_mem *save);

	//7.0_ft_operator_swap.c
void		ft_sa(t_mem *save);
void		ft_sb(t_mem *save);
void		ft_ss(t_mem *save);

	//7.1_ft_operator_push.c
void		ft_pa(t_mem *save);
void		ft_pb(t_mem *save);
void		ft_push(t_struct **l_lst_s, t_struct **l_lst_a, int *i_s, int *i_a);

	//7.2_ft_operator_rotate.c
void		ft_ra(t_mem *save);
void		ft_rb(t_mem *save);
void		ft_rr(t_mem *save);

	//7.3_ft_operator_rev_rotate.c
void		ft_rra(t_mem *save);
void		ft_rrb(t_mem *save);
void		ft_rrr(t_mem *save);

#endif
