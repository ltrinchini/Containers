/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:55:41 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/04 12:07:15 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../tools/Node.hpp"
#include "../tools/utility.hpp"
#include "../tools/iterator_tree.hpp"

#include <functional>
#include <limits>
#include <map>
#include <memory>
#include <unistd.h>

// Synopsis
// namespace ft
// {
//     template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
//     class map
//     {
//       public:
//         typedef Key                                                                                  key_type;
//         typedef T                                                                                    mapped_type;
//         typedef ft::pair<const Key, T>                                                               value_type;
//         typedef Allocator                                                                            allocator_type;
//         typedef typename allocator_type::size_type                                                   size_type;
//         typedef typename allocator_type::difference_type                                             difference_type;
//         typedef Compare                                                                              key_compare;
//         typedef typename allocator_type::reference                                                   reference;
//         typedef typename allocator_type::const_reference                                             const_reference;
//         typedef typename allocator_type::pointer                                                     pointer;
//         typedef typename allocator_type::const_pointer                                               const_pointer;
//         typedef ft::iterator_tree<value_type, difference_type, pointer, reference>                   iterator;
//         typedef ft::iterator_tree<const value_type, difference_type, const_pointer, const_reference> const_iterator;
//         typedef ft::reverse_iterator<iterator>                                                       reverse_iterator;
//         typedef ft::reverse_iterator<const_iterator>                                                 const_reverse_iterator;
//         class value_compare;

//         template <typename U, typename Dist, typename Pt, typename Rf>
//         friend class iterator_tree;

//       private:
//         typedef Node<value_type>                                      Node;
//         typedef typename allocator_type::template rebind<Node>::other allocator_node_type;
//         Node                                                         *_root;
//         size_type                                                     _size;
//         allocator_type                                                _allocator;
//         key_compare                                                   _comp;
//         value_compare                                                 _Vcomp;
//         allocator_node_type                                           _nodeAllocator;

//         // node and binary tree function
//         int   height(Node *node);
//         Node *rightRotate(Node *node);
//         Node *leftRotate(Node *node);
//         Node *rightLeftRotate(Node *node);
//         Node *leftRightRotate(Node *node);
//         void  rebalance(Node *node);
//         bool  is_anbalance(Node *node);
//         void  checkBalance(Node *node);
//         void  setBalance(Node *node, int value);
//         Node *add(Node *parent, const value_type &value);
//         Node *_getClosestNode(const Key &key, Node *node) const;
//         void  erase(Node *node);

//       public:
//         // Member functions
//         map(void);
//         explicit map(const Compare &comp = Compare(), const Allocator &alloc = Allocator());
//         template <class InputIt>
//         map(InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator &alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0);
//         map(const map &other);
//         ~map(void);
//         map           &operator=(const map &other);
//         allocator_type get_allocator(void) const;

//         // Element access
//         T       &at(const Key &key);
//         const T &at(const Key &key) const;
//         T       &operator[](const Key &key);

//         // Iterator
//         iterator               begin(void);
//         const_iterator         begin(void) const;
//         iterator               end(void);
//         const_iterator         end(void) const;
//         reverse_iterator       rbegin(void);
//         const_reverse_iterator rbegin(void) const;
//         reverse_iterator       rend(void);
//         const_reverse_iterator rend(void) const;

//         // Capacity
//         bool      empty(void) const;
//         size_type size(void) const;
//         size_type max_size(void) const;

//         // Modifiers
//         void                     clear(void);
//         ft::pair<iterator, bool> insert(const value_type &value);
//         iterator                 insert(iterator pos, const value_type &value);
//         template <class InputIt>
//         void      insert(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type *= 0);
//         iterator  erase(iterator pos);
//         iterator  erase(iterator first, iterator last);
//         size_type erase(const Key &key);
//         void      swap(map &other);

//         // Lookup
//         size_type                                count(const Key &key) const;
//         iterator                                 find(const Key &key);
//         const_iterator                           find(const Key &key) const;
//         iterator                                 lower_bound(const Key &key);
//         const_iterator                           lower_bound(const Key &key) const;
//         iterator                                 upper_bound(const Key &key);
//         const_iterator                           upper_bound(const Key &key) const;
//         ft::pair<iterator, iterator>             equal_range(const Key &key);
//         ft::pair<const_iterator, const_iterator> equal_range(const Key &key) const;

//         // Observers
//         key_compare key_comp(void) const;
//     };

//     // Non-member functions
//     template <class Key, class T, class Compare, class Alloc>
//     bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs);

//     template <class Key, class T, class Compare, class Alloc>
//     bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs);

//     template <class Key, class T, class Compare, class Alloc>
//     bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs);

//     template <class Key, class T, class Compare, class Alloc>
//     bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs);

//     template <class Key, class T, class Compare, class Alloc>
//     bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs);

//     template <class Key, class T, class Compare, class Alloc>
//     bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs);
// } // namespace ft

// namespace std
// {
//     template <class Key, class T, class Compare, class Alloc>
//     void swap(ft::map<Key, T, Compare, Alloc> &lhs, ft::map<Key, T, Compare, Alloc> &rhs);
// } // namespace std

#ifndef MAP_HPP
#define MAP_HPP

