/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:29:27 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/12/24 16:36:38 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

// template <class Iter>
// struct has_pointer
// {
// private:
// 	typedef char one;
// 	struct two
// 	{
// 		one x[2];
// 	};

// 	template <class T>
// 	static one test(typename T::pointer);
// 	template <class T>
// 	static two test(...);

// public:
// 	static const bool value = sizeof(test<Iter>(0)) == sizeof(one);
// };
namespace ft
{
    template <class Iter>
    struct iterator_traits
    {
        typedef typename Iter::difference_type   difference_type;
        typedef typename Iter::value_type        value_type;
        typedef typename Iter::pointer           pointer;
        typedef typename Iter::reference         reference;
        typedef typename Iter::iterator_category iterator_category;
    };

    template <class T>
    struct iterator_traits<T *>
    {
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef T                              *pointer;
        typedef T                              &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
} // namespace ft
#endif
