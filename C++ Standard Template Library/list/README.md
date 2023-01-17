### `list` &rArr; two ways container (two entrances & exits) with extended features

| operations | purpose |
|:---|:---|
|`operator[]`| for accessing element in spesific index  
`at()`| for accessing element in spesific index while checking it's size limit. If the index is beyond the limit, then it will print ***"out_of_range"***
`front()`| for accessing element in the first index
`back()` | for accessing element in the last index
`begin()` | to set an iterator pointing at the first element
`end()` | to set an iterator pointing at the last element plus one
`size()` | to get the number of elements in the list
`max_size()` | to get the maximum number of elements can be stored
`resize(n)` | to resize the list to a specified number of elements (***n***)
`assign(n,v)` | to resize the list to (***n***) and fill all the index with a certain value (***v***)
`empty()` | to check if the list is empty (return ***true***) or not (return ***false***)
`swap(list)` | to swap the content of one list with another ***list*** with the same data type (size difference doesn't matter)
`push_front(v)` | to insert an element ***v*** at the first position
`pop_front()` | to erase an element at the first position
`push_back(v)` | to insert an element (***v***) at the last position
`pop_back()` | to erase an element at the last position
`emplace(it,v)` | to insert a new element (v) inside the list at pointed position (it)
`emplace.front(v)` | to insert a new element (v) inside the list at the first position
`emplace.back(v)` | to insert a new element (v) inside the list at the last position
`insert(it,v/it,n,v)` | to insert element/s (***v***) at a specific position (pointed by ***it***) or range (as much as ***n***)
`erase(it/it1,it2)` | to erase element/s at a specific position (pointed by ***it***) or range (from ***it1*** &rarr; ***it2***)
`clear()` | to wipe out all of the existing element in the list (size became 0)
`reverse()` | to reverse the order of elements inside the list
`sort(l,r)` | sorting all elements inside in descending order at a given range [l,r]
`merge(list)` | to merge a list with another ***list***
`splice(it,list,it1,it2)` | to transfer selected element/s at given range [it1-it2] from ***list*** to a position pointed by ***it*** (can be 2 or 3 parameters)
`unique()` | to erase all duplicated elements and leaving only unique elements
`remove(v)` | to remove every ***v*** found in the list
`remove_if(pred)` | removes elements that match the conditions given


