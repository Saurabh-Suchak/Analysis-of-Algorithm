#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={-2, -3, 4, -1, -2, 1, 5, -3};
    int n = v.size(), ans = INT_MIN;
        for(int i = 0; i < n; i++) 
            for(int j = i, curSum = 0; j < n ; j++) 
                curSum += v[j],
                ans = max(ans, curSum);        
        cout<<ans;
    return 0;
}