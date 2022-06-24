/*
    ***************** Introduction to Stack ******************
    LIFO => last In First out

    push => push element in the last
    pop => pop out element from last inserted value
    peek => show to last inserted element of the top
    empty => element exits or not

    STL => stack< int > s;
        s.push(2)
        s.pop()
        s.top()
        s.empty()
        s.size()


 */
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // creation of stack
    stack<int> s;

    s.push(3);
    s.push(5);

    cout << s.top() << endl;

    s.pop();

    cout << s.top() << endl;

    return 0;
}
