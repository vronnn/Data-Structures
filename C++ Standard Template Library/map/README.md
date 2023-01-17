### `map` &rArr; An associative container that holds element in key-value form

| operations | purpose |
|:---|:---|
|`operator[]`| for accessing the value of a key  
`begin()` | to set an iterator pointing at the first element
`end()` | to set an iterator pointing at the last element plus one
`size()` | to get the number of elements in the map
`max_size()` | to get the maximum number of elements can be stored
`empty()` | to check if the map is empty (return ***true***) or not (return ***false***)
`swap(map)` | to swap the content of one map with another ***map*** with the same data type (size difference doesn't matter)
`insert({}/ make_pair(x,y)` | to insert a new ***key*** and it's ***value*** as a pair (allowed to use iterator as the first param to set the position)
`erase(key)` | to erase an existing ***key*** and it's ***value*** from the map 
`clear()` | to wipe out all of the existing elemen in the map (size became 0)
`find(key)` | to find the given key in the map (returns an iterator) 
`count(key)` | to find the number of element with the given ***key*** 

