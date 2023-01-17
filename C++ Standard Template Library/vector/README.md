### `vector` &rArr; A **dynamic** vector (the size is adjusting the number of elements)  

| operations | purpose |
|:---|:---|
|`operator[]`| for accessing element in spesific index  
`at()`| for accessing element in spesific index while checking it's size limit. If the index is beyond the limit, then it will print ***"out_of_range"***
`front()`| for accessing element in the first index
`back()` | for accessing element in the last index
`begin()` | to set an iterator pointing at the first element
`end()` | to set an iterator pointing at the last element plus one
`size()` | to get the number of elements in the vector
`resize(n)` | to resize the vector to a specified number of elements (***n***)
`assign(n,v)` | to resize the vector to (***n***) and fill all the index with a certain value (***v***)
`empty()` | to check if the vector is empty (return ***true***) or not (return ***false***)
`swap(vector)` | to swap the content of one vector with another ***vector*** with the same data type (size difference doesn't matter)
`push_back(v)` | to insert an elemen (***v***) at the last position
`pop_back()` | to erase an elemen at the last position
`insert(it,v/it,n,v)` | to insert element/s (***v***) at a specific position (pointed by ***it***) or range (as much as ***n***)
`erase(it/it1,it2)` | to erase element/s at a specific position (pointed by ***it***) or range (from ***it1*** &rarr; ***it2***)
`clear()` | to wipe out all of the existing elemen in the vector (size became 0)
`sort(l,r)` | sorting all elements inside in descending order at a given range [l,r]
`lower_bound(l,r,v)` | Returns an iterator that points to the biggest element in the range [l,r] but no bigger than ***v***. If not present, it returns the last iterator.
`upper_bound(l,r,v)` | Returns an iterator that points to the smallest elements in the range [l,r] but bigger than ***v***. If not present, it returns the last iterator.
