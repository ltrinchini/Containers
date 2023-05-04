# Container

## About

In C++, a container is a class that stores and organizes elements of a certain data type. The three most commonly used **container** types are:

- Vector
- Map
- Stack

To gain a deep understanding of how they work, I programmed these containers using **C++98**.

## Vector

The vector is a dynamic array container that can be automatically resized when it is necessary to add or remove elements. The elements of the vector are stored contiguously in memory, which facilitates access to each element by its index.


## Map

The map is a dictionary-type container that stores elements as key-value pairs. Each element is associated with a unique key that can be used to access the corresponding value. The elements of the map are automatically sorted in ascending order based on their key.

I also programmed an AVL Tree which is a balanced binary search tree data structure. In an AVL tree, the height difference between the left and right sub-trees of a node is at most 1, ensuring logarithmic execution time for search, insertion, and deletion operations. However, the available functions for the AVL Tree in C++98 depend on the specific implementation.

<div style="display" align="center">
<img src="./rscs/AVL_Tree_Example.gif">
</div>


## Stack

The stack is a Last In First Out (LIFO) container that stores elements in the order they were added. Elements can only be added or removed from the top of the stack, ensuring that the last element added is the first to be removed.

## Other functions
I also programmed this functions:
````C
std::iterators_traits
std::reverse_iterator
std::enable_if
std::is_integral
std::lexicographical_compare
std::pair
std::make_pair
````

## Getting Started
To get started, clone the repository using the following command:
````bash
git clone git@github.com:ltrinchini/Containers.git
````

# Usage

To use my containers, simply include the headers:

```C
#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"
```

And use them by specifying the `ft` namespace:

```C
ft::vector
ft::map
ft::stack
```

You can find a `main.cpp` in this project to see the containers in action.
