#include <bits/stdc++.h>
using namespace std;

int edit(string& word1, string& word2, int n1, int n2)
    {
        if(n1 == 0)
            return n2;
        if(n2 == 0)
            return n1;
       
        if(word1[n1-1] == word2[n2-1]) {
            return edit(word1, word2, n1-1, n2-1);
        }

        int insert = edit(word1, word2, n1, n2-1);
        int del = edit(word1, word2, n1-1, n2);
        int replace = edit(word1, word2, n1-1, n2-1);
            
            return 1 + min(insert, min(del, replace));
            
        return 1+min(edit(word1, word2, n1, n2-1),
                  min(edit(word1, word2, n1-1, n2),
                  edit(word1, word2, n1-1, n2-1)));
    }

int main(){

    string word1="tryingthiscode";
    string word2="tryingthecodes";

    int n1 = word1.size();
    int n2 = word2.size();
    cout<<"minimum edits required are "<<edit(word1, word2, n1, n2)<<endl;
        
    
}