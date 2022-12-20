# String Editing
<br/>

### Problem Statement:
Implement the string editing algorithm using dynamic programming approach and demonstrate 3 test cases.



### Applications of String Editing :
String edit distances have been used for decades and has various applications with some them being -
- Spelling correction
- Web search suggestions. For example, the Apache Lucene
- DNA analysis like DNA-protein matching and sequence assembly
<br>



### Code:
```
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
        

```

### Testcase 1 :
```
An application of string editing for spell correction:


word1= "doingthisdp"
word2= "dwingthedp"

Output - the minimum edits required are 3

Here 3 edits are required to make the spelling correct and match the two words
- Edit 1 : replace 'w' with 'o' in the second string
- Edit 2 : replace 'e' with 'i'
- Edit 3 : insert 's' in the second string to match oth strings

Therefore minimum 3 edits would be required to match both the words and the associated cost would be incurred, according to the 
individual cost of operations (i.e insertion, deletion and updation/replace)
```

### Testcase 2 :
```
word1 = "abcfg"
word2 ="adceg"

Output - the minimum edits required are 2
```

![WhatsApp Image 2022-12-20 at 6 18 03 PM](https://user-images.githubusercontent.com/91744743/208671162-c9ecf2d0-d4ab-4322-a8cd-960825e6e9eb.jpeg)

### Testcase 3 :
```
word1 = "chocolatey"
word2 = "c"

Output - the minimum edits required are 9
```

### Time and Space complexity :
```
Time Complexity of Recursion - O(min(3^n1, 3^n2)) 
Space Complexity - O(n)    // stack space for recursion

Time Complexity in dynamic prog. -  O(n1 * n2)
Space Complexity - O(n1 * n2)

n1,n2 represents the length of word1 and word2

```
