/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:13:27 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/12/28 18:00:15 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_VECTOR_HPP
#define ITERATOR_VECTOR_HPP

#include <iterator>

namespace ft
{
    template <class T, class Distance = std::ptrdiff_t, class Pointer = T *, class Reference = T &>
    class iterator_vec : public std::iterator<std::random_access_iterator_tag, T, Distance, Pointer, Reference>
    {
      public:
        typedef std::random_access_iterator_tag                                                             iterator_category;
        typedef typename std::iterator<iterator_category, T, Distance, Pointer, Reference>::pointer         iterator_type;
        typedef typename std::iterator<iterator_category, T, Distance, Pointer, Reference>::value_type      value_type;
        typedef typename std::iterator<iterator_category, T, Distance, Pointer, Reference>::difference_type difference_type;
        typedef typename std::iterator<iterator_category, T, Distance, Pointer, Reference>::pointer         pointer;
        typedef typename std::iterator<iterator_category, T, Distance, Pointer, Reference>::reference       reference;

      private:
        template <class V, class dist, class pt, class re>
        friend class iterator_vec;
        pointer ptr;

      public:
        iterator_vec(void) : ptr(NULL) {}
        iterator_vec(pointer x) : ptr(x) {}
        template <class V, class dist, class pt, class re>
        iterator_vec(const iterator_vec<V, dist, pt, re> &mit) : ptr(mit.ptr)
        {
        }
        ~iterator_vec(void) {}

        template <class V, class dist, class pt, class re>
        iterator_vec &operator=(const iterator_vec<V, dist, pt, re> &copy)
        {
            ptr = copy.ptr;
            return *this;
        }

        template <class V, class dist, class pt, class re>
        bool operator==(const iterator_vec<V, dist, pt, re> &rhs)
        {
            return (ptr == rhs.ptr);
        }
        template <class V, class dist, class pt, class re>
        bool operator!=(const iterator_vec<V, dist, pt, re> &rhs) const
        {
            return ptr != rhs.ptr;
        }

        reference operator*() const { return *ptr; }
        pointer   operator->() const { return ptr; }

        iterator_vec &operator++()
        {
            ++ptr;
            return *this;
        }
        iterator_vec operator++(int)
        {
            iterator_vec tmp(*this);
                         operator++();
            return tmp;
        }
        iterator_vec &operator--()
        {
            --ptr;
            return *this;
        }
        iterator_vec operator--(int)
        {
            iterator_vec tmp(*this);
                         operator--();
            return tmp;
        }

        iterator_vec operator+(difference_type n) const
        {
            iterator_vec ret(*this);
            ret.ptr += n;
            return ret;
        }

        template <class V, class dist, class pt, class re>
        iterator_vec operator+(const iterator_vec<V, dist, pt, re> &iter) const
        {
            iterator_vec ret(*this);
            ret.ptr += iter.ptr - ret.ptr;
            return ret;
        }

        iterator_vec operator-(difference_type n) const
        {
            iterator_vec ret(*this);
            ret.ptr -= n;
            return ret;
        }

        template <class V, class dist, class pt, class re>
        difference_type operator-(const iterator_vec<V, dist, pt, re> &iter) const
        {
            return (ptr - iter.ptr);
        }

        template <class V, class dist, class pt, class re>
        bool operator<(const iterator_vec<V, dist, pt, re> &iter) const
        {
            return ptr < iter.ptr;
        }

        template <class V, class dist, class pt, class re>
        bool operator>(const iterator_vec<V, dist, pt, re> &iter) const
        {
            return ptr > iter.ptr;
        }

        template <class V, class dist, class pt, class re>
        bool operator<=(const iterator_vec<V, dist, pt, re> &iter) const
        {
            return ptr <= iter.ptr;
        }

        template <class V, class dist, class pt, class re>
        bool operator>=(const iterator_vec<V, dist, pt, re> &iter) const
        {
            return ptr >= iter.ptr;
        }

        iterator_vec &operator+=(difference_type n)
        {
            ptr += n;
            return *this;
        }

        iterator_vec &operator-=(difference_type n)
        {
            ptr -= n;
            return *this;
        }

        reference operator[](difference_type n) const { return ptr[n]; }

        friend iterator_vec operator+(difference_type n, const iterator_vec &rhs)
        {
            iterator_vec ret(rhs.ptr);
            ret.ptr += n;
            return ret;
        }
    };
} // namespace ft

#endif
