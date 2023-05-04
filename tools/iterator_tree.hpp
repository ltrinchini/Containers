#ifndef ITERATOR_TREE_HPP
#define ITERATOR_TREE_HPP

#include "Node.hpp"

#include <iterator>

namespace ft
{

    template <typename T, typename Distance, typename Pointer, typename Reference>
    class iterator_tree : public std::iterator<std::bidirectional_iterator_tag, T, Distance, Pointer, Reference>
    {
      public:
        typedef std::bidirectional_iterator_tag              iterator_category;
        typedef typename std::iterator<iterator_category, T> iterator_type;
        typedef typename iterator_type::value_type           value_type;
        typedef typename iterator_type::difference_type      difference_type;
        typedef typename iterator_type::pointer              pointer;
        typedef typename iterator_type::reference            reference;

        template <typename U, typename Dist, typename Pt, typename Rf>
        friend class iterator_tree;

		template <class Key, class U, class Compare, class Allocator >
   		friend class map;

		private:
			Node<value_type> *p;
			bool              isEnd;

      public:
        iterator_tree(void) : p(NULL), isEnd(true) {}

        template <class U>
        iterator_tree(Node<U> *x) : p((Node<T> *) x), isEnd(false)
        {
			if (!x) {
				isEnd = true;
			}
        }

        template <typename U, typename Dist, typename Pt, typename Rf>
        iterator_tree(const iterator_tree<U, Dist, Pt, Rf> &mit) : p((Node<T> *) mit.p), isEnd(mit.isEnd) // TODO je n'aime pas la facon du cast
        {
        }
        ~iterator_tree(void) {}

        template <class U, class Dist, class Pt, class Rf>
        iterator_tree<U, Dist, Pt, Rf> &operator=(const iterator_tree<U, Dist, Pt, Rf> &cpy)
        {
            p = cpy.p;
            isEnd = cpy.isEnd;
            return (*this);
        }

        template <typename U, typename Dist, typename Pt, typename Rf>
        bool operator==(const iterator_tree<U, Dist, Pt, Rf> &rhs) const
        {
            return (p == rhs.p && isEnd == rhs.isEnd);
        }

        template <typename U, typename Dist, typename Pt, typename Rf>
        bool operator!=(const iterator_tree<U, Dist, Pt, Rf> &rhs) const
        {
            return (p != (Node<T> *) rhs.p || isEnd != rhs.isEnd);
        }

        Reference operator*() const { return (p->data); }
        Pointer   operator->() const { return (&p->data); }

        iterator_tree &operator++()
        {
            Node<value_type> *tmp = p->getNext();
            if (tmp)
            {
                p = tmp;
            }
            else
            {
                isEnd = true;
            }
            return (*this);
        }

        iterator_tree operator++(int)
        {
            iterator_tree tmp(*this);

            operator++();
            return (tmp);
        }

        iterator_tree &operator--()
        {
            if (isEnd)
            {
                isEnd = false;
            }
            else
            {
                p = p->getPrev();
            }
            return (*this);
        }

        iterator_tree operator--(int)
        {
            iterator_tree tmp(*this);

            operator--();
            return (tmp);
        }
    };
} // namespace ft

#endif
