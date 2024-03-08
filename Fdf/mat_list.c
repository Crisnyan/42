/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:22:10 by cmanica-          #+#    #+#             */
/*   Updated: 2024/03/08 17:29:22 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const t_mat	mat_list(int index)
{
	if (index == 1)
		return ((const)cmat(cvec(cos(ANGLE), sin(ANGLE), 0), 
				cvec(-sin(ANGLE), cos(ANGLE),  0), cvec(0, 0, 1));
	if (index == 2)
		return ((const)cmat(cvec(cos(ANGLE), sin(ANGLE), 0), 
				cvec(-sin(ANGLE), cos(ANGLE),  0), cvec(0, 0, 1));
	if (index == 3)
		return ((const)cmat(cvec(cos(ANGLE), sin(ANGLE), 0), 
				cvec(-sin(ANGLE), cos(ANGLE),  0), cvec(0, 0, 1));
	if (index == 4)
		return ((const)cmat(cvec(cos(ANGLE), sin(ANGLE), 0), 
				cvec(-sin(ANGLE), cos(ANGLE),  0), cvec(0, 0, 1));
	if (index == 5)
		return ((const)cmat(cvec(cos(ANGLE), sin(ANGLE), 0), 
				cvec(-sin(ANGLE), cos(ANGLE),  0), cvec(0, 0, 1));
	else
		return ((const)cmat(cvec(1, 0, 0), cvec(0, 1, 0), cvec(0, 0, 1));
}
