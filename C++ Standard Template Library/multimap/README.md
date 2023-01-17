### `multimap` &rArr; map with the addition that multiple elements can have the same key

| operations | purpose |
|:---|:---|
|`operator[]`| for accessing the value of a key  
`begin()` | to set an iterator pointing at the first element
`end()` | to set an iterator pointing at the last element plus one
`size()` | to get the number of elements in the multimap
`max_size()` | to get the maximum number of elements can be stored
`empty()` | to check if the multimap is empty (return ***true***) or not (return ***false***)
`swap(multimap)` | to swap the content of one multimap with another ***multimap*** with the same data type (size difference doesn't matter)
`insert({}/ make_pair(x,y)` | to insert a new ***key*** and it's ***value*** as a pair (allowed to use iterator as the first param to set the position)
`erase(key)` | to erase an existing ***key*** and it's ***value*** from the multimap 
`clear()` | to wipe out all of the existing elemen in the multimap (size became 0)
`find(key)` | to find the given key in the multimap (returns an iterator) 
`count(key)` | to find the number of element with the given ***key***
`lower_bound(v)` | Returns an iterator that points to the biggest element in the set but no bigger than ***v***. If not present, it returns the last iterator.
`upper_bound(v)` | Returns an iterator that points to the smallest elements in the set but bigger than ***v***. If not present, it returns the last iterator. 


