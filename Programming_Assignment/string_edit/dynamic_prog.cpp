#include <bits/stdc++.h>
using namespace std;

int main(){
    string word1= "doingthisdp";
    string word2= "dwingthedp";


        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        
        for(int i=0; i<n1+1; i++){
            dp[i][0] = i;
        }
            
        
        for(int j=0; j<n2+1; j++){
            dp[0][j] = j;
        }
            
        for(int i=1; i<n1+1; i++){
            for(int j=1; j<n2+1; j++){
                if(word1[i-1] == word2[j-1])
                    {dp[i][j] = dp[i-1][j-1];}
                else{
                    int insert = dp[i][j-1];
                    int del = dp[i-1][j];
                    int replace = dp[i-1][j-1];
                    
                    dp[i][j] = 1 + min(insert, min(del, replace));
                }
            }
        }
        cout<<"the minimum edits required are "<<dp[n1][n2];
        
}
        