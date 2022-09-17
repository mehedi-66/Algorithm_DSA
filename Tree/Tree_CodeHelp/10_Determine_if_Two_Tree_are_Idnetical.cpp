/*
    *********** Determine if Two Tree are identical or not

    Traverse both tree at a time


*/
#include<bits/stdc++.h>
using namespace std;

bool isIdenticall(Node* r1, Node* r2)
{
    if(r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if(r1 == NULL && r2 != NULL)
    {
        return false;
    }
    if(r1 != NULL && r2 == NULL)
    {
        return false;
    }

    bool left = isIdenticall(r1 -> left, r2 -> left);
    bool right = isIdenticall(r1 -> right, r2 -> right);

    bool Value = r1 -> data == r2->data;

    if(left && right && value)
    {
        return true;
    }
    else{
        return false;
    }



}
int main()
{


    return 0;
}
