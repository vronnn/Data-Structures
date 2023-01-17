### `forward_list` &rArr; one way container (one entrance & exit) 

| operations | purpose |
|:---|:---|
`assign({v})` | to insert element/s ({v}) into the forward_list
`front()`| for accessing element in the first index
`begin()` | to set an iterator pointing at the first element
`end()` | to set an iterator pointing at the last element plus one
`max_size()` | to get the maximum number of elements can be stored
`resize(n)` | to resize the forward_list to a specified number of elements (***n***)
`empty()` | to check if the forward_list is empty (return ***true***) or not (return ***false***)
`swap(forward_list)` | to swap the content of one forward_list with another ***forward_list*** with the same data type (size difference doesn't matter)
`push_front(v)` | to insert an element ***v*** at the first position
`pop_front()` | to erase an element at the first position
`emplace_after(it,v)` | to insert a new element (***v***) inside the forward_list at the after pointed position
`emplace_front(v)` | to insert a new element (***v***) inside the forward_list at the first position
`insert_after(it,n,v)` | to insert element/s (***v***) inside the forward_list at the after pointed position (by ***it***) as much as ***n*** (optional)
`erase_after(it/it1,it2)` | to erase element/s at the after pointed position (by ***it***) or range (from after ***it1*** &rarr; ***it2***)
`clear()` | to wipe out all of the existing element in the forward_list (size became 0)
`reverse()` | to reverse the order of elements inside the forward_list
`merge(forward_list)` | to merge a forward_list with another ***forward_list***
`splice_after(it,forward_list,it1,it2)` | to transfer selected element/s at given range [it1-it2] from ***forward_list*** to a position pointed by ***it*** (can be 2 or 3 parameters)
`unique()` | to erase all duplicated elements and leaving only unique elements
`remove(v)` | to remove every ***v*** found in the forward_list
`remove_if(pred)` | removes elements that match the conditions given


