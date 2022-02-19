/*
    move zero
     Input: 0 1 5 0 3 0 0
     output: 1 5 3 0 0 0 0

     Order must be same :

*/

#include<bits/stdc++.h>
using namespace std;


vector< int > moveZeroes(vector< int > v)
{
    int nonZero = 0;

    for(int j = 0; j < v.size(); j++)
    {
        if( v[j] != 0)
        {
            swap(v[j], v[nonZero]);
            nonZero++;
        }
    }

    return v;
}

void print(vector< int > v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
}


int main()
{
    vector< int > v = {0, 1, 5, 0, 3, 0 , 0};

    v = moveZeroes(v);

    print(v);


}
