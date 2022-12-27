# Mencari Ayah (Looking For Father)

[HackerRank : Mencari Ayah](https://www.hackerrank.com/contests/alpro-its-sd-m3-e-2022/challenges/mencari-ayah-1)

## Description :
Yuta is curious about his relatives and ancestors. Luckily, he just received his family tree that has the form of a balanced Binary Search Tree. But since the tree is too big, he needs our help to find out the parents of his relatives.  

## Input Formats :
The first line is ***N*** which represents the number of his family member, followed by ***N*** integers for each family member, and the next line is ***Q*** which represents the number of his relatives that we're going to help to find out who their parents are, followed by ***Q*** lines for each relatives.  

## Constraints :
- 1 &le; ***Q<sub>i</sub>*** &le; ***N<sub>i</sub>*** &le; 1000
- 1 &le; ***Q*** , ***N*** &le; 1000  

## Output Formats :
***Q*** lines, which each contains the relatives's parent and the relative's name. If the relative's father is not found, outputs "Yah ga ketemu D:"  

## Input Sample :
```
10
1 2 3 4 5 6 7 8 9 10
5
1
2
4
6
8
```  

## Output Sample :  
```
2 1
4 2
Yah ga ketemu D: 4
8 6
4 8
```  

## Explanations :  
Here is the form of the family tree in this case :  
  
<img width="626" alt="image" src="https://user-images.githubusercontent.com/105977864/209627654-802724f9-0f1a-4b1c-8b82-0b5ebdbb6da9.png">  
  
There are 5 relative's we need to help :  
1 &rArr; 2  
2 &rArr; 4  
4 &rArr; the tree root, doesn't have parent  
6 &rArr; 8  
8 &rArr; 4  

## Solution :  
The idea to solve this problem is by traversing the relative's position while keeping track of it's parent using the AVL tree (stated in the problem that the tree has the form of balanced BST). This can be done by using 2 pointers, one's for the relative and one's for it's parent. The parent's pointer will move one step behind following the relative's pointer. That way, we can figure out whoever's parent that currently being traversed by the relative's pointer. So when we have found the relative's position, we will also have it's parent position pointed by the other pointer. Then, we just got to print them both. You can find the C implementation source code file within the same folder as this file, but if you're looking for the general implementation of an AVL tree, you can find it in the Self Balancing BST folder in the first page of this repository.  

Thanks, CMIIW :thumbsup: