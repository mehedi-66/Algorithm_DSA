/*
    ************* Recursion ****************
    when a function calls itself until a specific condition meet

    => Recursion
    => Base Case
    => Stack OverFlow / Stack space
    => Recursion tree


    f(){


        f();
    }
*/

#include<bits/stdc++.h>
using namespace std;
int cnt = 0;

void f()
{
    if(cnt == 4)
    {
        return;
    }

    cout << cnt << endl;
    cnt++;

     f();
}

int main()
{
    f();
}

// output:
    0
    1
    2
    3
