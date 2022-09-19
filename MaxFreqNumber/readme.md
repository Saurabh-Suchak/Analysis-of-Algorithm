# Find Element with max freq 

### Background:
Activity selection problem
Activity Selection Problem is based on Greedy approach. A greedy algorithm is a simple, intuitive algorithm that is used in optimization problems. The algorithm makes the optimal choice at each step as it attempts to find the overall optimal way to solve the entire problem.
<br />
In activity selection we try to use the same approach so that maximum activities can take place.


### Problem Statement:
Accept a 1-D array using random number generator. The array may be be in the range of [0,1,2] [Only three numbers are permitted]
Scan the array and print "X" if number "0" is more than number of "1" and "2".
Print "Y" if number of "1" are more than "0" and "2"
Print "Z" if number of "2" are more than "0" and "1"
Expected complexity O(log n) 


### Approach / Intuition:

Since the expected time complexity is given as logn, we can use binary search to get the answer. But first we need to consider finding the element with max freq as a sub problem and then print the required output.
To get the answer, we can get the ending indices of the elements 0,1,2 in the sorted array and therefore get their frequency.
We make a little modification in binary search function such that even if we find the required element as mid, we always proceed to the right so that the ending index can be obtained.
### Code:

```cpp
#include <bits/stdc++.h>
using namespace std;


int binarySearch(int array[], int x, int low, int high) {
  
int ans=-1;	
  while (low <= high) {
    
    int mid = low + (high - low) / 2;

    if (array[mid] == x || array[mid]<x)
      {
        ans=mid;
        low=mid+1;
        }
    else 
      {
        high = mid - 1;
    }
    
  }

  return ans;
}



int main(){

 int arr[10];

 for(int i=0;i<10;i++){
    arr[i]=rand()%3;
 }
 cout<<"the array obtained is - "<<endl;
 for(int i=0;i<10;i++){
    cout<<arr[i]<<" ";
 }
cout<<endl;
sort(arr,arr+10);

 cout<<"the array after sorting is - "<<endl;
 for(int i=0;i<10;i++){
    cout<<arr[i]<<" ";
 }

int ending0 = binarySearch(arr,0,0,9);
int ending1 = binarySearch(arr,1,ending0+1,9);

cout<<endl;

cout<<"the index where 0 ends is "<<ending0<<endl;
cout<<"the index where 1 ends is "<<ending1<<endl;

int num0=(ending0!=-1)?ending0+1:0;
int num1=(ending1!=-1)?ending1-ending0:0;
int num2= 10-num1-num0;

cout<<"no of zeroes in array are "<<num0<<endl;
cout<<"no of ones in array are "<<num1<<endl;
cout<<"no of two in array are "<<num2<<endl;

cout<<endl<<"printing the output according to maximum freq element"<<endl;
if(num0>num1 && num0>num2)cout<<"X";
else if(num1>num0 && num1>num2)cout<<"Y";
else cout<<"Z";

}


```

### Output1 using n=15 :
```
the array obtained is - 
2 2 1 1 2 1 0 0 1 2 2 2 1 0 1
the array after sorting is -
0 0 0 1 1 1 1 1 1 2 2 2 2 2 2
the index where 0 ends is 2
the index where 1 ends is 8
no of zeroes in array are 3
no of ones in array are 6
no of two in array are 6

printing the output according to maximum freq element
Z
```

### Output2 using n=10 :
```
the array obtained is - 
2 2 1 1 2 1 0 0 1 2
the array after sorting is -
0 0 1 1 1 1 2 2 2 2
the index where 0 ends is 1
the index where 1 ends is 5
no of zeroes in array are 2
no of ones in array are 4
no of two in array are 4

printing the output according to maximum freq element
Z
```

### Time and Space complexity :
```
TC- O(NlogN)         // whole code
    O(logN)          // binary search function to find ending index
SC- O(1)            // No auxiliary space used apart from variables.
```


### Explanation : 

Step 01 : We iterate through the start and end array and store in vector the start and end time of an activity as a pair as {finsih,start}.<br />
Step 02 : This way of storing makes it easy to sort the activities accoriding to the finsih times, we just have to use the inbuilt sort now.<br />
Step 03 : then we select the activities **greedily**, choosing the activities that finish early so that we can maximise available time for other activities.
