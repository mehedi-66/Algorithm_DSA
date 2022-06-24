/*
    *************** Implement Stack using Class ****************

    Stack => implement
            1) array
            2) Linked List
 */

 #include<bits/stdc++.h>
 using namespace std;

 class Stack{
    // data
    public:
        int* arr;
        int top;
        int size;

    // function
    Stack(int size)
    {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        //  has space or not
        if(size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack overflow" << endl;
        }
    }

    void pop()
    {
        // has element
        if(top >= 0)
        {
            top--;
        }
        else{
            cout << "Stack has no value" << endl;
        }
    }

    int peek()
    {
        // has element
        if(top >= 0 && top < size)
        {
            return arr[top];
        }
        else{
            cout << "Stack is Empty " << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        else{
            return false;
        }
    }



 };
 int main()
 {
    Stack st = Stack(5);

    st.push(22);

    cout << st.peek() << endl;

    st.push(30);

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.isEmpty() << endl;

     return 0;
 }
