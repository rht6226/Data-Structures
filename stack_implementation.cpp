/*  Perform push and pop operations on stack. Implement Stacks and avoid using inbuilt library.

Input Format

First line of input contains T - number of operations. Its followed by T lines, each line contains either "push x" or "pop".

Constraints

1 <= T <= 10000
-100 <= x <= 100

Output Format

For each "pop" operation, print the popped element, separated by newline. If the stack is empty, print "Empty".


INPUT:                        
8
push 5
pop
pop
push 10
push -15
pop
push -10
pop

OUTPUT:
5
Empty
-15
-10                */

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
    cin.ignore();
    string arr[t];
    int top=-1;
    for(int i=0;i<t;i++){
        getline(cin,arr[i]);
    }
    int j=0;
    string  temp[t];
 for(int i=0;i<t;i++){
    string  str=arr[i];
     if(str[0]=='p' &&str[1]=='u'){
         temp[j]=arr[i];
         top=j;
         j++;
     }
     else if(str=="pop"){
         if(j>0){
             j=j-1;
         }
         if(top==-1){
             cout<<"Empty";
         }
         else{
string k=temp[top];
             for(int c=5;c<k.length();c++){
                 cout<<k[c];
             }
             top--;
             
         }
         cout<<"\n";
     }
    
 }    return 0;
}
