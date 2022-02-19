/*
    Marge two sorted Array
    { 1 2, 4, 6, 9 }
    { 3, 5, 8}

    Marge : {1, 2, 3, 4, 5, 6, 8, 9}

    1) two pointer approach

*/

#include<bits/stdc++.h>
using namespace std;

vector< int >  MargeSortedArray(vector< int > v1, vector< int > v2)
{
    vector< int > v;

    int i = 0;
    int j = 0;

    while(i < v1.size() && j < v2.size())
    {
        if(v1[i] < v2[j])
        {
            v.push_back(v1[i]);
            i++;
        }
        else if(v2[j] < v1[i])
        {
            v.push_back(v2[j]);
            j++;
        }
        else if(v1[i] == v2[j])
        {
            v.push_back(v1[i]);
           // i++;
            j++;
        }
    }

    while(i < v1.size())
    {
        v.push_back(v1[i++]);
    }

    while(j < v2.size()){
        v.push_back(v2[j++]);
    }

    return v;
}


void print(vector< int > v)
{
    for(int i = 0; i< v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector< int > v1;
    vector< int > v2;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(9);

    v2.push_back(3);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(8);


    vector< int > v = MargeSortedArray(v1, v2);

    print(v);

    return 0;
}
