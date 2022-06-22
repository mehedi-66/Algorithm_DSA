/*
    *********** Merge Two sorted Linked List ***********
*/

#include<bits/stdc++.h>
using namespace std;

Node * solve(Node * first, Node * second)
{
    // first list have only one element then
    if(first -> next == NULL)
    {
        first -> next = seond;
        return first;
    }
    Node * curr1 = first;
    Node * next1 = curr1-> next;
    Node * curr2 = second;

    while(next1 != NULL && curr2 != NULL)
    {
        // first one data is smaller
        if( (curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data))
        {
               curr1 -> next = curr2;
               next2 = curr2 -> next;
               curr2 -> next = next1;

               // update pointer
               curr1 = curr2;
               curr2 = next2;
        }
        else{
            // curr1 and next1 .. move forward
            curr1 = next1;
            next1 = next1 -> next1;

            // first list is null
            if(next1 == NULL)
            {
                curr1 -> next = curr2;
                return first;
            }
        }
    }

    return first;

}
Node * SortTwoLists(Node * first, Node * second)
{
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;

    // we have to find out which one is the first element of this two linked list
     if(first->data <= second -> data)
     {
         solve(first, second);
     }
     else{
        solve(second, first);
     }
}
int main()
{

    return 0;
}
