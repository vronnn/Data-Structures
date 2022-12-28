# Is This A Special Graph?

[HackerRank : Is This A Special Graph](https://www.hackerrank.com/contests/alpro-its-sd-m4-e-2022/challenges/is-this-a-special-graph)

### Description :
The point is that we are asked to check if some unweighted undirected graph is just a graph or a tree or a linked list.

### Input Formats :
The first line is ***T*** that represents the number of graph that needs to be checked, followed by ***V*** and ***E*** which each represents the number of vertex and the number of edges in the current graph, followed by the next ***E*** lines which each contain ***V<sub>1</sub>*** and ***V<sub>2</sub>*** which indicate the edges in the current graph.

### Constraints :
- 1 &le; ***T*** &le; 10
- 2 &le; ***V*** &le; 100
- ***V***-1 &le; ***E*** &le; 200

### Output Formats :
***T*** rows each containing **"This graph is a linked list"** if it can be classified as a linked list or **"This graph is a tree"** if it can be classified as a tree or **"This graph is a graph"** if it's just a basic graph.

### Input Sample :
```
3
4 3
1 2
2 3
3 4
5 4
1 2
1 3
3 4
3 5
4 4
1 2
1 3
3 4
2 3
```  
### Output Sample :
```
Graf ini adalah linked list
Graf ini adalah tree
Graf ini adalah graf biasa
```  
### Explanation :
There are **3** graphs, which are :
```
4 3
1 2
2 3
3 4
```  
Classified as linked list,  
<img width="442" alt="image" src="https://user-images.githubusercontent.com/105977864/209460991-10bacc8a-1185-43bc-b136-5e9ad1087166.png">  
  
Second graph :
```
5 4
1 2
1 3
3 4
3 5
```  
Classified as tree,  
<img width="359" alt="image" src="https://user-images.githubusercontent.com/105977864/209461006-f982fdaa-8e90-4d46-b100-e198926dc1c9.png">  
  
Third graph :
```
4 4
1 2
1 3
3 4
2 3
```  
Classified as a basic graph,  
<img width="348" alt="image" src="https://user-images.githubusercontent.com/105977864/209461031-19057ca1-48c2-49c3-b133-903c331a098d.png">  
  
### Solution :
First, we need to know what seperates graph from tree and from linked list. a linked list vertex can't have more than one edge while tree and graph can. and on the other side Tree can't have circular edges while graph can. These things are what seperates graph from them.  
  
So the next problem is how to check if a graph has more than one edge or not. This can be easily done by checking iteratively each vertex if they have more than an edge (or after saved in a data structure check if their size is more than 2). if they have, then they can't be a linked list, instead, they could be a tree or a graph. But if they don't, it means that they are a linked list. In this checkpoint, we can put a flag variable to keep track.  
  
Then we move on to the next problem, which is to check if a graph has circular edges or not. This can be done by using [DFS](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/) methods or [Depth First Search](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/). The idea is to traverse recursively each vertex and check if there are any conditions that the current traversed vertex are the same vertex with the first traversed vertex. This condition shows that there is a looping / circular edges that returns to the first traversed vertex after a several iterations. So if this condition is fulfilled, then this graph can't be a tree, it means that this graph is just a graph. We can put a boolean variable that immidiately return or break from the recursive loop and gives the values of true. But if until the end of the loop it doesn't break, it means that the boolean values will still be false and this graph can be classified as a tree. You can find the C++ implementation source code within the same folder as this file. 
  
Thanks, CMIIW :thumbsup: