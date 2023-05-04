/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:15:53 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/12/24 16:37:09 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

#include "lexicographical_compare.hpp"

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
      public:
        typedef T1 first_type;
        typedef T2 second_type;

        T1 first;
        T2 second;

        pair(void) : first(first_type()), second(second_type()) {}
        template <class U1, class U2>
        pair(const pair<U1, U2> &cpy) : first(cpy.first), second(cpy.second)
        {
        }
        pair(const T1 &x, const T2 &y) : first(x), second(y) {}
        ~pair(void) {}
        pair &operator=(const pair &other)
        {
            if (this == &other)
                return (*this);
            first = other.first;
            second = other.second;
            return (*this);
        }
    };

    template <class T1, class T2>
    bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <class T1, class T2>
    bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T1, class T2>
    bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        if (lhs.first < rhs.first)
            return (true);
        return (lhs.first == rhs.first && lhs.second < rhs.second);
    }

    template <class T1, class T2>
    bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return (lhs < rhs || lhs == rhs);
    }

    template <class T1, class T2>
    bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        if (rhs.first < lhs.first)
            return (true);
        return (lhs.first == rhs.first && rhs.second < lhs.second);
    }

    template <class T1, class T2>
    bool operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return (lhs > rhs || lhs == rhs);
    }
} // namespace ft
#endif
