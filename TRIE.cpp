#include<bits/stdc++.h>
using namespace std;
struct Node{
Node *links[26];
bool track=false;
bool isExist(char ch)
{

   return (links[ch-'a']!=NULL);
}
void setLast()
{
    track=true;
}
bool checkTrack()
{
    return track;
}
void createLink(char ch,Node* node)
{

    links[ch-'a']=node;
}
 Node* next(char ch)
 {
    return links[ch-'a'];
 }
};
class Trie{

Node* root;
public:
Trie()
{
    root=new Node();

}
void insert(string s)
{
    Node* node=root;
    //insert which will take O(N) time complexity.
    for(int i=0;i<s.size();i++)
    {
        //i will check ,is this char exist.
        //if not,then i will create a empty trie.
        //and in particular index, i will link.
        if(node->isExist(s[i])==false)
        {
            node->createLink(s[i],new Node());
        }
        //then i will move to the next trie
        //links[] pointing to the next trie.
        node=node->next(s[i]);

    }
    node->setLast();
}
//search which will take O(N)
bool search(string s)
{
    Node* node=root;
    for(int i=0;i<s.size();i++)
    {
        if(node->isExist(s[i])==false)
        {
            return false;
        }
       node= node->next(s[i]);
    }
    if(node->checkTrack())
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool startsWith(string s)
{
    Node* node=root;
    for(int i=0;i<s.size();i++)
    {
        if(node->isExist(s[i])==false)
        {
            return false;
        }
        node=node->next(s[i]);
    }
    return true;

}


};
int main()
{
    Trie* trie=new Trie();
    trie->insert("apple");
    cout<<trie->startsWith("app");
}

