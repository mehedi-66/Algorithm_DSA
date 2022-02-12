/* given array has 1 to n-1 number find duplicate in
    arr[] = {1, 2, 3, 4, 3};

1) count => Hash
2) sum 1 to n-1 and subtract from sum

3) XOR ^ push => with 1 to n-1 ... last you got the third number arrive
      arr => 1 2 3 2
 we push => 1 2 3  => 2 arrive three times

*/


#include<bits/stdc++.h>
using namespace std;

int findDuplicate(int arr[], int n)
{
    int ans = 0;

    // whole arr element make XOR
    for(int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    // Our push 1 to n-1 XOR ... find 3 times arrive number
    for(int i = 1; i < n; i++)
    {
        ans = ans ^ i;
    }

    return ans;
}


int main()
{
    int arr[5] = {4, 2, 1, 3, 1};

    int duplicate = findDuplicate(arr, 5);

    cout << duplicate << endl;
    return 0;
}
