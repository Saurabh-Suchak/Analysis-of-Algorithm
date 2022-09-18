#include <bits/stdc++.h>
using namespace std;
 
int maxSum(int s1[], int s2[], int s3[], int n1,
           int n2, int n3)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;
 
    // check the sum of all 3 stacks first
    for (int i = 0; i < n1; i++)
        sum1 += s1[i];
 
    
    for (int i = 0; i < n2; i++)
        sum2 += s2[i];
 
    
    for (int i = 0; i < n3; i++)
        sum3 += s3[i];
 
   // considering the first element as top of stack
    int top1 = 0, top2 = 0, top3 = 0;
    while (1) {
        
        if (top1 == n1 || top2 == n2 || top3 == n3)
            return 0;
 
        
        if (sum1 == sum2 && sum2 == sum3)
            return sum1;
 
        // remove top element of stack with max sum

        if (sum1 >= sum2 && sum1 >= sum3)
            sum1 -= s1[top1++];
        else if (sum2 >= sum1 && sum2 >= sum3)
            sum2 -= s2[top2++];
        else if (sum3 >= sum2 && sum3 >= sum1)
            sum3 -= s3[top3++];
    }
}
 
int main()
{
    int s1[] = { 3,2,1,1,1 };
    int s2[] = { 4,3,2 };
    int s3[] = { 1,1,4,1 };
 
    int n1 = sizeof(s1) / sizeof(s1[0]);
    int n2 = sizeof(s2) / sizeof(s2[0]);
    int n3 = sizeof(s3) / sizeof(s3[0]);
 
    cout << maxSum(s1, s2, s3, n1, n2, n3)   // output comes out to be 5
         << endl;
    return 0;
}