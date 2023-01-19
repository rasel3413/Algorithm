
#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" = "<<x<<endl;
struct trie
{
    int isend;
    trie *child[26];
    trie()
    {
        isend=0;
        for(int i=0; i<26; i++)
            child[i]=NULL;
    }
};
void insert(trie *root,string s)
{
    trie * temp=root;
    for(int i=0; i<s.length(); i++)
    {
        int idx=s[i]-'a';
        if(temp->child[idx]==NULL)
            temp->child[idx]=new trie();
        temp=temp->child[idx];
    }
    temp->isend++;;
}
int query(trie *root,string s)
{
    trie* temp=root;
    for(int i=0; i<s.length(); i++)
    {
        int idx=s[i]-'a';
        if(temp->child[idx]==NULL)
            return 0;
        temp=temp->child[idx];
    }
    return temp->isend;

}
void words(trie *root,string s)
{

    if(root==NULL)
        return;
        if(root->isend!=0)
        {
            for(int i=0;i<root->isend;i++)cout<<s<<endl;

        }
    for(int i=0; i<26; i++)
    {
        if(root->child[i]==NULL)
            continue;
        else
        {


//            if(root->child[i]->isend!=0)
//            {
//                for(int j=0; j<root->child[i]->isend; j++)
//                    cout<<s+(char)(i+'a')<<endl;
//            }


            words(root->child[i],s+(char)(i+'a'));
        }

    }

}
int main()
{
    trie *root=new trie();
    string str="In computer science about there there is ";
    //, a trie, also called digital tree or prefix tree, is a type of search tree, a tree data structure used for locating specific keys from within a set. These keys are most often strings, with links between nodes defined not by the entire key, but by individual characters. In order to access a key (to recover its value, change it, or remove it), the trie is traversed depth-first, following the links between nodes, which represent each character in the key.";

   ///INSERT in length of string (complexity)
   ///Search in length of string (complexity)
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
            str[i]=str[i]-'A'+'a';
        else if(!isalpha(str[i]))
            str[i]=' ';

    }
    istringstream os(str);
    string token;
    vector<string>word;
    while(os>>token)
    {
        word.push_back(token);
    }


    for(int i=0; i<word.size(); i++)
    {
        insert(root,word[i]);
    }
    trie * temp=root;
    words(temp,"");
    while(1)
    {
        string ss;
        cin>>ss;
        cout<<query(root,ss)<<endl;
    }
}
