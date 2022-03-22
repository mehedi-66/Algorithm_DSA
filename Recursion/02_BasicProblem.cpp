/*
    ******************** Solve some basic Problem ***********
    Time O(n) Space O(n)

    => print names 5 times
    => print linearly from 1 to N
    => print from N to 1
    => Print linearly from 1 to N ( by backTracking )
    => print from N to 1 ( by backTracking )


*/

#include<bits/stdc++.h>
using namespace std;

void printNames(int i, int n)
{
    if(i > n)
    {
        return ;
    }

    cout << "Mehedi Hasan" << endl;

    printNames(i+1, n);
}



void print_1_to_N(int i, int n)
{
    if(i > n)
    {
        return ;
    }

    cout << i << endl;

    print_1_to_N(i+1, n);
}

void print_N_to_1(int n)
{
    if(n < 1)
    {
        return ;
    }

    cout << n << endl;

    print_N_to_1(n-1);
}

void print_1_to_N_Backtracking(int i, int n)
{
    if(i < 1)
    {
        return ;
    }

    print_1_to_N_Backtracking(i-1, n);

    cout << i << endl;
}


void print_N_to_1_Backtracking(int i, int n)
{
    if(i > n)
    {
        return ;
    }

    print_N_to_1_Backtracking(i+1, n);

    cout << i << endl;
}


int main()
{
    int n;
    cin >> n;

     printNames(1, n);

     print_1_to_N(1, n);

     print_N_to_1(n);

     print_1_to_N_Backtracking(n, n);

     print_N_to_1_Backtracking(1, n);


    return 0;
}
