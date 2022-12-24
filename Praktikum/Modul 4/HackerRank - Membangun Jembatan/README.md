# Membangun Jembatan (Building Bridges)
## Description :
We are asked to help Yuta to count how many different bridges does the local government need to build to connect every population center (represented as the vertex) to the nearest consession (represented as the edge) with the given data in the form of a graph? (not include the bridge from the first vertex)

### input :
```
6 3  
1 2  
3 4  
5 6  
```

### output :
```
2
```  

### Explanation :
`6 3`  
  
it means that we have 6 vertices with 3 edges total, there are :
  
`1 2` , `3 4` , and `5 6`  
  
so we need **3** bridges to build, as following picture,  

<img width="428" alt="image" src="https://user-images.githubusercontent.com/105977864/209446075-1eafba6d-268d-4026-88ed-6d9cdb447ddb.png">  
  
but since we exclue the main bridge (from vertex *1*), we just need to build **2** bridges only, which is to connect `3 4` and `5 6`.

<br>

## Solution :
We can see right away from the problem stated that this is a graph material problem, therefore, we can simply just choose graph as our data structure (undirected, as shown in the picture). So the next problem is to count how much bridges should the government build to achieve their plans. We can solve this problem using [DFS](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/) or [Depth First Search](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/). Why? it's because we only need to count the number of vertices that have no connection at all yet to other vertices, or in other words, a vertex that hasn't been visited yet.  

By using DFS, we can mark every edges that has a connection with the current traversed vertex, whether it's directly or undirectly, recursively as visited at onces with only 1 bridge to build or connect. we can do this by looping through each vertex and see if it has been visited or not. if it hasn't, then we need to build a bridge to connect it with it's edges recursively and mark them all as visited. After that, we can increment the tracking variable (bridges) by 1. But if it has been visited, then we don't need to build any bridges, because they're already connected with other vertex and then we can move on to the next vertex.  

With this approach, there will be no vertex in the graph that hasn't been connected yet to at least one other vertex (implicitly) by bridges and we will have the number of bridges that needs to be build saved in the tracking variable by the end of the loop. but since we don't need to include the main bridge (from the vertex), we can substract the last result by 1. You can see the C++ implementation source code in the same folder as this file.

Thanks, CMIIW :thumbsup: