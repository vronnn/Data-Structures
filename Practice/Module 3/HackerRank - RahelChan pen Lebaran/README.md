# RahelChan pen Lebaran (RahelChan wants Eid)

[HackerRank : RahelChan pen Lebaran](https://www.hackerrank.com/contests/alpro-its-sd-m3-e-2022/challenges/rahelchan-pen-lebaran)

## Description :
Eid is coming soon, and Rahel plans to visit the Pawel Family's house. So while waiting, Rahel wanted to make a program to calculate the age difference of the Pawel Family members. This family tree is similar to the AVL Tree. The program will take an age as an input and it will find the parent and it's sibling, then calculates the difference. But since Rahel is having a hard time, we will help her to make the program.  

## Input Formats :
The first line are ***N*** and ***T*** which each represents the number of the Pawel Family members and the number of testcases.  
The next line are ***N<sub>i</sub>*** for each member's age.  
The next ***T*** lines are the age input  
> NOTE : There is a possibility that the input for the Tree is duplicated, only one value will be inserted into the Tree  
  
## Constraints :
- ***N*** < 100
- 1 < ***T*** < 30  

## Output Formats :
Output the difference in age between the requested sibling parent nodes.  
If the input is the root's age, then print “Aku adalah Kepala Keluarga Pawel”.  
If the parent doesn't have a sibling, then assume that the sibling's age is 0.  
If the input is not in the tree, then print "Aku Bukan Anggota Keluarga Pawel".  

## Input Sample :
```
16 4
6 15 26 27 28 50 17 29 7 48 10 64 98 14 32 57
27
50
32
17
```  

## Output Sample :
```
Aku adalah Kepala Keluarga Pawel
27
20
19
```  

## Explanation :
Here is the picture of the input tree :
  
<img width="816" alt="image" src="https://user-images.githubusercontent.com/105977864/209709197-bdd16679-c840-48bd-97dd-73e676b8bb09.png">  
  
- 27 is the root of the tree, so the output is "Aku adalah Kepala Keluarga Pawel"
- 50 has a parent of 27, but 27 doesn't have a sibling, so the output is 27 - 0 = 27
- 32 has a parent of 48, and 48's sibling is 28, so the output is 48 - 28 = 20
- 17 has the parent of 26, and 26's sibling is 7, so the output is 26 - 7 = 19  

## Solution : 
The idea to this problem's solution is kind of the same with the previous problem, which is the "Mencari Ayah" problem (You can find it in the previous folder, module 3). We just got to keep track of the input's parent using another pointer. Then, we find the parent's parent (or grandpa) using the same methods. After that, we just have to find the other child of this grandpa and subtract it with it's sibling's age we found before. then print it as an output. if it doesn't have another child, then just outputs it right away. and if the input is the root, then print "Aku adalah Kepala Keluarga Pawel".  

You can find the C implementation source code file within the same folder as this file, but if you're looking for the general implementation of an AVL tree, you can find it in the Self Balancing BST folder in the first page of this repository.  

Thanks, CMIIW :thumbsup:
