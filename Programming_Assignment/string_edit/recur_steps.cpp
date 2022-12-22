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
