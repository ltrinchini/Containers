/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:46:02 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/12/24 16:37:34 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "enable_if.hpp"
#include "is_integral.hpp"
#include "iterator_traits.hpp"
#include "lexicographical_compare.hpp"
#include "make_pair.hpp"
#include "pair.hpp"
#include "reverse_iterator.hpp"

#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{
    template <class InputIt>
    static typename ft::iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last)
    {
        typename ft::iterator_traits<InputIt>::difference_type rtn(0);
        while (first != last)
        {
            ++first;
            rtn++;
        }
        return (rtn);
    }
} // namespace ft

#endif
