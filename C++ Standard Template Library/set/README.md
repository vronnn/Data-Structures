### `set` &rArr; A **dynamic** associative container that holds element uniquely in key-value form where the key is the value 

| operations | purpose |
|:---|:---|
`begin()` | to set an iterator pointing at the first element
`end()` | to set an iterator pointing at the last element plus one
`size()` | to get the number of elements in the set
`max_size()` | to get the maximum number of elements can be stored
`empty()` | to check if the set is empty (return ***true***) or not (return ***false***)
`swap(set)` | to swap the content of one set with another ***set*** with the same data type (size difference doesn't matter)
`insert(v)` | to insert a new element (***v***) into the set
`erase(v)` | to erase an element (***v***) from the set
`clear()` | to wipe out all of the existing elemen in the set (size became 0)
`find(key)` | to find the given key in the map (returns an iterator) 
`count(key)` | to find the number of element with the given ***key***, but since each element is unique, this function will return ***1*** if ***key*** is found, and return ***0*** if it isn't
`lower_bound(v)` | Returns an iterator that points to the biggest element in the set but no bigger than ***v***. If not present, it returns the last iterator.
`upper_bound(v)` | Returns an iterator that points to the smallest elements in the set but bigger than ***v***. If not present, it returns the last iterator.

