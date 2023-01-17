# C++ Standard Template Library (STL) ***Containers***

## Descriptions
The ***Standard Template Library*** (STL) is a library of generic algorithms and data structures for C++ with 4 consituent components, ***algorithm, container, function, and iterator***. These components are meant to simplify our efforts to implements any kinds of useful data structures in various scenarios.

## Components

- ***Algorithm*** is a set of instruments that we can use to perform various activities and operations such as *sorting*, *searching*, and *partitioning* on our ***containers*** with ease, such as `sort`, `find`, and `upper_bound`.

- ***Containers*** is a set of ***template classes*** which acts as a holder object that allows us to stores data in it. There are 3 types of containers,  
    - ***Sequence containers*** allows us to access it sequentially, includes  
`array`, `vector`, `deque`, `forward_list`, and `list`.  
    - ***Associative containers*** are sorted data structures which allows us to to perform a fast lookup, includes  
`set`, `map`, `multiset`, and `mulitmap`  
    - ***Container adaptors*** are sequence containers with different interfaces and different features, includes  
`stack`, `queue`, and `priority_queue`  

- ***Functions*** in STL is called functors or function objects, which is the term for an instance of classes that overload the function call operator, `operator()`. Functors allow the behavior of the associated function to be parameterized (e.g. through arguments passed to the functor's constructor). But it's more often used in [Object Oriented Programming]().

- ***Iterators*** is basically a pointer to alter any pointed values in our data structure. It is used in ***algorithms***, ***functions***, and ***containers*** component generally. But we can also use it manually to our will. You can find each container's detail explanations and it's C++ implementation within their respective folder in this repository.

Thanks, CMIIW :thumbsup: