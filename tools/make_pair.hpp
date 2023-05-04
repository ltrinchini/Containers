/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:32:27 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/12/24 16:36:58 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
#define MAKE_PAIR_HPP

#include "pair.hpp"
namespace ft
{
    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 t, T2 u)
    {
        ft::pair<T1, T2> ret(t, u);
        return ret;
    }
} // namespace ft

#endif
