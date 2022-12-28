# Tugas Prioritas (Priority Task)

[HackerRank : Tugas Prioritas](https://www.hackerrank.com/contests/alpro-its-sd-m4-e-2022/challenges/tugas-prioritas)

### Description :
We are asked to help Peter to calculate the order in which his task will be printed based on it's position and it's priority scale among others printing task on the queue (each has it's own position and priority scale).  

### Input Formats :
The first line is an integer ***T*** which represents the number of testcase. The next line is two integers ***N*** and ***M*** which each represents the number task in the queue and the position of Peter's task. And the next ***N*** lines contain each task's priority scale from 1 to 9. If there are any task with the same priority scale, print whatever comes first.  

### Constraints :
- 1 &le; ***T*** < 100
- 1 &le; ***N*** < 1000
- 1 &le; ***M*** < ***N*** - 1  

### Output Formats :
A line contains the order in which Peter's work will be completed.  

### Input Sample :
```
5
5 4
1 2 3 4 5
7 0
7 6 5 4 3 2 1
3 1
9 1 9
9 7
5 3 5 2 3 6 2 4 6
10 5
3 2 5 6 7 8 3 4 3 5
```  

### Output Sample :
```
1
1
3
5
1
```  

### Explanation :  
The sample input has 5 testcase, the first one is :  
```
5 4
1 2 3 4 5
```  
Peter's work is at position 4, which has priority scale of 5 (the biggest). So Peter's work will be printed first.  
The second testcase is :  
```
7 0
7 6 5 4 3 2 1
```  
Again, Peter's work is at position 0 and has the biggest priority scale (7) so it will also be printed first.  
The third testcase is :  
```
3 1
9 1 9
```  
Peter's work is at position 1, which has priority scale of 1 (the smallest). So Peter's work will be printed last.  
The fourth testacase is :  
```
9 7
5 3 5 2 3 6 2 4 6
```  
Peter's work is at position 7, which has priority scale of 4. So Peter's work will be printed after the task with priority scale of 6, 6, 5, and 5, which is number 5.  
The fifth testacase is :  
```
10 5
3 2 5 6 7 8 3 4 3 5
```  
Peter's work is at position 5, which has priority scale of 8 (the biggest). So Peter's work will be printed first  


### Solution :
The idea to solve this problem is to iterate through each task in the queue to find the biggest priority scale and mark it as printed while keeping track of the current print order. If it's already printed, then we move on to the next biggest priority scale task to print until we reach the Peter's work's position, and then we can stop the loop and print the current order variable.  

Actually, it's not the best algorithm to solve this problem. There are lots of better way to solve it, but at the time I worked on this problem, it's the best way I can think of. You can find the C++ implementation source code within the same folder as this file. 

Thanks, CMIIW :thumbsup:

