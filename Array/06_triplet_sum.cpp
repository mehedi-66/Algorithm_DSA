
#include<bits/stdc++.h>
using namespace std;

// not optimize solution .. bot force solution

void findTripletSum(int arr[], int n, int sum)
{
    for(int i = 0; i < n-2; i++)
    {
        for(int j = i+1; j < n-1; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                //cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                if((arr[i] + arr[j] + arr[k]) == sum)
                {
                    cout << sum << " " << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                }
            }
        }
    }
}




// *** O(N^2) ****
// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
bool find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;

    /* Sort the elements */
    sort(A, A + arr_size);

    /* Now fix the first element one by one and find the
       other two elements */
    for (int i = 0; i < arr_size - 2; i++) {

        // To find the other two elements, start two index
        // variables from two corners of the array and move
        // them toward each other
        l = i + 1; // index of the first element in the
        // remaining elements

        r = arr_size - 1; // index of the last element
        while (l < r) {
            if (A[i] + A[l] + A[r] == sum) {
                printf("Triplet is %d, %d, %d", A[i],
                       A[l], A[r]);
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }

    // If we reach here, then no triplet was found
    return false;
}






int main()
{
    int arr[5] = {1, 3, 2, 5, 4};

    sort(arr, arr + 5);

    // {1, 2, 3, 4, 5}

    findTripletSum(arr, 5, 12);
}
