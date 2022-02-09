/* find unique means => 2 3 2 3 1 => 1

 1) Aproch => cunt number of arrive =>Hash
 2) XOR ^
*/
#include<bits/stdc++.h>
using namespace std;

int findUnique(int arr[], int n)
{
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;

}

int main()
{
    int arr[7] = {2, 3, 1, 6, 3, 6, 2};
     // output => 1

    int Unique = findUnique(arr, 7);

    cout << Unique << endl;

    return 0;
}
