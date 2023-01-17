### `deque` &rArr; shorts for "double-ended queue (two entrances and two exits)

| operations | purpose |
|:---|:---|
|`operator[]`| for accessing element in spesific index  
`at()`| for accessing element in spesific index while checking it's size limit. If the index is beyond the limit, then it will print ***"out_of_range"***
`front()`| for accessing element in the first index
`back()` | for accessing element in the last index
`begin()` | to set an iterator pointing at the first element
`end()` | to set an iterator pointing at the last element plus one
`size()` | to get the number of elements in the deque
`max_size()` | to get the maximum number of elements can be stored
`resize(n)` | to resize the deque to a specified number of elements (***n***)
`assign(n,v)` | to resize the deque to (***n***) and fill all the index with a certain value (***v***)
`empty()` | to check if the deque is empty (return ***true***) or not (return ***false***)
`swap(deque)` | to swap the content of one deque with another ***deque*** with the same data type (size difference doesn't matter)
`push_front(v)` | to insert an element ***v*** at the first position
`pop_front()` | to erase an element at the first position
`push_back(v)` | to insert an element (***v***) at the last position
`pop_back()` | to erase an element at the last position
`insert(it,v/it,n,v)` | to insert element/s (***v***) at a specific position (pointed by ***it***) or range (as much as ***n***)
`erase(it/it1,it2)` | to erase element/s at a specific position (pointed by ***it***) or range (from ***it1*** &rarr; ***it2***)
`clear()` | to wipe out all of the existing element in the deque (size became 0)
`lower_bound(l,r,v)` | Returns an iterator that points to the biggest element in the range [l,r] but no bigger than ***v***. If not present, it returns the last iterator.
`upper_bound(l,r,v)` | Returns an iterator that points to the smallest elements in the range [l,r] but bigger than ***v***. If not present, it returns the last iterator.