class value_compare;
namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
      public:
        typedef Key                                                                                  key_type;
        typedef T                                                                                    mapped_type;
        typedef ft::pair<const Key, T>                                                               value_type;
        typedef Allocator                                                                            allocator_type;
        typedef typename allocator_type::size_type                                                   size_type;
        typedef typename allocator_type::difference_type                                             difference_type;
        typedef Compare                                                                              key_compare;
        typedef typename allocator_type::reference                                                   reference;
        typedef typename allocator_type::const_reference                                             const_reference;
        typedef typename allocator_type::pointer                                                     pointer;
        typedef typename allocator_type::const_pointer                                               const_pointer;
        typedef ft::iterator_tree<value_type, difference_type, pointer, reference>                   iterator;
        typedef ft::iterator_tree<const value_type, difference_type, const_pointer, const_reference> const_iterator;
        typedef ft::reverse_iterator<iterator>                                                       reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                                                 const_reverse_iterator;

        class value_compare
        {
            friend class map;

          protected:
            key_compare comp;
            value_compare(key_compare c) : comp(c) {}

          public:
            typedef bool       result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;

            bool operator()(const value_type &lhs, const value_type &rhs) const { return (comp(lhs.first, rhs.first)); }
        };

      private:
        typedef Node<value_type>                                      Node;
        typedef typename allocator_type::template rebind<Node>::other allocator_node_type;

        Node               *_root;
        size_type           _size;
        allocator_type      _allocator;
        key_compare         _comp;
        value_compare       _Vcomp;
        allocator_node_type _nodeAllocator;

        // node and binary tree function
        int height(Node *node)
        {
            size_t i = 0;
            while (true)
            {
                if (!node)
                {
                    return (i);
                }
                else if (node->balance < 0)
                {
                    node = node->right;
                    i++;
                }
                else if (node->balance > 0)
                {
                    node = node->left;
                    i++;
                }
                else if (node->balance == 0)
                {
                    if (node->right)
                    {
                        node = node->right;
                    }
                    else
                    {
                        node = node->left;
                    }
                    i++;
                }
            }
        }

        Node *rightRotate(Node *node)
        {
            Node *tmp = node->left;
            node->left = tmp->right;
            if (node->left)
                node->left->parent = node;
            tmp->parent = node->parent;
            tmp->right = node;
            if (tmp->parent)
            {
                if (tmp->parent->left == node)
                {
                    tmp->parent->left = tmp;
                }
                else
                {
                    tmp->parent->right = tmp;
                }
            }
            node->parent = tmp;
            node->balance = height(node->left) - height(node->right);
            tmp->balance = height(tmp->left) - height(tmp->right);
            return (tmp);
        }

        Node *leftRotate(Node *node)
        {
            Node *tmp = node->right;
            node->right = tmp->left;
            if (node->right)
                node->right->parent = node;

            tmp->parent = node->parent;

            tmp->left = node;
            if (tmp->parent)
            {
                if (tmp->parent->left == node)
                {
                    tmp->parent->left = tmp;
                }
                else
                {
                    tmp->parent->right = tmp;
                }
            }
            node->parent = tmp;
            node->balance = height(node->left) - height(node->right);
            tmp->balance = height(tmp->left) - height(tmp->right);
            return (tmp);
        }

        Node *rightLeftRotate(Node *node)
        {
            node->right = rightRotate(node->right);
            if (node->left == node->right)
                node->left = NULL;
            node->right->parent = node;
            node = leftRotate(node);
            return (node);
        }

        Node *leftRightRotate(Node *node)
        {
            node->left = leftRotate(node->left);
            if (node->left == node->right)
                node->right = NULL;
            node->left->parent = node;
            node = rightRotate(node);
            return (node);
        }

        void rebalance(Node *node)
        {
            if (node->balance > 1)
            {
                if (node->left->balance > 0)
                {
                    node = rightRotate(node);
                }
                else
                {
                    node = leftRightRotate(node);
                }
            }
            else
            {
                if (node->right->balance < 0)
                {
                    node = leftRotate(node);
                }
                else
                {
                    node = rightLeftRotate(node);
                }
            }
            if (node->parent == NULL)
            {
                _root = node;
            }
        }

        bool is_anbalance(Node *node) { return (node->balance < -1 || node->balance > 1); }

        void checkBalance(Node *node)
        {
            if (is_anbalance(node))
            {
                rebalance(node);
            }
            if (node->parent == NULL)
                return;
            checkBalance(node->parent);
        }

        void setBalance(Node *node, int value)
        {
            node->balance += value;
            if (is_anbalance(node))
            {
                rebalance(node);
                return;
            }
            else if (node->parent)
            {
                if (node->parent->left == node)
                {
                    if (node->balance != 0 || (!node->left && !node->right))
                    {
                        setBalance(node->parent, 1);
                    }
                }
                else
                {
                    if (node->balance != 0 || (!node->left && !node->right))
                    {
                        setBalance(node->parent, -1);
                    }
                }
            }
        }

        Node *add(Node *parent, const value_type &value)
        {
            if (!_Vcomp(value, parent->data))
            {
                if (parent->right == NULL)
                {
                    try
                    {
                        parent->right = _nodeAllocator.allocate(1);
                    }
                    catch (const std::exception &e)
                    {
                        throw;
                    }
                    _nodeAllocator.construct(parent->right, value);
                    parent->right->parent = parent;
                    setBalance(parent, -1);
                    _size++;
                    return (parent->right);
                }
                else
                {
                    return (add(parent->right, value));
                }
            }
            else
            {
                if (parent->left == NULL)
                {
                    try
                    {
                        parent->left = _nodeAllocator.allocate(1);
                    }
                    catch (const std::exception &e)
                    {
                        throw;
                    }
                    _nodeAllocator.construct(parent->left, value);
                    parent->left->parent = parent;
                    setBalance(parent, 1);
                    _size++;
                    return (parent->left);
                }
                else
                {
                    return (add(parent->left, value));
                }
            }
        }

        Node *_getClosestNode(const Key &key, Node *node) const
        {
            if (!node)
            {
                return (NULL);
            }
            if (_comp(key, node->data.first))
            {
                if (node->left)
                {
                    return (_getClosestNode(key, node->left));
                }
            }
            else if (_comp(node->data.first, key))
            {
                if (node->right)
                {
                    return (_getClosestNode(key, node->right));
                }
            }
            return (node);
        }

        void erase(Node *node)
        {
            if (!node->left && !node->right)
            {
                if (node->parent)
                {
                    if (node->parent->left == node)
                    {
                        node->parent->left = NULL;
                        if (node->parent->right != NULL)
                        {
                            node->parent->balance += -1;
                        }
                    }
                    else if (node->parent->right == node)
                    {
                        node->parent->right = NULL;
                        if (node->parent->left != NULL)
                        {
                            node->parent->balance += 1;
                        }
                    }
                }
                else
                {
                    _root = NULL;
                }
                _nodeAllocator.destroy(node);
                _nodeAllocator.deallocate(node, 1);
                _size--;
                return;
            }
            else if (node->left && node->right)
            {
                Node *tmp = node->right;
                Node  buff;

                while (tmp->left)
                {
                    tmp = tmp->left;
                }

                if (tmp->parent == node)
                {
                    node->right = tmp->right;
                }
                else
                    tmp->parent->left = node;

                buff.parent = tmp->parent;
                buff.left = tmp->left;
                buff.right = tmp->right;
                buff.balance = tmp->balance;

                if (node->left)
                    node->left->parent = tmp;
                if (node->right && node->right->parent != tmp)
                    node->right->parent = tmp;
                else
                    node->right->parent = node;

                tmp->parent = node->parent;
                if (!tmp->parent)
                    _root = tmp;
                else
                    tmp->parent->right = tmp;
                tmp->left = node->left;
                if (tmp->right == node->right)
                {
                    tmp->right = node;
                }
                else
                {
                    tmp->right = node->right;
                }
                tmp->balance = node->balance;

                if (buff.parent == node)
                    node->parent = tmp;
                else
                    node->parent = buff.parent;

                node->left = buff.left;
                node->right = buff.right;
                node->balance = buff.balance;
                erase(node);
                return;
            }
            else // (!node->left || !node->right)
            {
                Node *childrenNode = node->left;
                if (node->right)
                    childrenNode = node->right;

                if (node->parent)
                {
                    childrenNode->parent = node->parent;
                    if (node->parent->left == node)
                    {
                        node->parent->left = childrenNode;
                        setBalance(node->parent, -1);
                    }
                    if (node->parent->right == node)
                    {
                        node->parent->right = childrenNode;
                        setBalance(node->parent, 1);
                    }
					_nodeAllocator.destroy(node);
                    _nodeAllocator.deallocate(node, 1);
                }
                else
                {
                    _nodeAllocator.destroy(node);
                    _nodeAllocator.deallocate(node, 1);
                    node = childrenNode;
                    childrenNode->parent = NULL;
                    _root = childrenNode;
                }
                _size--;
                return;
            }
            checkBalance(node);
        }
		
		void	deleteNodeRecursive(Node *node) {
			if (!node) {
				return;
			}
			deleteNodeRecursive(node->right);
			deleteNodeRecursive(node->left);
			_nodeAllocator.destroy(node);
			_nodeAllocator.deallocate(node, 1);
		}

      public:
        // Member functions
        explicit map(const Compare &comp = Compare(), const Allocator &alloc = Allocator()) : _root(NULL), _size(0), _allocator(alloc), _comp(comp), _Vcomp(comp) {}
        template <class InputIt>
        map(InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator &alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0) : _root(NULL), _size(0), _allocator(alloc), _comp(comp), _Vcomp(comp)
        {
            insert(first, last);
        }

        map(const map &other) : _root(NULL), _size(0), _allocator(other._allocator), _comp(other._comp), _Vcomp(other._Vcomp), _nodeAllocator(other._nodeAllocator) { insert(other.begin(), other.end()); }

        ~map(void) { clear(); }

        map &operator=(const map &other)
        {
            if (this == &other)
                return (*this);

            clear();

            _allocator = other._allocator;
            _nodeAllocator = other._nodeAllocator;
            _comp = other._comp;
            _root = NULL;

            insert(other.begin(), other.end());

            return (*this);
        }

        allocator_type get_allocator(void) const { return (_allocator); }

        // Element access
        T &at(const Key &key)
        {
            Node *closestNode = _getClosestNode(key, _root);

            if (!closestNode || _comp(key, closestNode->data.first) || _comp(closestNode->data.first, key))
            {
                throw std::out_of_range("map::at: key not found");
            }
            return (closestNode->data.second);
        }

        const T &at(const Key &key) const
        {
            Node *closestNode = _getClosestNode(key, _root);

            if (!closestNode || _comp(key, closestNode->data.first) || _comp(closestNode->data.first, key))
            {
                throw std::out_of_range("map::at: key not found");
            }
            return (closestNode->data.second);
        }

        T &operator[](const Key &key)
        {
            if (!count(key))
            {
                insert(ft::make_pair(key, T()));
            }
            return (find(key)->second);
        }

        // Iterator
        iterator begin(void)
        {
            if (_root)
            {
                return (_root->getLess());
            }
            return (iterator());
        }

        const_iterator begin(void) const
        {
            if (_root)
            {
                return (_root->getLess());
            }
            return (const_iterator());
        }

        iterator end(void)
        {
            if (_root)
            {
                return (++iterator(_root->getMore()));
            }
            return (iterator());
        }

        const_iterator end(void) const
        {
            if (_root)
            {
                return (++iterator(_root->getMore()));
            }
            return (const_iterator());
        }

        reverse_iterator       rbegin(void) { return (end()); }
        const_reverse_iterator rbegin(void) const { return (end()); }
        reverse_iterator       rend(void) { return (begin()); }
        const_reverse_iterator rend(void) const { return (begin()); }

        // Capacity
        bool      empty(void) const { return (_size == 0); }
        size_type size(void) const { return (_size); }
        size_type max_size(void) const
        {
            size_type       size = _allocator.max_size();
            difference_type max_diff = std::numeric_limits<difference_type>::max();
            if (size > (size_type) max_diff)
            {
                return (max_diff);
            }
            return (_allocator.max_size());
        }

        // Modifiers
        void clear(void)
        {
			deleteNodeRecursive(_root);
			_size = 0;
			_root = NULL;
        }

        ft::pair<iterator, bool> insert(const value_type &value)
        {
            // std::cout << "ajout de " << value.first << std::endl;
            Node *closestNode = _getClosestNode(value.first, _root);

            if (closestNode && !_comp(value.first, closestNode->data.first) && !_comp(closestNode->data.first, value.first))
            {
                return (ft::make_pair(closestNode, false));
            }
            return (ft::make_pair(insert(closestNode, value), true));
        }

        iterator insert(iterator pos, const value_type &value)
        {
            if (!_root)
            {
                try
                {
                    _root = _nodeAllocator.allocate(1);
                }
                catch (const std::exception &e)
                {
                    throw;
                }
                _nodeAllocator.construct(_root, value);
                _size++;
                return (_root);
            }
            if (!pos.p)
            {
                return (iterator(add(_root, value)));
            }
            Node *closestNode = _getClosestNode(value.first, pos.p);

            if (!_comp(value.first, closestNode->data.first) && !_comp(closestNode->data.first, value.first))
            {
                return (iterator(closestNode));
            }
            return (iterator(add(closestNode, value)));
        }

        template <class InputIt>
        void insert(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0)
        {
            for (iterator it = first; it != last; it++)
            {
                insert(*it);
            }
        }

        iterator erase(iterator pos)
        {
            iterator tmp = pos;
            tmp++;
            erase(pos.p);
            return (tmp);
        }

        iterator erase(iterator first, iterator last)
        {
            size_t dist = std::distance(first, last);

            for (size_t i = 0; i < dist; i++)
            {
                erase(first++);
            }
            return (end());
        }

        size_type erase(const Key &key)
        {
            for (iterator it = begin(); it != end(); it++)
            {
                if (it.p->data.first == key)
                {
                    erase(it.p->getPtr());
                    return (1);
                }
            }
            return (0);
        }

        void swap(map &other)
        {
            Node               *_buffRoot = _root;
            size_type           _buffSize = _size;
            allocator_type      _buffAllocator = _allocator;
            key_compare         _buffComp = _comp;
            allocator_node_type _buffNodeAllocator = _nodeAllocator;

            _root = other._root;
            _size = other._size;
            _allocator = other._allocator;
            _comp = other._comp;
            _buffNodeAllocator = _nodeAllocator;

            other._root = _buffRoot;
            other._size = _buffSize;
            other._allocator = _buffAllocator;
            other._comp = _buffComp;
            other._nodeAllocator = _buffNodeAllocator;
        }

        // Lookup
        size_type count(const Key &key) const
        {
            if (find(key) == end())
            {
                return (0);
            }
            return (1);
        }

        iterator find(const Key &key)
        {
            Node *ptr = _root;
            while (ptr != NULL)
            {
                if (key == ptr->data.first)
                    return (ptr);
                else if (_comp(key, ptr->data.first))
                {
                    ptr = ptr->left;
                }
                else
                {
                    ptr = ptr->right;
                }
            }
            return (end());
        }

        const_iterator find(const Key &key) const
        {
            Node *ptr = _root;
            while (ptr != NULL)
            {
                if (key == ptr->data.first)
                    return (ptr);
                else if (_comp(key, ptr->data.first))
                {
                    ptr = ptr->left;
                }
                else
                {
                    ptr = ptr->right;
                }
            }
            return (end());
        }

        iterator lower_bound(const Key &key)
        {
			if (!_root) {
				return (end());
			}
			
			Node *tmp = _getClosestNode(key, _root);
			iterator ret(tmp);
			if (_comp(tmp->data.first, key)) {
				ret++;
			}
			return (ret);
            // iterator it;
            // for (it = begin(); it != end(); it++)
            // {
            //     if (!_comp(it.p->data.first, key))
            //     {
            //         return (it);
            //     }
            // }
            // return (end());
        }

        const_iterator lower_bound(const Key &key) const
        {
			if (!_root) {
				return (end());
			}
			
			Node *tmp = _getClosestNode(key, _root);
			const_iterator ret(tmp);
			if (_comp(tmp->data.first, key)) {
				ret++;
			}
			return (ret);
            // const_iterator it;
            // for (it = begin(); it != end(); it++)
            // {
            //     if (!_comp(key, it.p->data.first))
            //     {
            //         return (it);
            //     }
            // }
            // return (end());
        }

        iterator upper_bound(const Key &key)
        {
			if (!_root) {
				return (end());
			}
			
			Node *tmp = _getClosestNode(key, _root);
			iterator ret(tmp);
			if (!_comp(key, tmp->data.first)) {
				ret++;
			}
			return (ret);
            // iterator it;
            // for (it = begin(); it != end(); it++)
            // {
            //     if (_comp(key, it.p->data.first))
            //     {
            //         return (it);
            //     }
            // }
            // return (end());
        }

        const_iterator upper_bound(const Key &key) const
        {
			if (!_root) {
				return (end());
			}
			
			Node *tmp = _getClosestNode(key, _root);
			const_iterator ret(tmp);
			if (!_comp(key, tmp->data.first)) {
				ret++;
			}
			return (ret);
            // const_iterator it;
            // for (it = begin(); it != end(); it++)
            // {
            //     if (_comp(key, it.p->data.first))
            //     {
            //         return (it);
            //     }
            // }
            // return (end());
        }

        ft::pair<iterator, iterator>             equal_range(const Key &key) { return (ft::make_pair(lower_bound(key), upper_bound(key))); }
        ft::pair<const_iterator, const_iterator> equal_range(const Key &key) const { return (ft::make_pair(lower_bound(key), upper_bound(key))); }

        // Observers
        key_compare key_comp(void) const { return (_comp); }
    };

    // Non-member functions
    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        typename ft::map<Key, T, Compare, Alloc>::const_iterator itLhs;
        typename ft::map<Key, T, Compare, Alloc>::const_iterator itRhs;
        for (itLhs = lhs.begin(), itRhs = rhs.begin(); itLhs != lhs.end() && itRhs != rhs.end(); itLhs++, itRhs++)
        {
            if (!(*itLhs == *itRhs))
                return (false);
        }
        return (true);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return (!(lhs == rhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return (lhs < rhs || lhs == rhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return (lhs > rhs || lhs == rhs);
    }
} // namespace ft

namespace std
{
    template <class Key, class T, class Compare, class Alloc>
    void swap(ft::map<Key, T, Compare, Alloc> &lhs, ft::map<Key, T, Compare, Alloc> &rhs)
    {
        lhs.swap(rhs);
    }
} // namespace std

#endif
