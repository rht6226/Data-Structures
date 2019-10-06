#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
     unordered_map<char,TrieNode*> m;
     bool endofword;

     TrieNode(){
       endofword=false;
     }
};
TrieNode *root= new TrieNode();
void insert(string s)
{
    TrieNode *curr=root;
    
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        TrieNode *node=new TrieNode();
        
        if(((curr->m).find(c))==((curr->m).end()))
        {
          (curr->m)[c]=node;
          curr=node;
        }
        else
         {
             delete node;
            curr=(curr->m)[c];
         }
        
    }
    curr->endofword = true;
}
bool search(string s)
{
   TrieNode *curr=root;
   
   for(int i=0;i<s.length();i++)
   {
       char c=s[i];
       if((curr->m).find(c)==(curr->m).end())
       {
           return false;
       }
       else
        curr = (curr->m)[c];
   }
   
   return curr->endofword;
  
}

bool deleteString(TrieNode *current,string word,int index)
{
    
    if(index==(word.length()))
    {
        //when end of word is reached only delete if currrent.endOfWord is true.
        if(!(current->endofword))
         return false;
         
        current->endofword = false; 
         //if current has no other mapping then return true
         return (current->m).size()==0;
    }
    
    char c = word[index];
    auto it = (current->m).find(c);
    
    if(it==(current->m).end())
     return false;
     
    bool shoulddeletecurrentnode = deleteString(it->second,word,index+1);
    
    if(shoulddeletecurrentnode)
    {
        (current->m).erase(c);
        return (current->m).size()==0;
    }
    
    return false;
}
int main()
 {
	//code
	
       int i,n;
       string t;
       cin>>n;
       for(i=0;i<n;i++)
       {
          cin>>t;
          insert(t);
       }
       string toS;
       cin>>toS;

       cout<<search(toS)<<endl;
       deleteString(root,"world",0);
       cout<<search(toS)<<endl;
    
	
	return 0;
}
