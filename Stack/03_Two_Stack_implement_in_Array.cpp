/*
    ***************** Two Stack Implement in Array **************

    Approach 1:
        Given Single Array
        top1 => push left to right
        top2 => push right to left

        when top1 and top2 cross each other then it is Stack Overflow

    Approach 2:
        top1 => insert left to data n/2
        top2 => insert n/2 to left right

        Space not well manage

        first Approach Better in term of space management

*/
#include<bits/stdc++.h>
using namespace std;

class TwoStack{
    public:
        int* arr;
        int top1;
        int top2;
        int size;

        TowStack(int s)
        {
            this -> size = s;
            top1 = -1;
            top2 = s;
            arr = new int[s];
        }

        // push in stack 1
        void push1(int num)
        {
            // at least a empty space present
            if(top2 - top1 > 1)
            {
                top1++;
                arr[top1] = num;
            }
            else{
                cout << "Stack OverFlow" << endl;
            }
        }

        // push in stack 2
        void push2(int num)
        {
            if(top2 - top1 > 1 )
            {
                top2--;
                arr[top2] = num;
            }
            else{
                cout << "Stack OverFlow" << endl;
            }
        }

        // pop from stack 1 and return popped element
        int pop1()
        {
            if(top1 >= 0)
            {
                int ans = arr[top1];
                top1--;

                return ans;
            }
            else
            {
                return -1;
            }
        }

        //  pop from stack 2 and return popped element
        int pop2()
        {
            if(top2 < si ze)
            {
                int ans = arr[top2];
                top2++;
                return ans;
            }
            else
            {
                return -1;
            }
        }
};
int main()
{


    return 0;
}
