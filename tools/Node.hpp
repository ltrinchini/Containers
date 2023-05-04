/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:09:03 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/12/24 16:37:07 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>
#include <iostream>

template <class T>
class Node
{
  public:
    T        data;
    int      balance;
    Node<T> *parent;
    Node<T> *left;
    Node<T> *right;

    Node(void) : data(T()), balance(0), parent(NULL), left(NULL), right(NULL) {}
    Node(const T &data) : data(data), balance(0), parent(NULL), left(NULL), right(NULL) {}

    template <class U>
    Node(const Node<U> &other) : data(other.data), balance(other.balance), parent((Node<T> *) other.parent), left((Node<T> *) other.left), right((Node<T> *) other.right)
    {
    }

    ~Node(void) {}

    template <class U>
    Node &operator=(const Node<U> &cpy)
    {
        if (this == cpy)
            return (*this);
        data = cpy.data;
        parent = cpy.parent;
        left = cpy.left;
        right = cpy.right;
        return (*this);
    }

    Node *getLess(void)
    {
        Node *current = this;
        while (current->left)
            current = current->left;
        return (current);
    }

    Node *getMore(void)
    {
        Node *current = this;
        while (current->right)
            current = current->right;
        return (current);
    }

    Node *getPrev(void)
    {
        if (left)
        {
            return (left->getMore());
        }
        else
        {
            Node *buffer = this;
            while (buffer->parent)
            {
                if (buffer->parent->right == buffer)
                {
                    return (buffer->parent);
                }
                buffer = buffer->parent;
            }
            return (NULL);
        }
    }

    Node *getNext(void)
    {
        if (right)
        {
            return (right->getLess());
        }
        else
        {
            Node *buffer = this;
            while (buffer->parent)
            {
                if (buffer->parent->left == buffer)
                {
                    return (buffer->parent);
                }
                buffer = buffer->parent;
            }
            return (NULL);
        }
    }

    Node *getPtr(void) { return (this); }
};

#endif
