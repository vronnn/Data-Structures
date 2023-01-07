# Self Balancing BST
Self Balancing BST are height-balanced [binary search tree]() that automaticaly keeps their height as small as possible when insertion and deletion operations are performed on these trees.  

It is possible since these operations were designed with precautionary measures against boundlessly increasing tree height property that maintains their height to be logarithmic, so all of these operations will take O(log n) time on average.  

There are several trees that apply this Self Balancing BST concept, some of them are :  
***Red-Black Tree, AVL Tree, and B-Tree.***

<br>

## Red-Black Tree
A Red-Black Tree is a self balancing BST where each node stores an extra bit to represent their color (red or black). These colors are used to ensure that the tree remains balanced during insertion and deletion. So when the tree is modified, their nodes will be recolored and rearranged to restore coloring properties that they hold in order to prevent the worst case scenario of unbalanced tree.  

Although this tree's re-balancing mechanism isn't perfect, it still guarantees us with an ***O(log n)*** time of searching, where ***n*** is the number of stored elements.  

**The following are some of the properties that must be satisfied by any Red-Black Tree :**
1. Every node is either **red** or **black**.
2. The root of the tree is always **black**.
3. There are **no two adjacent red nodes** (a red node cannot have a red parrent or a red child).
4. All leaf nodes (***null***) are considered **black**
5. Every path from a given node (including root) to any of it's descendant's ***null*** nodes goes through same number of black nodes.  
  
To make it easier to understand, let me draw you an example of the Red-Black Tree,  

Red-Black Tree |
:-------------:|
![Untitled (17)](https://user-images.githubusercontent.com/105977864/209514636-df86b4e5-0140-48d2-b351-81166cfbb4db.jpg)|  
  
This tree in the picture above satisfies all five rules previously mentioned, let's prove it!  
1. We can see that every node in those tree is either red or black.
2. And the root (13) is black-colored.
3. We can also see that there are no red nodes adjacent to each other.
4. And all the leaf nodes (null) are black.
5. To prove this point, let's choose one starting node as example, the root 13. And we're also gonna need some of the root's descendent null node, let's say 6, 15, and 22.  
The paths from 13 to it's three descendent's we've chosen are as follows :   
13 &rarr; 8 &rarr; 1 &rarr; 6  
13 &rarr; 17 &rarr; 15  
13 &rarr; 17 &rarr; 25 &rarr; 22  
Now, we count the number of black nodes on each of these paths :  
13 &rarr; 8 &rarr; 1 &rarr; 6&emsp;&emsp;&emsp;&rArr; 2 black nodes (13, 1)  
13 &rarr; 17 &rarr; 15&emsp;&emsp;&emsp;&ensp; &rArr; 2 black nodes (13, 15)  
13 &rarr; 17 &rarr; 25 &rarr; 22&emsp;&nbsp;&rArr; 2 black nodes (13, 25)  
So, it's proven. To get from 13 to any of it's descendent null node, we need exactly 2 black nodes to go through.  

<br>

## AVL Tree  
An AVL tree (Adelson-Velsky and Landis Tree) is also a self Balancing BST where they keep the difference in height between left and right subtrees to a maximum of 1 for any nodes. This height-differences on each node that they mantain every time an insertion or deletion operations is performed is called the ***balance-factor*** which value is either ***-1, 0, or 1***. If it's not one of these three, then they need to re-balance the tree to restore the ***balance-factor*** property that they hold to prevent the worst case scenario of unbalanced tree.  

This tree is more balance than the Red-Black Tree, which means, it saves us more time when it comes to searching operation. But it may cost more rotations during insertion and deletion operations. So if your program involves more frequent insertion and deletion, then Red-Black Tree is your option, but if your program involves more frequent seaching operations, then AVL tree is the right choice  

These are some example for the correct and incorrect AVL Tree based on their node's balance factor :
  
AVL Tree             |  Not AVL Tree
:-------------------------:|:-------------------------:
![Untitled (14)](https://user-images.githubusercontent.com/105977864/209507703-92cd6e94-cb33-4e44-9395-1916886409ff.jpg)  |  ![Untitled (15)](https://user-images.githubusercontent.com/105977864/209508161-2849fb6f-874f-482f-8bf9-fbf8d827b34a.jpg)  
  
We can see that in the left tree, each node keeps it's balance factor around -1, 0, and 1. which means that the height of every subtrees in it is perfectly balanced. While in the other hand, the root of the right tree has a balance factor of 2, which means that there is an inbalanced height differences between left and right substree. That's why the left tree is considered as an AVL Tree while the right one isn't.  
  
## Comparison
| AVL Tree | Red-Black Tree |
|:--------------:|:--------------:|
| Strictly Balanced makes it more balanced | Roughly Balanced makes it less balanced|
| Faster searching operation | Slower searching operation |
| Slower insertion and deletion | Faster insertion and deletion |
| Slower rebalancing process (cost lots of rotations)| Faster rebalancing process (max 2 rotations)|
| Using balance factor as indicator (takes more memory) | Using color as indicator (takes less memory) |
| Used for programs that require fast searches such as databases | Used in most of the language libraries, like map, mulitmap, multiset in C++ |  
  
You can find both tree's explicit implementation in C++ within the same folder as this file.  

Thanks, CMIIW :thumbsup:
