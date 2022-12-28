# RahelChan pen Liburan (RahelChan Wants a Vacation)

[HackerRank : RahelChan pen Liburan](https://www.hackerrank.com/contests/alpro-its-sd-m4-e-2022/challenges/rahelchan-pen-liburan)

### Description :
RahelChan wants to go on a vacation with his friends, Pawel. But Pawel doesn't want to go for a long walk circuit route. So we have to help RahelChan to find the shortest circuit route.  
>FYI : circuit route are a walking route where three or more places are connected to each other.  

The itinerary planned by Rahel consists of ***X*** places marked with indexes ***0*** to ***X-1*** which are connected by two-way roads (assume the distance between places is the same) (**undirected & unweighted**) for a number of ***Y***. It is not guaranteed that every place will be connected to other places.  

### Input Formats :  
The first line is ***X*** which represents the number of places included in Rahel's itinerary. The second line is ***Y*** which represents the number of way that connects two places and the next ***Y*** lines contain ***A*** and ***B*** which represents the places connected by each of those ways.  

### Constraints :
- 2 < ***X*** < 10002 < ***Y*** < 20000 < ***A,B*** < ***X***  

### Output Formats :
An integer indicating the number of places that must be reached for the shortest circuit route. If no route is found, output "gamau gasuka gelay" without the quotation marks.  

### Input Sample 0 :
```
7
6
1 6
6 4
6 2
2 0
2 3
0 5
```  

### Output Sample 0 :
```
gamau gasuka gelay
```  

### Explanation 0 :  
We can illustrate these inputs into a graph as follows :  
  
<img width="398" alt="image" src="https://user-images.githubusercontent.com/105977864/209470455-dbdd4666-7b1c-478f-bddb-80867878f899.png">  
  
We can see that there is no circular route in the graph we've made, that's why the output should be "gamau gasuka gelay".  
  
### Input Sample 1 :  
```
7
8
0 6
0 5
5 1
1 6
2 6
2 3
3 4
4 1
```  

### Output Sample 1 :  
```
4
```  

### Explanation 1 :  
We can illustrate these inputs into a graph as follows :  
  
<img width="364" alt="image" src="https://user-images.githubusercontent.com/105977864/209470609-9069e42c-1cd0-420d-b5f6-f8c09f705b4a.png">  

We can see that there is a circular route that is formed by 4 connected places, which are 0, 6, 1, and 5.  

### Solution :  
Actually, this kind of problem's solution can be found in this following link :  
[Shortest Cycle Path - geeksforgeeks](https://www.geeksforgeeks.org/shortest-cycle-in-an-undirected-unweighted-graph/)  
  
But I am still going to explain it the way i understand and implement it for this problem.

The idea to solve this problem is to traverse each unvisited vertex recursively while marking it as visited and keeping track of the distance we've traversed and check if it eventually returns to one of the visited vertex before. if it is, then the cycle is present, but if it isn't, then there is no cycle in the graph.  
  
We are going to do the same thing to all unvisited vertex until we find the shortest cycle path in the graph. So by the end of the loop, we will get the length of the shortest circular route returned from the function we've made and print it as the output. but if there's no cycle present in the graph, our function will return -1 and print "gamau gasuka gelay" as requested. You can find the C++ implementation source code within the same folder as this file.  
  
Thanks, CMIIW :thumbsup:
