# Binary Search Tree (BST)

## Description
Binary Search Tree (BST) is a binary tree data structure in which each node has a maximum of 2 subtrees where the left subtree contains nodes with smaller values ​​while the right subtree contains nodes with larger values.

Since the nodes are laid out holding these properties, BST can perform a fast lookup, insertion, or removal of data items using binary search which each comparison skips about a half of the remaining tree and makes it's performace is propotional to the binary logarithmic complexity. But still, any operations will have worst case complexity of ***O(h)*** where ***h*** is the height of the tree, since it doesn't have any balance assurance property like the [Self Balancing BST](https://github.com/zennv/Data-Structures/tree/main/Self%20Balancing%20BST).  

These following are some examples of the proper BST :  
  
| ![Untitled (18)](https://user-images.githubusercontent.com/105977864/209845389-f96119a7-9723-4217-93ac-2f1b30b8b5ff.jpg)| ![Untitled (20)](https://user-images.githubusercontent.com/105977864/209845831-997e660e-de2d-4a0e-80a6-8b140dcc8c85.jpg) |
|:---:|:---:|
| ![Untitled (21)](https://user-images.githubusercontent.com/105977864/209845971-42965b90-ee91-4e2c-ac4b-62ae79a63e66.jpg) | ![Untitled (23)](https://user-images.githubusercontent.com/105977864/209846446-36ef2a37-9ed4-460f-8596-05d033da44c8.jpg) |  

  
## Traversal
BST can be traversed in **three** different ways :
### 1. Preorder Traversal  
This is the basic traversal which prints every nodes in it's current path of the tree.    
Another way to represent this traversal is :  
***print - left - right***  

For example, if we want to traverse the top left tree image above, we will have :  
```
10 5 3 8 13 15
```  

### 2. Inorder Traversal  
As the name implies, this traversal will print you the nodes of the tree in ascending order.  
Another way to represent this traversal is :  
***left - print - right***  

For example, if we want to traverse the top left tree image abobve, we will have :  
```
3 5 8 10 13 15
```

### 3. Postorder Traversal  
This traversal is will print you the nodes of the tree from the bottom to the top.  
Another way to represent this traversal is :  
***left - right - print***  

For example, if we want to traverse the top left tree image above, we will have :  
```
3 8 5 15 13 10
```

You can find this tree's explicit implementation in C within the same folder as this file.  

Thanks, CMIIW :thumbsup:

