/*
    **************** Longest Common Prefix *******************
                str = {"coding", "codezen", "codingninza", "coders"};

            All string we have to check and .... find out longest common all of them

                ans = "cod"


    Approach:
        First string ... pick and compaier all of them
        ... like this way

        Algo:
            take firstString
            compeir all of them:
                char by char a... match all of them ... put into ans:

*/
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    char data;
    TrieNode * children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};
class Trie{
public:
    TrieNode * root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word)
    {
        // base case
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return ;
        }

        // assumption, word will be small
        int index = word[0] - 'a';
        TrieNode * child;

        // present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else{
            // not present
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursion call
        insertUtil(cild, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }



    // Find out longest common prefex
    void lcp(string str, string &ans)
    {
        for(int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if(root->childCount == 1)
            {
                ans.push_back(ch);
                // go forward
                int index = ch - 'a';

                root = root->children[index];
            }
            else{
                break;
            }

            if(root->isTerminal)
            {
                break;
            }
        }
    }
};
int main()
{


    // First Approach: O(N^2)
        // for traversing all characters of first String

        for(int i = 0; i < arr[0].length(); i++)
        {
            char ch = arr[0][i];

            bool match = true;

            // for comparing ch with all char ...... all string
            for(int j = 1; j < n; j++)
            {
                if(arr[j].size() < i || ch != arr[j][i]){
                    match = false;
                    break;
                }
            }

            if(match == false)
            {
                break;
            }
            else{
                ans.push(ch);
            }
        }




    // Approach 2 using Trie....   O(M*n) previous one not efficient

    // insert all the string into trie..

    // childCout == 1    if a node has only one child then add into ans ... other  return that is ans our longest child
f
    Trie *t = new Trie('\0');

    // insert all string into Trie

    for(int i = 0; i < n; i++)
    {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);

    return ans;





    return 0;
}
