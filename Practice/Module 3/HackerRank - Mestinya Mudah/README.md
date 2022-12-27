# Mestinya Mudah (Should be Easy)

[HackerRank : Mestinya Mudah](https://www.hackerrank.com/contests/alpro-its-sd-m3-e-2022/challenges/mestinya-mudah)

## Description :
The problem is simple, we are given ***Q*** querys, and each query will followed by an integer ***N***. the querys are :  
***1 N*** &rarr; insert ***N*** into the tree.  
***2 N*** &rarr; print the index of ***N*** if it's in the tree.  
If it's not in the tree, print "Data tidak ada".  
> NOTE : It's an AVL Tree !  
  
## Input Formats :
The first line is the number of ***Q*** for this problem and the next ***Q*** lines are the querys.  

## Constraints :
- 1 &le; ***Q*** &le; 1000
- 1 &le; ***N*** &le; 10000  

## Output Formats :
The index of ***N*** if it's in the tree.  
If it isn't, print "Data tidak ada".  

## Input Sample :
```
15
1 120
1 108
1 207
2 120
1 203
2 111
1 79
2 79
1 291
1 48
2 48
1 68
1 1
2 291
1 26
```  

## Output Sample :
```
2
Data tidak ada
1
1
9
```  

## Explanation :
There are 15 querys, which is way too many to explain, so let me explain just the first 4 querys
```
1 120
1 108
1 207
2 120
```  
The first three querys start with 1, which means we're going to insert each number that comes after it one by one, 120 then 108 then 207. The next query starts with 2, which means we're going to look for the number that comes after it, 120, and since we have inserted it before, so we just need to print out it's index if it's traversed in inorder way, which is **2** (the order is 108, 120, 207).  

## Solution :
The point of this problem is that we have to print the index of the requested number if the tree is traversed in inorder way. So what we have to do is to traverse the tree in inorder way while saving the number temporarily in another data structure. So that after the traversing thing is done, we can look for the number in this other data structure we used and print the requested index.  

For the implementation, I use queue as my temporarily data structure since I need the FIFO property and I can reuse it as long as I need it. You can find the C implementation source code file within the same folder as this file, but if you're looking for the general implementation of an AVL tree, you can find it in the Self Balancing BST folder in the first page of this repository.