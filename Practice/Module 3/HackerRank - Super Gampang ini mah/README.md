# Super Gampang ini mah (This is Super Easy)

[HackerRank : Super Gampang ini mah](https://www.hackerrank.com/contests/alpro-its-sd-m3-e-2022/challenges/super-gampang-ini-mah)

### Description :  
Given a series of numbers as follows  
```
4, 24, 43, 64, 84, 103, 124, 144, 163 ...
```  
and ***N*** inputs of integers ***a***. We are asked to 
take the value in the sequence based on the a<sup>th</sup> order and insert it into the tree (it's a balanced BST).  

### Input Formats :
The first line is ***N*** which represents how many numbers we're going to put into the tree, and the next line is ***N*** integers (***a***) which is going to be the order of the numbers in the sequence to be inserted.  

### Constraints :
***N*** and ***a*** are integers.  

### Output Formats :
Print the contents of the tree after all insertions in order.  

### Input Sample :
```
6
1 2 3 4 5 6
```

### Output Sample :
```
4 24 43 64 84 103 
```  

### Explanation :  
There are six numbers to be inserted, which are the first, second, third, fourth, fifth, and sixth order of the sequence.  
1 &rarr; 4  
2 &rarr; 24  
3 &rarr; 43  
4 &rarr; 64  
5 &rarr; 84  
6 &rarr; 103  
and since it's in order, then we just have to print them all directly.  

### Solution : 
Since it's just an insert and print command of the AVL Tree (stated in the problem that the tree is a balanced BST), then what we actually need to concern is how to complete the sequence to be the right one. After a few observation, i found out that this sequence is just an arithmetic sequence with the first term of 4 and a common difference of 20, but with a little twist on every multiple of 3, which we have to substract it by 1. So if i generate the first fifteen numbers in the sequence, it will be something like this,  

| i | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| n | 4 | 24 | 43 | 64 | 84 | 103 | 124 | 144 | 163 | 184 | 204 | 223 | 244 | 264 | 283 |  

So it's done. We just have to insert the correct order of the sequence into the tree and then print it in order. You can find the C implementation source code file within the same folder as this file, but if you're looking for the general implementation of an AVL tree, you can find it in the Self Balancing BST folder in the first page of this repository.