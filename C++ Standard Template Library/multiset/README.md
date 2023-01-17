### `multiset` &rArr; set but with addition that multiple elements can have the same value 

| operations | purpose |
|:---|:---|
`begin()` | to set an iterator pointing at the first element
`end()` | to set an iterator pointing at the last element plus one
`size()` | to get the number of elements in the multiset
`max_size()` | to get the maximum number of elements can be stored
`empty()` | to check if the multiset is empty (return ***true***) or not (return ***false***)
`swap(multiset)` | to swap the content of one multiset with another ***multiset*** with the same data type (size difference doesn't matter)
`insert(v)` | to insert a new element (***v***) into the multiset
`erase(v)` | to erase an element (***v***) from the multiset
`clear()` | to wipe out all of the existing elemen in the multiset (size became 0)
`find(key)` | to find the given key in the map (returns an iterator) 
`count(key)` | to find the number of element with the given ***key***, but since each element is unique, this function will return ***1*** if ***key*** is found, and return ***0*** if it isn't
`swap(multiset)` | to swap the content of one multiset with another ***multiset***
`lower_bound(v)` | Returns an iterator that points to the biggest element in the multiset but no bigger than ***v***. If not present, it returns the last iterator.
`upper_bound(v)` | Returns an iterator that points to the smallest elements in the multiset but bigger than ***v***. If not present, it returns the last iterator.


