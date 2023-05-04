/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:29:17 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/12/24 16:37:14 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
      public:
        typedef Iterator                                              iterator_type;
        typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename iterator_traits<Iterator>::value_type        value_type;
        typedef typename iterator_traits<Iterator>::difference_type   difference_type;
        typedef typename iterator_traits<Iterator>::pointer           pointer;
        typedef typename iterator_traits<Iterator>::reference         reference;

      private:
        iterator_type _base;

      public:
        reverse_iterator(void) : _base(iterator_type()) {}
        reverse_iterator(const iterator_type &it) : _base(it) {}
        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it) : _base(rev_it.base())
        {
        }

        iterator_type base() const { return _base; }

        reference operator*() const
        {
            iterator_type ret(_base);
            ret--;
            return *ret;
        }

        reverse_iterator operator+(difference_type n) const
        {
            reverse_iterator ret(*this);
            ret._base -= n;
            return ret;
        }

        reverse_iterator &operator++()
        {
            _base--;
            return *this;
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator ret(*this);
            _base--;
            return ret;
        }

        reverse_iterator &operator+=(difference_type n)
        {
            _base -= n;
            return *this;
        }

        reverse_iterator operator-(difference_type n) const
        {
            reverse_iterator ret(*this);
            ret -= n;
            return ret;
        }

        reverse_iterator &operator--()
        {
            _base++;
            return *this;
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator ret(*this);
            _base++;
            return ret;
        }

        reverse_iterator &operator-=(difference_type n)
        {
            _base += n;
            return *this;
        }

        pointer operator->() const { return &(operator*()); }

        reference operator[](difference_type n) const { return _base[-n - 1]; }
    };

    template <class Iterator, class Iter>
    bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iter> &rhs)
    {
        return lhs.base() == rhs.base();
    }
    template <class Iterator, class Iter>
    bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iter> &rhs)
    {
        return lhs.base() != rhs.base();
    }
    template <class Iterator, class Iter>
    bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iter> &rhs)
    {
        return lhs.base() > rhs.base();
    }
    template <class Iterator, class Iter>
    bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iter> &rhs)
    {
        return lhs.base() >= rhs.base();
    }
    template <class Iterator, class Iter>
    bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iter> &rhs)
    {
        return lhs.base() < rhs.base();
    }
    template <class Iterator, class Iter>
    bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iter> &rhs)
    {
        return lhs.base() <= rhs.base();
    }

    template <class Iterator, class Iter>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iter> &rev_it)
    {
        return rev_it + n;
    }

    template <class Iterator, class Iter>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iter> &rhs)
    {
        return rhs.base() - lhs.base();
    }
} // namespace ft
#endif
