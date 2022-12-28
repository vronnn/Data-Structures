# RahelChan Mau Hadiah (RahelChan wants a present)

[HackerRank : RahelChan Mau Hadiah](https://www.hackerrank.com/contests/alpro-its-sd-m3-e-2022/challenges/rahelchan-mau-hadiah)

### Description :
Rahel just had a birthday, but she didn't get any present from her friends. Until the next day, there is a mysterious containing a number with an additional message, "Enter these numbers into the AVL Tree. If there are the same numbers, just keep inserting it. If you have finished, take one or more numbers that you like so that you can find the order. Then, send the result back to this email so I can send you the best gift :D".  

Reading the email made Rahel excited again and she rushed to make her AVL Tree. Help Rahel to make the program to find the sequence of numbers she likes from the AVL Tree!

### Input Formats :
***X Y***  
- If ***X*** = 1, then put ***Y*** into the tree.
- If ***X*** = 2, then take ***Y*** from the tree.

### Constraints :
1 &le; ***Y*** &le; 1000000

### Output Formats :
- If ***X*** = 2, show the number's (***Y***) order.
- If ***Y*** doesn't exist in the tree, print "M44f h3l c4r1 4ngk4 l4in y4"

### Input Sample 0 :
```
1 2
1 2
1 2
1 2
2 2
```

### Output Sample 0 :
```
2
```

### Explanation 0 :
Maybe the previous problem explanations aren't quite through, so what i've discovered from some of these testcases

### Input Sample 1 :
```
1 5
1 6
1 1
1 11
1 5
1 7
1 3
1 2
1 15
1 12
1 48
2 12
2 5
2 2
2 1422
```

### Output Sample 1 :
```
9
4
2
M44f h3l c4r1 4ngk4 l4in y4
```

### Explanation 1 :


### Solution :  
The idea to solve this problem is to traverse each node in inorder way while saving them in another data structure such as queue. And then, we keep the order of each requested node by moving it into another array while counting the index. So that all we have to do now is just deciding which order should be printed for the correct output.

Maybe the previous problem explanations aren't quite through, so what i've discovered from some of these testcases are that if the tree contains an even amount of the same requested numbers, then the output should be the ***n/2<sup>th</sup>*** order in the tree or the ***n/2-1<sup>th</sup>*** order in the array. We can take an example of the first testcase, which there are four 2s inserted into the tree as follows,  
  
| n | 2 | 2 | 2 | 2 |
|:-----:|:---:|:---:|:---:|:---:|
| Array Index | 0 | 1 | 2 | 3 |
| Tree Index     | 1 | 2 | 3 | 4 |  
  
Since four is even, then the correct array index of the requested node is ***n/2-1 = 4/2-1 = 1*** which is 2 in tree index. So the output is 2.  

It works the same way with the second testcase. We can draw the table for each node easily since it has been ordered in inorder way as follows,  

| index | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| n | 1 | 2 | 3 | 5 | 5 | 6 | 7 | 11 | 12 | 15 | 48 |  

The first query is 12, and since there's just one 12, we can print the index directly, which is 9.  
The second query is 5 and there are two 5s in the table. Since two is even, so we're going to print the ***n/2<sup>th</sup>*** order of 5 in there, which is  the ***2/2 = 1<sup>th</sup>*** order, 4.  
The next query is 2 which there is only one two, so we can directly print the index, 2.  
The last query is 1422 and as we can see, there is no 1422 in the tree, so the output is "M44f h3l c4r1 4ngk4 l4in y4".  

You can find the C implementation source code file within the same folder as this file, but if you're looking for the general implementation of an AVL tree, you can find it in the Self Balancing BST folder in the first page of this repository.  

Thanks, CMIIW :thumbsup:
