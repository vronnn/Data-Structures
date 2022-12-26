# Mencurigakan (Suspicious)

[HackerRank : Mencurigakan](https://www.hackerrank.com/contests/alpro-its-sd-m4-e-2022/challenges/mencurigakan)

## Description :
We are asked to help Yuta to count and find anyone that uses his website that acts suspiciously, such as a user who hasn't indicated to be logged in but already recorded doing logged out or vice versa.

### Input Format :
The first line is ***T*** which represents the number of activities watched by Yuta, followed by ***T*** lines which each contains ***N*** that represents the user and their activity. If the value of ***N*** is positive, then the user ***N*** is doing a log in activity and if the value of ***N*** is negative, then the user ***-N*** is doing a log out activity.  

### Constraint :
- 1 &le; ***T*** &le; 1000
- -100 &le; ***N*** &le; 100, ***N*** &notin; 0  

### Output Format :
A number ***R*** which represents the number of suspicious activities, followed by ***R*** rows containing users who have been recorded as having suspicious activities.  

### Sample Input :
```
6
1
2
2
-2
-1
-3
```  

### Sample Output :
```
2
2
3
```  

### Explanation :
There are 6 activities and 3 users, namely 1, 2, and 3. The first activity is user 1 logging in, followed by user 2 who is also logging in. But there is something suspicious in the third activity, which is user 2 is logging in again without logging out first, it means that we should add user 2 to our suspicous list. Then the next activity is user 2 logging out. followed by user 1 logging out too. But in the last activity, there is user 3 that logging out without logging in first. This is definitely going in to our suspicious list. So in the end, we have 2 suspicious activities, which were done by user 2 and user 3.  

## Solution :
This problem is actually pretty simple, we just need to check every activities input that's happening. If there is a negative ***N*** input without posistive ***N*** recorded in our data structure, then we have put it in our suspicious list, but if there is a positive ***N*** recorded, then we erase them all from our data structure because they are not classified as suspicous activities.  
  
Another condition we need to check is if there is a positive ***N*** input but we have already recorded it before without any log out activity recorded, then we have to put it in our both data structure and our suspicious list, because any log in activities must be recorded in our data structure but since it's suspicious, then we have to put it in our suspicious list too. Other than that we just casually put it in to our data structure for recording purpose.  
  
There are actually a lot ways to implement this solution, but at the time I worked on this problem, I use vector data structure to save and check every activities input that's happening. The reason I choose vector is because I can easily erase an element in it using iterator without worrying to much about the index. You can find the C++ implementation source code within the same folder as this file. 

Thanks, CMIIW :thumbsup:

