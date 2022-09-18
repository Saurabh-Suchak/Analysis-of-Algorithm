# Activity-Selection-Problem

### Background:
Activity selection problem
This project provides a solution for Activity Selection Problem using Greedy algorithmic approach. Greedy is a algorithmic approach which builds up solution piece by piece, these are chosen such that it is the most benificial approach, this provides a solution to optimization problems. In this aproach we make choice at every step that provides best solution at present and hence we get the optimal solution for complete problem.
Activity selection problem is a approach wherein we select the activity from the set of given activities such that we maaximum number of activities should be completed/selected using the given solution


### Problem Statement:
Given the start and finish times of activities as given below. Output the maximum number of activiites that can take place in the given time provided that no two activities occur simultaneously.

| Index  | Start | End    |
| -----  | ----- | ------ |
| 0      | 1     | 1      |
| 1      | 2     | 3      |
| 2      | 3     | 5      |
| 3      | 4     | 4      |
| 4      | 7     | 7      |
| 5      | 8     | 9      |
| 6      | 9     | 11     |
| 7      | 9     | 13     |
| 8      | 11    | 12     |
| 9      | 12    | 14     |


### Code:

```cpp
#include <bits/stdc++.h>
using namespace std;


int main()
{
    // these are the input start and end times of the activities
    
    int s[]={1,2,3,4,7,8,9,9,11,12};
    int f[]={3,5,4,7,10,9,11,13,12,14};
    int n = sizeof(s)/sizeof(s[0]);
    
    // to implement activity selection , we need sort the activities according to the finish times
    // so we store the start and finsih of each in pair as {finish(i),start(i)}
    
    vector<pair<int,int>>act;
    for(int i=0;i<n;i++){
        act.push_back({f[i],s[i]});
    }
    
    sort(act.begin(),act.end());// sorted according to the finish time
    
    // the first activity is always selected
    cout<<"the following activites with start and end as given are selected - "<<endl;
    
    int i = 0;
    
    cout << "(" << act[i].second << ", " << act[i].first << "), ";

    
    for (int j = 1; j < n; j++)
    {
      // if start of activity j >= finish time of previous activity
      // since pair is of form {finish,start}, start is represented by .second and finsih by .first
      
      if (act[j].second >= act[i].first)
      {
          cout << "(" << act[j].second << ", "
              << act[j].first << "), ";
          i = j;
      }
    }
    
    
    return 0;
}

```


### Output:
```
the following activites with start and end as given are selected - 
(1, 3), (3, 4), (4, 7), (8, 9), (9, 11), (11, 12), (12, 14),
```

### Explanation : 

Step 01 : We iterate through the start and end array and store in vector the start and end time of an activity as a pair as {finsih,start}.<br />
Step 02 : This way of storing makes it easy to sort the activities accoriding to the finsih times, we just have to use the inbuilt sort now.<br />
Step 03 : then we select the activities **greedily**, choosing the activities that finish early so that we can maximise available time for other activities.
