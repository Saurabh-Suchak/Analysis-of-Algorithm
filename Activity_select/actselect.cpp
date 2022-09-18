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