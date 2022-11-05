/*
    ***************** Basic Trie *********************

                                Root

                         |     |     |   |
                         A     C     D    T
                         |     |     |    |
                         B     A     U    I
                         |     |          |
                         S     T          M
                                          |
                                          E


            Insert or Add  ====> Car

                                Root

                         |     |     |     |
                         A     C     D     T
                         |     |     |     |
                         B     A     U     I
                         |     | \         |
                         S     T  R        M
                                           |
                                           E

                Insertion Algo:

                            char --\__  Search  ---> present ==> Then go forward
                                                \
                                                 \  not present ==> Create node with char



                        TrieNode{
                            char data;
                            TrieNode * children[26];
                            bool isTerminal;
                        }

                        we have to know ==> where the node is terminate ???


            Search Alog:
                    ABS ===> True

                    TIM ===> False

                    Last node is reach or not===> That is also terminal node or not


        TC ==> insert ==> O(L)
                Search ==> O(L)


        Remove Word Alog:

            Searching .. and word last ... check ... it is a terminal node ... then make it non - terminal just...



*/

#include<bits/stdc++.h>
using namespace std;


class TrieNode{
public:
    char data;
    TrieNode * children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }

};


class Trie{

    public:
    TrieNode * root;

    Trie(){
        root = new TrieNode('\0'); // root node start by null char
    }

    void insertUtil(TrieNode* root, string word)
    {
        // base case
        if(word.length() == 0)
        {
            // full word complete
            root->isTerminal = true;
            return ;
        }

        // word will be in CAPS

        int index = word[0] - 'A';
        TrieNode* child;

        // present
        if(root-> children[index] != NULL)
        {
            child = root->children[index];
        }
        else{
            // not present
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }





    // Search function
    bool searchUtil(TrieNode* root, string word)
    {
        // base case
        if(word.length() == 0)
        {
            return root->isTerminal; // if it is terminal node or not
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            // char present
            child = root->children[index];
        }
        else{
            // not present
            return false;
        }

        // Call recursion
        return searchUtil(child, word.substr(1));

    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }
};


int main()
{
    Trie *t = new Trie();

    t->insertWord("ABCD");
    t->insertWord("DBACG");
    cout << "present or Not => " << t->search("ABCD") << endl;

    return 0;
}
