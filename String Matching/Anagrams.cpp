/* 
Given 2 strings, check if they are anagrams. An anagram is a rearrangement of the letters of one word to form another word. In other words, some permutation of string A must be same as string B.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line containing 2 space separated strings.

Constraints

10 points
1 <= T <= 100
1 <= len(S) <= 103
'a' <= S[i] <= 'z'

40 points
1 <= T <= 100
1 <= len(S) <= 105
'a' <= S[i] <= 'z'

Output Format

For each test case, print True/False, separated by newline.

Sample Input 0

4
a a
b h
stop post
hi hey


Sample Output 0
True
False
True
False
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin>>t;
    while(t--){
        string str1;
        string str2;
        cin>>str1;
        cin>>str2;
        int cnt[26]={0};
        for(int i=0;i<str1.length();i++){
            cnt[str1[i]-'a']++;
        }        
           for(int i=0;i<str2.length();i++){
            cnt[str2[i]-'a']--;
        }        
        int count=0;
    for(int i=0;i<26;i++){
        if(cnt[i]==0){
count++;
            }
    }
        if(count==26){
cout<<"True";
        }
        else{
cout<<"False";
        }
        cout<<"\n";
        
}
}
