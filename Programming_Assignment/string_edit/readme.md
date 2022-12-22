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


string s1="a";
string s2="fy";
int n=s1.size();
int m=s2.size();
vector<vector<int>> dp(n, vector<int>(m, -1));

int cnt=0;

int edit_distance(int i, int j) {
    if(i>n)return 0;
    if(j>m)return 0;
	if (i == s1.size()) return s2.size() - j;
	if (j == s2.size()) return s1.size() - i;

	if (dp[i][j] != -1) return dp[i][j];
	if (s1[i] != s2[j])
		return dp[i][j] = 1 + min(
				edit_distance(i + 1,j + 1), 
				min(
					edit_distance(i + 1, j), 
					edit_distance(i, j + 1) 
				) 
			);
	else
		return dp[i][j]=edit_distance(i + 1, j + 1);
}

void steps(int i, int j) {
	if (i == s1.size()) {
		string in {s2.substr(j)};
		if (in.size()==0) return;
		cout << "Insert ";
		for (int i = 0; i < in.size(); ++i) {cnt++;
			cout << (i > 0 ? ", " : "") << "'" << in[i] << "'";
		}
		return;
	}
	if (j == s2.size()) {
		string del{ s1.substr(i) };
		if (del.size()==0) return;
		cout << "Delete ";
		for (int i = 0; i < del.size(); ++i) {cnt++;
			cout << (i > 0 ? ", " : "") << "'" << del[i] << "'";
		}
		return;
	}
	if (s1[i] != s2[j]) {
		int opt = edit_distance(i, j);
		int change = 1 + edit_distance(i + 1, j + 1);
		int insert = 1 + edit_distance(i, j + 1);
		int rem = 1 + edit_distance(i + 1, j);
		if (change == opt) {cnt++;
			cout << "Change '" << s1[i] << "' to '" << s2[j] << endl;
			steps(i + 1, j + 1);
		}
		else if (insert == opt) {cnt++;
			cout << "Insert '" << s2[j] << endl;
			steps(i, j + 1);
		}
		else {cnt++;
			cout << "Delete '" << s1[i] << endl;
			steps(i + 1, j);
		}
	}
	else
		steps(i + 1, j + 1);

}



int main() {
     steps(0,0);
     cout<<endl<<"minimum edits required are "<<dp[0][0]<<endl;
    //  cout<<endl<<"minimum edits required are "<<cnt<<endl;
    
    
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
