#include<bits/stdc++.h>
using namespace std;
struct Node{
//in our node, we will have now two new things
//one is for tracking how many strings we have
//for that we will declare countEnd
//and for prefix count like how many strings start with some prefix that will be given
//for that we need another variable called countPrefix


int countEnd=0;
int countPrefix=0;
Node* links[26];


//i need to check is particular character link is exist or not
bool isExist(char ch)
{
    return (links[ch-'a']!=NULL);
}

//i will create link if not exist
void createLink(char ch,Node* node)
{
    links[ch-'a']=node;
}
//we should go next trie's node
Node* next(char ch)
{
    return links[ch-'a'];
}
//i need to increase the count prefix value
void increaseCountPrefix()
{
    countPrefix++;
}
//after complete the string , we need to count how many strings we have similar to this
void increaseCountEnd()
{
    countEnd++;
}
int getCountPrefix()
{
    return countPrefix;
}
int getCountEnd()
{
    return countEnd;
}
void decreamentCountPrefix()
{
    countPrefix--;
}
void decreamentCountEnd()
{
    countEnd--;
}
};


class Trie{

Node* root;
public:
//constructor
Trie()
{
   root=new Node();
}
//we will have insert function
void insert(string s)
{
    Node* node=root;
    for(int i=0;i<s.size();i++)
    {
        if(node->isExist(s[i])==false)
        {
            node->createLink(s[i],new Node());
        }
        node=node->next(s[i]);
        node->increaseCountPrefix();
    }
    node->increaseCountEnd();
}
//we will have countWordStartingWith function
int countWordsStartingWith(string s)
{
   Node* node=root;
   for(int i=0;i<s.size();i++)
   {
       if(!node->isExist(s[i]))
       {
           return 0;
       }
      node=node->next(s[i]);
   }
   return node->getCountPrefix();
}

//we will have countWordsEqualTo function
int countWordsEqualTo(string s)
{
   Node* node=root;
   for(int i=0;i<s.size();i++)
   {
       if(!node->isExist(s[i]))
       {
           return 0;
       }
       node=node->next(s[i]);
   }
   return node->getCountEnd();
}
//we will have erase function
void erase(string s)
{
 Node* node=root;
 for(int i=0;i<s.size();i++)
 {
     if(!node->isExist(s[i]))
     {
         return;
     }
     node= node->next(s[i]);
     node->decreamentCountPrefix();

 }
 node->decreamentCountEnd();

}


};


int main()
{
    Trie* trie=new Trie();
    trie->insert("apple");
    trie->insert("apple");
    trie->insert("apps");
    trie->insert("apps");

   cout<< trie->countWordsStartingWith("app")<<endl;
   cout<< trie->countWordsEqualTo("apple")<<endl;
   trie->erase("apple");
   cout<< trie->countWordsEqualTo("apple")<<endl;
   cout<< trie->countWordsStartingWith("app")<<endl;




}

