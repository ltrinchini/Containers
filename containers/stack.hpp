/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:35:58 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/01/03 15:03:17 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
      public:
        typedef T                                  value_type;
        typedef Container                          container_type;
        typedef typename container_type::size_type size_type;

      protected:
        container_type c;

      public:
        explicit stack(const Container &cont = Container()) : c(cont) {}
        ~stack(void) {}

        stack &operator=(const stack &other)
        {
            if (this == &other)
                return (*this);
            c = other.c;
			return (*this);
        }

        value_type       &top(void) { return (c.back()); }
        const value_type &top(void) const { return (c.back()); }

        bool      empty(void) const { return (c.empty()); }
        size_type size(void) const { return (c.size()); }

        void push(const value_type &value) { c.push_back(value); }
        void pop(void) { c.pop_back(); }

        friend bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c == rhs.c); }
        friend bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c != rhs.c); }
        friend bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c < rhs.c); }
        friend bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c <= rhs.c); }
        friend bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c > rhs.c); }
        friend bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c >= rhs.c); }
    };
} // namespace ft
#endif
