/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:38:31 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/01/03 15:01:23 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include <type_traits>

namespace ft
{
    template <class T, T v>
    struct integral_constant
    {
        typedef T                       value_type;
        typedef integral_constant<T, v> type;

        const static T value = v;

        operator T(void) { return (value); }
    };

    template <class T>
    struct is_integral : public ft::integral_constant<bool, false>
    {
    };

    template <>
    struct is_integral<bool> : public ft::integral_constant<bool, true>
    {
    };

    template <>
    struct is_integral<char> : public ft::integral_constant<bool, true>
    {
    };

    template <>
    struct is_integral<char16_t> : public ft::integral_constant<bool, true>
    {
    };

    template <>
    struct is_integral<char32_t> : public ft::integral_constant<bool, true>
    {
    };

    template <>
    struct is_integral<wchar_t> : public ft::integral_constant<bool, true>
    {
    };

    template <>
    struct is_integral<signed char> : public ft::integral_constant<bool, true>
    {
    };

    template <>
    struct is_integral<short int> : public ft::integral_constant<bool, true>
    {
    };

    template <>
    struct is_integral<int> : public ft::integral_constant<bool, true>
    {
    };

    template <>
    struct is_integral<long int> : public ft::integral_constant<bool, true>
    {
    };

    template <>
    struct is_integral<unsigned char> : public ft::integral_constant<bool, true>
    {
    };

    template <>
    struct is_integral<unsigned short int> : public ft::integral_constant<bool, true>
    {
    };

    template <>
    struct is_integral<unsigned int> : public ft::integral_constant<bool, true>
    {
    };

    template <>
    struct is_integral<unsigned long int> : public ft::integral_constant<bool, true>
    {
    };

    // NOTE c++11
    template <>
    struct is_integral<long long int> : public ft::integral_constant<bool, true>
    {
    };

    template <>
    struct is_integral<unsigned long long int> : public ft::integral_constant<bool, true>
    {
    };
} // namespace ft

#endif
