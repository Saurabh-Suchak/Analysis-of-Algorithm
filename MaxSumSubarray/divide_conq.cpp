#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int>& v, int L, int R){
        if(L > R) return INT_MIN;
        int mid = (L + R) / 2, lsum = 0, rsum = 0;
        
        for(int i = mid-1, curSum = 0; i >= L; i--)
            curSum += v[i],
            lsum=max(lsum, curSum);
        
        for(int i = mid+1, curSum = 0; i <= R; i++)
            curSum += v[i],
            rsum = max(rsum, curSum); 

		
        return max({ maxSum(v, L, mid-1), maxSum(v, mid+1, R), lsum + v[mid] + rsum });
    }


int main(){
vector<int>v={-2, -3, 4, -1, -2, 1, 5, -3};
    int ans=maxSum(v, 0, v.size()-1);
    cout<<ans;
    }
    