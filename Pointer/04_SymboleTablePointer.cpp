/*
    ******** Symbole Table content *******

    symbole table content Can not Be change

    int arr[10];

    S.T create a mapping with the name and address

    arr ===> address (710)

    int *p = &arr[0];

    ST

    &p ===> address (1111) another location




*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10] = {1, 2, 3};

    // not changeable
//    arr = arr + 1; // show error

    int *p = &arr[0];

    p = p + 1; // it run but why

    cout << *p << endl; // output: 2

    // p store the array first location ==> go only second location

   // ***** Character Array and integer array

   int a[10] = {1, 2, 3, 4};
   char ch[10] = "abck";

   cout << a << endl; // output: 0x61fdc0
   cout << ch << endl; // output: abck

   /*
        int array show address and
        char array show value

        But why it actually implementation is different on case of Cout
   */
   char *c = &ch[0];

   cout << c << endl; // output: abck ==> coz implementation of cout is different


    return 0;
}
