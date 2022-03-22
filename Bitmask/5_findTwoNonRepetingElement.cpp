/*
    **************** Find Two non Repearting Element ***********


    Example: 1 1 2 3

        output: 2 3

    Approach:
        res = 1 ^ 1 ^ 2 ^ 3

      res => 2 ^ 3

      2 => 10
      3 => 11
        ________
           01    ==> 0 th bit setBit

            After contributing two element ^ only number is contribute 3 =>> 11

     *** Find element which 0 th Bit is set and store is vector do ^ operation to all ==>> 1 ^ 1 ^ 3
        we get 3
     ***
         a = 3
         res = 2 ^ 3 (note)
         b = res ^ a;
          b =  2 ^ 3 ^ 3
          b = 2;


*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        res ^= arr[i];
    }

    int tempRes = res, index = 0;
    // check the first bit wich is set(1)
    while(tempRes > 0)
    {
        if(tempRes & 1)
        {
            break;
        }
        index++;
        tempRes = tempRes >> 1;
    }

    int mask = (1 << index);
    vector<int> tempArr;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] & mask)
        {
            tempArr.push_back(arr[i]);
        }
    }
    int a = 0;
    for(vector<int>::iterator it = tempArr.begin(); it != tempArr.end(); it++)
    {
        a ^= (*it);
    }
    int b = res ^ a;
    if(a > b)
    {
        cout << b << " " << a << "\n";
    }
    else{
        cout << a << " " << b << "\n";
    }
    return 0;
}
