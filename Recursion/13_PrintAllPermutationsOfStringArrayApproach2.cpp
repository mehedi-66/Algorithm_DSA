
/*
    ********* Print All permutation of String and Array Approach 2 ************
    Time complexity => O(n!)
    and Depth of recursion call is: O(n)

    Not using extra space

    without taking Extra space

    Different technique swapping to generating all Permutation

                        [1, 2, 3]
                         0  1  2

                        f([1, 2, 3])
        swap 1 -> 1    /  1->2|  1->3 \
                      /       |        \
            f([1,2,3])   f([2,1,3])    f([3,2,1])
     2->2 /  2->3 \
         /         \
    f([1,2,3])   f([1,3,2])
    3->3|           2->2 |
        |                |
    f([1,2,3])        f([1,3,2])

        return

*/
#include<bits/stdc++.h>
using namespace std;

int N = 3;
void recurPermute(int index, vector<int> &arr, vector< vector<int> > &ans)
{
    if(index == arr.size())
    {
        ans.push_back(arr);
        return ;
    }

    // loop run for swapping
    for(int i = index; i < arr.size(); i++)
    {
        // forward time swap
        swap(arr[index], arr[i]);

        recurPermute(index+1, arr, ans);

        // back time swap
        swap(arr[index], arr[i]);
    }
}


int main()
{
    vector<int> arr({1, 2, 3});

    vector< vector<int> > ans;

    recurPermute(0, arr, ans);


    // print
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
