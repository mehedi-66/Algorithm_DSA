
/*
    k times => Rotated array

    input: 1 2 3 4 5  k=2
    output: 4 5 1 2 3


    shift k time forward ...

    % => % n => [0 -- (n-1)] gives ...


    1) arr[(i + k ) % n] = arr[i];
     cyclic away te ... i th value replace ...

*/

#include<bits/stdc++.h>
using namespace std;

vector< int > rotated(vector< int > v, int k)
{
    vector< int > temp(v.size());

    for(int i = 0; i < v.size(); i++)
    {
        temp[(i+k)%v.size()] = v[i];
    }

    return temp;
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
    vector< int > v = {1, 2, 3, 4, 5};

    v = rotated(v, 2);

    print(v);

    return 0;
}

