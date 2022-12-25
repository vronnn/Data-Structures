# Aku dan Dia Bertetangga (Me and Him are Neighbors)

[HackerRank : Aku dan Dia Bertetangga](https://www.hackerrank.com/contests/alpro-its-sd-m4-e-2022/challenges/aku-dan-dia-bertetangga)

## Description :
Given a graph that represents the cities as shown below :
  
<img width="554" alt="image" src="https://user-images.githubusercontent.com/105977864/209458388-3dc73f44-baeb-4a22-8c08-95898b30ba07.png">
  
We are asked to print the neighbors of a city along with their distance with the given input format,
  
### Input Formats :
1. The first line is an integer **n** which represents the number of cities in the graph.
2. The second line are **n** space-seperated inputs, which is the name of the cities,  
ex : **n = 2**, then the input can be **Jakarta Bandung**.
3. The next **n** lines are the inputs for the neighbor of each city (sequentially based on the seconnd line inputs). Each row starts with an integer input **a** which represents the number of neighbors then followed by the neighbor's name and it's distance **x**.
4. The next line is the **name of a city** that they want us to print all of their **neighbors** along with their **distance**.
  
These are the input samples with the same formats :

```
5
Jakarta Denpasar Sumba Surabaya Palu
3 Denpasar 100 Sumba 200 Surabaya 600
2 Surabaya 100 Jakarta 200
1 Palu 50
4 Jakarta 200 Denpasar 80 Sumba 300 Palu 1000
0
Surabaya
```

### Constraints :
- 1 &le; **n** &le; 1000
- **a** &le; **n** - 1
- 1 &le; **x** &le; 5000

### Output Format :
print the neighbors and distance of the requested city name with the following format :  
  
```
(neighbor1, distance1) , (neighbor2, distance2), ..., (neighborn, distancen)
```

>NOTE : if the requested city doesn't have a neoghbor, output "TIDAK TERSEDIA"
  
### Sample Input :
```
5
Jakarta Denpasar Sumba Surabaya Palu
3 Denpasar 100 Sumba 200 Surabaya 600
2 Surabaya 100 Jakarta 200
1 Palu 50
4 Jakarta 200 Denpasar 80 Sumba 300 Palu 1000
0
Surabaya
```  

### Sample Output :
```
(Jakarta, 200) (Denpasar, 80) (Sumba, 300) (Palu, 1000) 
```  

### Explanation :
We are asked to output every neighbors of Surabaya along with their distance. We can see that Surabaya is in the 4<sup>th</sup> place on the second line input, therefore, we can immediately look at the 4 line right after it. this line shows that Surabaya has 4 neighbors, which are **Jakarta for 200 km, Denpasar for 80 km, Sumba for 300 km, and Palu for 1000 km**.


## Solution :
Since it's just a print command, then what we actually need to concern is how to store each inputs variable so that we can easily access them all when we need it. first, we need to list every variable that needs to be saved for this problem, which are requested city names, order index, and also pair of their neighbors with it's distance. but since we only need the city's index to access it's neighbor and the distance we've saved in a data structure such as vector, then we're going to store the city names in another accessable data structure. This is why i have a vector with the type of string to store the city names and an array of pair vector to store every neighbor and the distance according to the city's order index. And that's also why i made two function to make it easier for me to access all of those datas, which is ***encrypt*** to get the order index from a city name and ***decrypt*** to get the city name from an order index. This way, i can ensure that i'm accessing the correct data from the data structure i use for each command.  
  
thanks, CMIIW :thumbsup: