/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:23:10 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/04 12:07:10 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../tools/utility.hpp"
#include "../tools/iterator_vector.hpp"

#include <iostream>
#include <limits>
#include <memory>
#include <vector>

// Synopsis
// namespace ft
// {
// 	template <class T, class Allocator = std::allocator<T> >
// 	class vector
// 	{
// 	public:
// 		typedef T value_type;
// 		typedef Allocator allocator_type;
// 		typedef typename allocator_type::size_type size_type;
// 		typedef typename allocator_type::difference_type difference_type;
// 		typedef typename allocator_type::reference reference;
// 		typedef typename allocator_type::const_reference const_reference;
// 		typedef typename allocator_type::pointer pointer;
// 		typedef typename allocator_type::const_pointer const_pointer;
// 		typedef ft::iterator<value_type, difference_type, pointer, reference> iterator;
// 		typedef ft::iterator<const value_type, difference_type, const_pointer, const_reference> const_iterator;
// 		typedef ft::reverse_iterator<iterator> reverse_iterator;
// 		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

// 	private:
// 		pointer _begin;
// 		pointer _end;
// 		size_type _cap;
// 		allocator_type _allocator;

// 	public:
// 		vector(void);
// 		explicit vector(const Allocator &alloc);
// 		explicit vector(size_type count, const T &value = T(), const Allocator &alloc = Allocator());
// 		template <class InputIt>
// 		vector(InputIt first, InputIt last, const Allocator &alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0);
// 		vector(const vector &other) : _begin(NULL), _end(NULL), _cap(0), _allocator(other._allocator);
// 		~vector(void);
// 		vector &operator=(const vector &other);
// 		void assign(size_type count, const T &value);
// 		template <class InputIt>
// 		void assign(InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value>::type * = 0);
// 		allocator_type get_allocator() const;

// 		// Element access
// 		reference at(size_type pos);
// 		const_reference at(size_type pos) const;
// 		reference operator[](size_type pos);
// 		const_reference operator[](size_type pos) const;
// 		reference front();
// 		const_reference front() const;
// 		reference back();
// 		const_reference back() const;
// 		T *data();
// 		const T *data() const;

// 		// Iterators
// 		iterator begin();
// 		const_iterator begin() const;
// 		iterator end();
// 		const_iterator end();
// 		reverse_iterator rbegin();
// 		reverse_iterator rend();
// 		const_reverse_iterator rbegin() const;
// 		const_reverse_iterator rend() const;

// 		// Capacity
// 		bool empty() const;
// 		size_type size() const;
// 		size_type max_size() const;
// 		void reserve(size_type new_cap);
// 		size_type capacity(void) const;

// 		// Modifiers
// 		void clear(void);
// 		iterator insert(const_iterator pos, const T &value);
// 		iterator insert(const_iterator pos, size_type count, const T &value);
// 		template <class InputIt>
// 		void insert(const_iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0);
// 		iterator erase(iterator pos);
// 		iterator erase(iterator first, iterator last);
// 		void push_back(const T &value);
// 		void pop_back();
// 		void resize(size_type count, T value = T());
// 		void swap(vector &other);
// 	};
//
// 	// Non-member functions
//	template <class T, class Allocator = std::allocator<T> >
// 	bool operator==(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);
//	template <class T, class Allocator = std::allocator<T> >
// 	bool operator!=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);
//	template <class T, class Allocator = std::allocator<T> >
// 	bool operator<(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);
//	template <class T, class Allocator = std::allocator<T> >
// 	bool operator<=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);
//	template <class T, class Allocator = std::allocator<T> >
// 	bool operator>(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);
//	template <class T, class Allocator = std::allocator<T> >
// 	bool operator>=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);
//
// 	namespace std
// 	{
// 		template <typename T, class Allocator>
// 		void swap(ft::vector<T, Allocator> &lhs, ft::vector<T, Allocator> &rhs);
// 	}
// }
#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
      public:
        typedef T                                                                                   value_type;
        typedef Allocator                                                                           allocator_type;
        typedef typename allocator_type::size_type                                                  size_type;
        typedef typename allocator_type::difference_type                                            difference_type;
        typedef typename allocator_type::reference                                                  reference;
        typedef typename allocator_type::const_reference                                            const_reference;
        typedef typename allocator_type::pointer                                                    pointer;
        typedef typename allocator_type::const_pointer                                              const_pointer;
        typedef ft::iterator_vec<value_type, difference_type, pointer, reference>                   iterator;
        typedef ft::iterator_vec<const value_type, difference_type, const_pointer, const_reference> const_iterator;
        typedef ft::reverse_iterator<iterator>                                                      reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                                                const_reverse_iterator;

      private:
        pointer        _begin;
        pointer        _end;
        size_type      _cap;
        allocator_type _allocator;

      public:
        vector(void) : _begin(NULL), _end(NULL), _cap(0), _allocator(allocator_type()) {}
        explicit vector(const Allocator &alloc) : _begin(NULL), _end(NULL), _cap(0), _allocator(alloc) {}
        explicit vector(size_type count, const T &value = T(), const Allocator &alloc = Allocator()) : _begin(NULL), _end(NULL), _cap(0), _allocator(alloc)
        {
            try
            {
                reserve(count);
            }
            catch (const std::exception &e)
            {
                throw;
            }

            for (size_type index = 0; index < count; index++)
            {
                _allocator.construct(&_begin[index], value);
                _end++;
            }
        }

        template <class InputIt>
        vector(InputIt first, InputIt last, const Allocator &alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0) : _begin(NULL), _end(NULL), _cap(0), _allocator(alloc)
        {
            size_type size = ft::distance(first, last);
            try
            {
                reserve(size);
            }
            catch (const std::exception &e)
            {
                throw;
            }
            for (size_type index = 0; index < size; index++)
            {
                _allocator.construct(_begin + index, *first++);
                _end++;
            }
        }

        vector(const vector &other) : _begin(NULL), _end(NULL), _cap(0), _allocator(other._allocator)
        {
            try
            {
                reserve(other.size());
            }
            catch (const std::exception &e)
            {
                throw;
            }
            for (size_type i = 0; i < other.size(); i++)
            {
                _allocator.construct(_begin + i, other._begin[i]);
                _end++;
            }
        }

        ~vector(void)
        {
            clear();
            _allocator.deallocate(_begin, _cap);
        }

        vector &operator=(const vector &other)
        {
            if (this == &other)
                return (*this);

            clear();
            if (_allocator != other._allocator)
            {
                _allocator.deallocate(_begin, capacity());
                _cap = 0;
                _begin = _end = NULL;
                _allocator = other._allocator;
            }
            try
            {
                reserve(other._cap);
            }
            catch (const std::exception &e)
            {
                throw;
            }

            for (size_type i = 0; i < other.size(); i++)
            {
                _allocator.construct(_begin + i, other._begin[i]);
                _end++;
            }
            return (*this);
        }

        void assign(size_type count, const T &value)
        {
            clear();
            try
            {
                reserve(count);
            }
            catch (const std::exception &e)
            {
                throw;
            }

            for (size_type i = 0; i < count; i++)
            {
                _allocator.construct(_begin + i, value);
                _end++;
            }
        }

        template <class InputIt>
        void assign(InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value>::type * = 0)
        {
            vector tmp;
            while (first != last)
            {
                tmp.push_back(*first);
                first++;
            }

            size_type count = tmp.size();
            clear();

            try
            {
                if (_cap < count)
                {
                    _allocator.deallocate(_begin, _cap);
                    _begin = _end = NULL;
                    _cap = 0;
                }
                reserve(count);
            }
            catch (const std::exception &e)
            {
                throw;
            }

            for (size_type i = 0; i < count; i++)
            {
                _allocator.construct(_begin + i, tmp[i]);
                _end++;
            }
        }

        allocator_type get_allocator() const { return (_allocator); }

        // Element access
        reference at(size_type pos)
        {
            if (pos < 0 || pos >= size())
            {
                throw(std::out_of_range("Out of range"));
            }
            return (_begin[pos]);
        }

        const_reference at(size_type pos) const
        {
            if (pos < 0 || pos >= size())
            {
                throw(std::out_of_range("Out of range"));
            }
            return (_begin[pos]);
        }

        reference operator[](size_type pos) { return (_begin[pos]); }

        const_reference operator[](size_type pos) const { return (_begin[pos]); }

        reference       front() { return (*_begin); }
        const_reference front() const { return (*_begin); }
        reference       back() { return (*(_end - 1)); }
        const_reference back() const { return (*(_end - 1)); }
        T              *data() { return (_begin); }
        const T        *data() const { return (_begin); }

        // iterators
        iterator               begin() { return (_begin); }
        const_iterator         begin() const { return (_begin); }
        iterator               end() { return (_end); }
        const_iterator         end() const { return (_end); }
        reverse_iterator       rbegin() { return (reverse_iterator(_end)); }
        reverse_iterator       rend() { return (reverse_iterator(_begin)); }
        const_reverse_iterator rbegin() const { return (reverse_iterator(_end)); }
        const_reverse_iterator rend() const { return (reverse_iterator(_begin)); }

        // Capacity
        bool empty() const { return (size() == 0); }

        size_type size() const { return (_end - _begin); }

        size_type max_size() const
        {
            size_type       size = _allocator.max_size();
            difference_type max_diff = std::numeric_limits<difference_type>::max();
            if (size > (size_type) max_diff)
            {
                return (max_diff);
            }
            return (_allocator.max_size());
        }

        void reserve(size_type new_cap)
        {
            if (new_cap > max_size() || new_cap < 0)
            {
                throw(std::length_error("vector"));
            }
            else if (new_cap > capacity())
            {
                T *tmp_tab;
                try
                {
                    if (new_cap < _cap * 2)
                        new_cap = _cap * 2;
                    tmp_tab = _allocator.allocate(new_cap);
                }
                catch (const std::exception &e)
                {
                    throw;
                }

                for (size_type i = 0; i < size(); i++)
                {
                    _allocator.construct(tmp_tab + i, _begin[i]);
                    _allocator.destroy(&_begin[i]);
                }

                size_type tab_size = size();
                _allocator.deallocate(_begin, _cap);
                _begin = tmp_tab;
                _end = _begin + tab_size;
                _cap = new_cap;
            }
        }

        size_type capacity(void) const { return (_cap); }

        // Modifiers
        void clear(void)
        {
            size_type tmp_size = size();
            for (size_type index = 0; index < tmp_size; index++)
            {
                _allocator.destroy(_begin + index);
            }
            _end = _begin;
        }

        iterator insert(const_iterator pos, const T &value) { return (insert(pos, 1, value)); }

        iterator insert(const_iterator pos, size_type count, const T &value)
        {
            value_type      val = value;
            difference_type index = &(*pos) - _begin;
            size_type       new_size = size() + count;
            reserve(new_size);

            for (size_type i = 0; i < count; i++)
            {
                _allocator.construct(_end + i);
            }

            _end += count;
            for (size_type i = size() - 1; i >= index + count; i--)
            {
                _begin[i] = _begin[i - count];
            }
            for (size_type i = 0; i < count; i++)
            {
                _begin[index + i] = val;
            }
            return (&_begin[index]);
        }

        template <class InputIt>
        void insert(const_iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0)
        {
            ft::vector<typename ft::iterator_traits<InputIt>::value_type> tmp;
            while (first != last)
            {
                tmp.push_back(*first++);
            }

            difference_type index = &(*pos) - _begin;
            size_type       count = tmp.size();
            size_type       new_size = size() + count;
            try
            {
                reserve(new_size);
            }
            catch (const std::exception &e)
            {
                throw;
            }

            for (size_type i = 0; i < count; i++)
            {
                _allocator.construct(_end + i);
            }

            for (size_type i = size() + count - 1; i >= index + count; i--)
            {
                _begin[i] = _begin[i - count];
            }
            try
            {
                for (size_type i = 0; i < count; i++)
                {
                    _begin[index + i] = tmp[i];
                }
            }
            catch (...)
            {
                _cap = 0;
                throw;
            }
            _end += count;
        }

        iterator erase(iterator pos)
        {
            difference_type index = &(*pos) - _begin;
            size_type       old_size = size();
            for (size_type i = index; i < old_size - 1; i++)
            {
                _begin[i] = _begin[i + 1];
            }
            _end--;
            _allocator.destroy(_end);
            return (pos);
        }

        iterator erase(iterator first, iterator last)
        {
            difference_type size_to_erase = &(*last) - &(*first);
            if (size_to_erase == 0)
                return (last);
            difference_type index = &(*first) - _begin;
            size_type       old_size = size();
            for (size_type i = index; i < old_size - (size_type) size_to_erase; i++)
            {
                _begin[i] = _begin[i + size_to_erase];
            }
            _end -= size_to_erase;
            for (size_type i = 0; i < (size_type) size_to_erase; i++)
            {
                _allocator.destroy(_end + i);
            }
            return (first);
        }

        void push_back(const T &value)
        {
            reserve(size() + 1);
            _allocator.construct(_end, value);
            _end++;
        }

        void pop_back()
        {
            if (_begin != _end)
            {
                _allocator.destroy(_end - 1);
                _end--;
            }
        }

        void resize(size_type count, T value = T())
        {
            reserve(count);
            size_type old_size = size();
            if (count < old_size)
            {
                for (size_type i = count; i < old_size; i++)
                {
                    _allocator.destroy(_begin + i);
                }
                _end = _begin + count;
            }
            else
            {
                size_type new_size = size();
                for (size_type i = new_size; i < count; i++)
                {
                    _allocator.construct(_begin + i, value);
                    _end++;
                }
            }
        }

        void swap(vector &other)
        {
            if (this == &other)
                return;

            allocator_type allocator = other._allocator;
            size_type      cap = other._cap;
            pointer        begin = other._begin;
            pointer        end = other._end;

            other._allocator = _allocator;
            other._cap = _cap;
            other._begin = _begin;
            other._end = _end;

            _allocator = allocator;
            _cap = cap;
            _begin = begin;
            _end = end;
        }
    };

    // Non-member functions
    template <typename T, class Allocator>
    bool operator==(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        for (size_t i = 0; i < lhs.size(); i++)
        {
            if (!(lhs[i] == rhs[i]))
                return (false);
        }
        return (true);
    }

    template <typename T, class Allocator>
    bool operator!=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
    {
        return (!(lhs == rhs));
    }

    template <typename T, class Allocator>
    bool operator<(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <typename T, class Allocator>
    bool operator<=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
    {
        return (lhs < rhs || lhs == rhs);
    }

    template <typename T, class Allocator>
    bool operator>(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
    {
        return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }

    template <typename T, class Allocator>
    bool operator>=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
    {
        return (lhs > rhs || lhs == rhs);
    }
} // namespace ft
namespace std
{
    template <typename T, class Allocator>
    void swap(ft::vector<T, Allocator> &lhs, ft::vector<T, Allocator> &rhs)
    {
        lhs.swap(rhs);
    }
} // namespace std

#endif
