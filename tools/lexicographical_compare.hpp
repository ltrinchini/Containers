/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:40:37 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/12/24 16:36:54 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

#include "enable_if.hpp"
#include "is_integral.hpp"
namespace ft
{
    template <class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
    {
        while (true)
        {
            if (first1 == last1 && !(first2 == last2))
                return (true);
            else if (first2 == last2)
                break;
            if (*first1 < *first2)
                return (true);
            if (*first2 < *first1)
                return (false);
            first1++;
            first2++;
        }
        return (false);
    }

    template <class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
    {
        while (true)
        {
            if (first1 == last1 && !(first2 == last2))
                return (true);
            else if (first2 == last2)
                break;
            if (comp(*first1, *first2))
                return (true);
            if (comp(*first2, *first1))
                return (false);
            first1++;
            first2++;
        }
        return (false);
    }
} // namespace ft
#endif
