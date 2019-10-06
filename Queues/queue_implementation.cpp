/*
Perform Enqueue and Dequeue operations on a queue. Implement Queue and avoid using inbuilt library.

Input Format

First line of input contains T - number of operations. Its followed by T lines, each line contains either "Enqueue x" or "Dequeue".

Constraints

1 <= T <= 10000
-100 <= x <= 100

Output Format

For each "Dequeue" operation, print the dequeued element, separated by newline. If the queue is empty, print "Empty".


Sample Input 0

8
Enqueue 5
Dequeue
Dequeue
Enqueue 10
Enqueue -15
Dequeue
Enqueue -10
Dequeue
Sample Output 0

5
Empty
10
-15
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<sstream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    cin.ignore();
     int u=0;
    int f=0,r=0;
            int i=0;
            string temp[t];
    while(t--){
        string str;
        getline(cin,str);
if(str[0]=='E'){
    int j=0;
    istringstream iss(str);
      for(string str;iss>>str;){
          if(j==1){
              temp[u]=str;
          }
              j++;

        }
          u++;
          r++;

}

       else{
            if(f==r){
                cout<<"Empty"<<"\n";
            }
            else{
             cout<<temp[f]<<"\n";
                f++; 
            }
        }
  
        
    }
    return 0;
}
