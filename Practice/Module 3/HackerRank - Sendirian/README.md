# Sendirian (Alone)

[HackerRank : Sendirian](https://www.hackerrank.com/contests/alpro-its-sd-m3-e-2022/challenges/sendirian)

### Description :
There are several new arrivals of adult age in the zoo. Since mating season is coming soon, these animals should be kept in a cage with their partner. Unfortunately, All these new arrivals came together in the same cage, so there is no guarantee that each of these animals will get their partner. Help the zoo officials to find every animals that don't have a partner!  

### Input Formats :
A line containing ***N*** which represents the number of the animals, followed by the next line containing ***N*** uppercase *char* which represents each animal.  

### Constraints :
1 &le; ***N*** &le; 1000

### Output Formats :
As many lines as the number of animals that don't get a mate (use AVL inorder traversal). If it's there's nothing, print "aman bang".

### Input Sample :
```
9
AABCCDDEF
```

### Output Sample :
```
B
E
F
```

### Explanation :
There are 9 animals, A, A, B, C, C, D, D, E, and F.  
And among those animals who have a partner are only A, C, and D.  
which means the rest of the remaining animals don't, namely B, E, and F.  

### Solution :
Since we're told to use the AVL's inorder traversal, so we will implement the AVL Tree to solve this problem. But the problem is, the input is in *char* data type while the general AVL Tree takes input in integer. So either we're going to convert these input into integer, or we're going to modify the tree so it will capable of taking a char input. well, I choose the first one at the time. C will automatically convert any char input into integer if we save it in an integer data structure based on it's [ASCII](https://id.wikipedia.org/wiki/ASCII) code.  

After it's saved in our integer data structure, we just need to insert each one of those into the tree **if** the data is not in the tree yet. If it is, then we're going to remove it from the tree. So that in the end, we will have only the unpaired animals left in the tree to print. You can find the C implementation source code file within the same folder as this file, but if you're looking for the general implementation of an AVL tree, you can find it in the Self Balancing BST folder in the first page of this repository.